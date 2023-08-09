#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Bước 1: khai báo cấu trúc dữ liệu danh sách liên kết
struct Node
{
    char kytu;
    struct Node *pPre, *pNext;
};
typedef struct Node NODE;

struct List
{
    NODE *pHead, *pTail;
};
typedef struct List LIST;

// Bước 2: khởi tạo danh sách liên kết
void InIt(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

// Bước 3: khởi tạo Node
Node *GetNode(char kytu)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
    {
        printf("\nKhong cap phat thanh cong");
        return NULL;
    }
    p->kytu = kytu;
    p->pNext = NULL;
    p->pPre = NULL;
    return p;
}

// Bước 4: thêm đầu/thêm cuối vào danh sách liên kết
void push_front(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPre = p;
        l.pHead = p;
    }
}
void push_back(LIST &l, NODE *p)
{
    if (l.pTail == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pPre = l.pTail;
        l.pTail = p;
    }
}
NODE *pop_back(LIST &l)
{
    if (l.pHead != NULL)
    {
        NODE *p = l.pTail;
        l.pTail = p->pPre;
        l.pTail->pNext = NULL;
        return p;
    }
    return NULL;
}

// Bước 5: viết Input/Output
void NhapString(LIST &l, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        NODE *p;
        p = GetNode(str[i]);
        push_back(l, p);
        i++;
    }
}
void XuatString(LIST l)
{
    // duyet tung node trong list
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        // in ra cac node
        printf("%c ", p->kytu);
    }
}
void InPut(LIST &l)
{
    NODE *p;
    char str[30];
    // khởi tạo list
    InIt(l);
    // nhập data cho node
    fflush(stdin);
    printf("\nNhap string: ");
    gets(str);
    // đóng gói Node vào list
    NhapString(l, str);
}
void OutPut(LIST l)
{
    XuatString(l);
}
// Bước 6: những xử lý cần có trên danh sách liên kết
void HoanVi(char *a, char *b)
{
    char tam = *a;
    *a = *b;
    *b = tam;
}
LIST DaoLaiDanhSach(LIST l) // reverse theo stack
{
    LIST newlist;  // khai báo list
    InIt(newlist); // khởi tạo list
    for (NODE *p = l.pTail; p != NULL; p = p->pPre)
    {
        NODE *q = GetNode(p->kytu);
        push_back(newlist, q); // thêm sau vào list
    }
    return newlist;
}
bool KiemTraPalindrome(LIST l1, LIST l2)
{
    NODE *q = l2.pHead;
    for (NODE *p = l1.pHead; p != NULL; p = p->pNext)
    {
        if (p->kytu != q->kytu)
        {
            return false;
        }
        q = q->pNext;
    }
    return true;
}
// Bước 7: giải phong danh sách liên kết
void GiaiPhong(LIST &l)
{
    NODE *p = l.pHead;
    while (l.pHead != NULL)
    {
        l.pHead = l.pHead->pNext;
        free(p);
        p = l.pHead;
    }
}

int main()
{
    LIST l, l_reverse;
    InPut(l);
    OutPut(l);
    printf("\nDanh sach sau khi dao lai: \n");
    l_reverse = DaoLaiDanhSach(l);
    OutPut(l_reverse);
    if (KiemTraPalindrome(l, l_reverse))
    {
        printf("\nDanh sach sau khi dao lai giong ban dau");
    }
    else
    {
        printf("\nDanh sach sau khi dao lai khong giong ban dau");
    }

    GiaiPhong(l);
    GiaiPhong(l_reverse);

    return 0;
}
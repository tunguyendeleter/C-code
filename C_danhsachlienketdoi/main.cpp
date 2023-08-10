#include <stdio.h>
#include <conio.h>
// #include <stblib.h> // malloc/calloc/realloc/free

// Bước 1: khai báo cấu trúc dữ liệu danh sách liên kết
struct Node
{
    int data;
    struct Node *pNext, *pPre;
};
typedef struct Node NODE;

struct List
{
    NODE *pHead, *pTail;
};
typedef struct List LIST;

// Bước 2: khởi tạo danh sách liên kết
void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

// Bước 3: tạo Node trong danh sách liên kết
NODE *GetNode(int data)
{
    NODE *p = new NODE; // khởi tạo con trỏ p
    if (p == NULL)
    {
        printf("\nKhong du bo nho de cap phat con tro");
        getch();
        return NULL; // trả về rỗng
    }
    p->data = data;
    p->pNext = NULL;
    p->pPre = NULL;
    return p;
}

// Bước 4: thêm Node p vào đầu/thêm Node p vào cuối vào danh sách liên kết
// thêm đầu
void PushFront(LIST &l, Node *p)
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
void PushBack(LIST &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p; // pTail trỏ Next tới p
        p->pPre = l.pTail;
        l.pTail = p; // cập nhật pTail chính là p
    }
}

// Bước 5: viết Input/Output
void InPut(LIST &l)
{
    Init(l); // khổi tạo danh sách
    int n;
    do
    {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("\nSo luong phan tu khong hop le");
        }
    } while (n < 0);

    // vòng lập chạy n lần, mỗi lần nhập 1 Node
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("\nNhap Data: ");
        scanf("%d", &data);

        // đóng gói data vào Node
        NODE *p; // khai báo Node p
        p = GetNode(data);
        PushBack(l, p); // thêm node p vào sau danh sáchch
    }
}
void OutPut(LIST l)
{
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        printf("%4d", p->data);
    }
}

// Bước 7: giải phong danh sách liên kết
void GiaiPhong(LIST &l)
{
    Node *p;
    while (l.pHead != NULL)
    {
        p = l.pHead;              // cho con trỏ p trỏ vào pHead
        l.pHead = l.pHead->pNext; // pHead được trỏ sang Node bên cạnh
        delete p;                 // giải phỏng con trỏ p
    }
}

// Bước 6: những xử lý cần có trên danh sách liên kết
/*
tính tông danh sách
*/
int TinhTong(LIST l)
{
    int tong = 0;
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        tong += p->data;
    }
    return tong;
}

/*
thêm vào sau các số chẵn
*/
void ThemVaoSauSoChan(LIST &l, int data) // cap phat vung nho lien tuc => int data
{
    for (NODE *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        if (p->data % 2 == 0)
        {
            NODE *x = GetNode(data);
            NODE *g = p->pNext;
            x->pNext = g;
            g->pPre = x;
            p->pNext = x;
            x->pPre = p;
            p = p->pNext;
        }
    }
    // xử lý thêm sau pTail
    if (l.pTail->data % 2 == 0)
    {
        NODE *x = GetNode(data);
        PushBack(l, x);
    }
}
/*
thêm một node vào trước một node
*/
void ThemNodeVaoTruoc(LIST &l, NODE *x, int data)
{
    // xử lý đầu
    if (data == l.pHead->data)
    {
        PushFront(l, x);
        return;
    }
    NODE *g = l.pHead;
    for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if (p->data == data)
        {
            x->pNext = p;
            p->pPre = x;
            g->pNext = x;
            x->pPre = g;
            return;
        }
        g = p;
    }
}
/*
thêm một node vào sau một node
*/
void ThemNodeVaoSau(LIST &l, NODE *x, int data)
{
    for (NODE *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        if (p->data == data)
        {
            NODE *q = p->pNext;
            x->pNext = q;
            q->pPre = x;
            p->pNext = x;
            x->pPre = p;
            return;
        }
    }
    if (l.pTail->data == data)
    {
        PushBack(l, x);
    }
}
/*
lấy ra/xoá phần tử đầu
*/
NODE *PopFront(LIST &l)
{
    if (l.pHead == NULL)
    {
        return NULL;
    }
    if (l.pHead->pNext != NULL)
    {
        NODE *p = l.pHead->pNext;
        p->pPre = NULL;
        l.pHead->pNext = NULL;
        NODE *q = l.pHead;
        l.pHead = p;
        return q;
    }
    if (l.pHead->pNext == NULL)
    {
        NODE *p = l.pHead;
        l.pHead = l.pTail = NULL;
        return p;
    }
}
/*
lấy ra/xoá phần tử cuối
*/
NODE *PopBack(LIST &l)
{
    if (l.pTail == NULL)
    {
        return NULL;
    }
    if (l.pTail->pPre != NULL)
    {
        NODE *p = l.pTail->pPre;
        l.pTail->pPre = NULL;
        p->pNext = NULL;
        NODE *q = l.pTail;
        l.pTail = p;
        return q;
    }
    if (l.pTail->pPre == NULL)
    {
        NODE *p = l.pTail;
        l.pHead = l.pTail = NULL;
        return p;
    }
}

int main()
{
    NODE *x = GetNode(96);
    LIST l;
    InPut(l);
    // ThemVaoSauSoChan(l, 69);
    // ThemNodeVaoTruoc(l, x, 5);
    ThemNodeVaoSau(l, x, 5);
    OutPut(l);
    printf("\nTong cua danh sach = %d", TinhTong(l));
    NODE *q = PopFront(l);
    NODE *p = PopBack(l);
    printf("\nDanh sach sau khi lay ra phan tu dau va cuoi:\n");
    OutPut(l);
    printf("\nPhan tu dau tien trong list: %d", q->data);
    printf("\nPhan tu cuoi cung trong list: %d", p->data);
    GiaiPhong(l); // giai phong list
    delete x;     // giai phong x
    return 0;
}
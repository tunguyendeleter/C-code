#include <stdio.h>
#include <conio.h>

// Bước 1: khai báo cấu trúc dữ liệu stack
struct Node
{
    int data;
    struct Node *pNext;
};
typedef struct Node NODE;
struct Stack
{
    NODE *pTop;
};
typedef struct Stack STACK;

// Bước 2: khởi tạo stack
void InIt(STACK &s)
{
    s.pTop = NULL;
}
// Bước 3: tạo Node trong stack
NODE *GetNode(int data)
{
    NODE *node = new NODE;
    if (node == NULL)
    {
        printf("\nCap phat that bai");
        return NULL;
    }
    node->pNext = NULL;
    node->data = data;
    return node;
}
// Bước 4: thêm node vào stack
// kiểm ra rỗng
bool IsEmpty(STACK s)
{
    if (s.pTop == NULL)
    {
        return true;
    }
    return false;
}
// thêm đầu stack, thành công = true, thất bài = false
bool PushFront(STACK &s, NODE *p)
{
    if (p == NULL)
    {
        return false;
    }

    if (IsEmpty(s))
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
}
bool PushBack(STACK &s, NODE *p)
{
    if (p == NULL)
    {
        return false;
    }

    if (s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        // tìm phần tử cuối danh sách
        NODE *q;
        for (q = s.pTop; q != NULL; q = q->pNext)
        {
            if (q->pNext == NULL)
            {
                break;
            }
        }
        q->pNext = p;
    }
    return true;
}
// lấy node ra khỏi stack, pop thành công = true, thất bại = false
bool Pop(STACK &s, int &x)
{
    if (s.pTop != NULL)
    {
        NODE *p = s.pTop;
        s.pTop = s.pTop->pNext;
        x = p->data;
        delete p;
        return true;
    }
    return false;
}
// xem node đầu tiên trong stack
int Top(STACK s)
{
    if (s.pTop != NULL)
    {
        return s.pTop->data;
    }
}
// Bước 5: viết Input/Output
void InPut(STACK &s)
{
    int n;
    InIt(s);
    do
    {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("\nSo luong khong hop le");
        }
    } while (n < 0);
    // duyệt các phần tử
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("\nNhap s[%d]: ", i);
        scanf("%d", &data);
        NODE *p = GetNode(data);
        PushFront(s, p); // stack push front
    }
}
void OutPut(STACK &s)
{
    // vòng lặp liên tục đến khi stack rỗng
    printf("\nStack: \n");
    while (!IsEmpty(s))
    {
        int x;
        Pop(s, x);
        printf("%4d", x);
    }
}
// Bước 6: những xử lý cần có trên danh sách liên kết
/*
Đổi hệ
*/
void Doihe(STACK &s, int socandoi, int hecandoi)
{
    // khởi tạo stack
    InIt(s);
    // chia lấy dư
    while (socandoi != 0)
    {
        int du;
        du = socandoi % hecandoi;
        socandoi /= hecandoi;
        // nhập stack
        NODE *p = GetNode(du);
        PushFront(s, p);
    }
    while (!IsEmpty(s))
    {
        int x;
        Pop(s, x);
        // quy ước hệ thập lục
        if (x >= 10)
        {
            x += 7;     // chuyển 10-15 sang A-F
        }
        printf("%4c", x + 48);
    }
}

// Bước 7: giải phong danh sách liên kết
void GiaiPhong(STACK &s)
{
    NODE *p;
    while (s.pTop != NULL)
    {
        p = s.pTop;
        s.pTop = p->pNext;
        delete p;
    }
}

int main()
{
    STACK s;
    // InPut(s);
    // OutPut(s);
    Doihe(s, 250, 16);
    GiaiPhong(s);
    return 0;
}
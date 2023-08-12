#include <stdio.h>
#include <conio.h>

// Bước 1: khai báo cấu trúc dữ liệu stack
struct Sach
{
    char TenSach[30];
    char NhaXuatBan[30];
    int GiaBan;
};
typedef struct Sach SACH;
struct Node
{
    SACH data;
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
NODE *GetNode(SACH data)
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
bool Pop(STACK &s, SACH &x)
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
SACH Top(STACK s)
{
    if (s.pTop != NULL)
    {
        return s.pTop->data;
    }
}
// Bước 5: viết Input/Output
void NhapThongTinSach(SACH &sach)
{
    fflush(stdin);
    printf("\nNhap ten sach: ");
    gets(sach.TenSach);
    printf("\nNhap nha xuat ban: ");
    gets(sach.NhaXuatBan);
    printf("\nNhap gia ban: ");
    scanf("%d", &sach.GiaBan);
}
void XuatThongTinSach(SACH sach)
{
    printf("\nNhap ten sach: %s", sach.TenSach);
    printf("\nNhap nha xuat ban: %s", sach.NhaXuatBan);
    printf("\nNhap gia ban: %d", sach.GiaBan);
}
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
        SACH data;
        printf("\n----------Nhap sach thu %d---------", i + 1);
        NhapThongTinSach(data);
        NODE *p = GetNode(data);
        PushFront(s, p); // stack push front
    }
}
void OutPut(STACK &s)
{
    // vòng lặp liên tục đến khi stack rỗng
    printf("\nStack: \n");
    int dem = 1;
    while (!IsEmpty(s))
    {
        printf("\n----------Xuat sach thu %d---------", dem++);
        SACH x;
        Pop(s, x);
        XuatThongTinSach(x);
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
    InPut(s);
    OutPut(s);
    GiaiPhong(s);
    return 0;
}
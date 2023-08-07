/*
7 bước căn bản luôn phải có không danh sách liên kết đơn

Bước 1: khai báo cấu trúc dữ liệu danh sách liên kết
Bước 2: khởi tạo danh sách liên kết
Bước 3: tạo Node trong danh sách liên kết
Bước 4: thêm đầu/thêm cuối vào danh sách liên kết
Bước 5: viết Input/Output
Bước 6: những xử lý cần có trên danh sách liên kết
Bước 7: giải phong danh sách liên kết
*/

#include <stdio.h>
#include <conio.h>

// Bước 1: khai báo cấu trúc dữ liệu danh sách liên kết
struct Node
{
    int data;
    struct Node *pNext;
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
    return p;
}

// Bước 4: thêm Node p vào đầu/thêm Node p vào cuối vào danh sách liên kết
// thêm đầu
void AddHead(LIST &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddTail(LIST &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p; // pTail trỏ Next tới p
        l.pTail = p;        // cập nhật pTail chính là p
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
        AddHead(l, p); // thêm node p vào đầu danh sáchch1f
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
Tinh tong danh sach
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
Liet ke cac so chan trong danh sach
*/
void LietKeSoChan(LIST l)
{
    printf("\nCac so chan trong danh sach: ");
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data % 2 == 0)
        {
            printf("%4d", p->data);
        }
    }
}
/*
Sap xep danh sach
*/
void HoanVi(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
void SapXepTang(LIST &l, char phanloai)
{
    for (NODE *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        for (NODE *q = p->pNext; q != NULL; q = q->pNext)
        {
            if (phanloai == 't')
            {

                if (p->data > q->data)
                {
                    HoanVi(p->data, q->data);
                }
            }
            else if (phanloai == 'g')
            {

                if (p->data < q->data)
                {
                    HoanVi(p->data, q->data);
                }
            }
        }
    }
}
/*
them node vao danh sach
*/
// them x vao sau q
void ThemDangSau(LIST &l, NODE *x, NODE *q)
{
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data == q->data)
        {
            x->pNext = p->pNext;
            p->pNext = x;
            return;
        }
    }
}

void ThemDangSauTatCaSoChan(LIST &l, int data)
{
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data % 2 == 0)
        {
            NODE *x = GetNode(data); // tạo ra node mới cho mỗi vòng lặp
            x->pNext = p->pNext;
            p->pNext = x;
            p = p->pNext;
        }
    }
}
/*
them node vao danh sach
*/
void ThemVaoTruocMotNode(LIST &l, NODE *x, NODE *p)
{
    if (p->data == l.pHead->data)
    {
        AddHead(l, x);
        return;
    }
    NODE *q;
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        if (k->data == p->data)
        {
            x->pNext = k;
            q->pNext = x;
            return;
        }
        q = k;
    }
}
void ThemVaoTruocSoChan(LIST &l, int data)
{
    // xét phần tử thứ 2 trước đê tránh việc vừa duyệt qua 2 lần phần tử đầu tiên
    NODE *q = l.pHead;
    for (NODE *k = l.pHead->pNext; k != NULL; k = k->pNext)
    {
        if (k->data % 2 == 0)
        {
            NODE *x = GetNode(data);
            x->pNext = k;
            q->pNext = x;
        }
        q = k;
    }
    // xét phần tử đầu tiên sau cùng
    if (l.pHead->data % 2 == 0)
    {
        NODE *x = GetNode(data);
        AddHead(l, x);
    }
}
// xoá đầu
void XoaDau(LIST &l)
{
    if (l.pHead != NULL)
    {
        NODE *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}
// xoá cuối
void XoaCuoi(LIST &l)
{
    NODE *truoc;
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p == l.pTail)
        {
            truoc->pNext = NULL;
            delete p;
            l.pTail = truoc;
            return;
        }
        truoc = p;
    }
}
// xoá vào sau phần tử
void XoaDangSauMotNode(LIST &l, NODE *q)
{
    for (NODE *p = l.pHead; p != l.pTail; p = p->pNext)
    {
        if (p->data == q->data)
        {
            NODE *x = p->pNext;
            p->pNext = x->pNext;
            delete x;
            return;
        }
    }
}
void XoaHetTatCaSoChan(LIST &l)
{
    NODE *truoc = l.pHead;
    for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if (p->data % 2 == 0)
        {
            NODE *sau = p->pNext;
            truoc->pNext = sau;
            delete p;
            p = truoc;
        }
        truoc = p;
    }
    if (l.pHead->data % 2 == 0)
    {
        XoaDau(l);
    }
}

/*
Sửa lại các số chẵn thành 69
*/
void SuaCacSoChan(LIST &l, int sothaythe)
{
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->data % 2 == 0)
        {
            p->data = sothaythe;
        }
    }
}

int main()
{
    LIST l;
    InPut(l);
    OutPut(l);
    printf("\nTong = %d", TinhTong(l));
    LietKeSoChan(l);
    SapXepTang(l, 't');
    printf("\nDanh sach sau khi sap xep: ");
    OutPut(l);
    // SapXepTang(l, 'g');
    // printf("\nDanh sach sau khi sap xep: ");
    // OutPut(l);
    printf("\nDanh sach sau khi xoa: ");
    NODE *x, *q;
    q = GetNode(1);
    // x = GetNode(69);
    // ThemDangSau(l, x, q);
    // ThemVaoTruocSoChan(l, 69);
    SuaCacSoChan(l, 69);
    OutPut(l);
    GiaiPhong(l);
    return 0;
}
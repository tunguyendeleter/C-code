/*
Học sinh có thông tin sau:
Mã số (10 ký tự)
Họ tên (30 ký tự)
Lớp
điểm thi
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

// Bước 1: khai báo cấu trúc dữ liệu danh sách liên kết
struct HocSinh
{
    char MaSo[10];
    char HoTen[30];
    char Lop[10];
    float DiemThi;
};
typedef struct HocSinh HOCSINH;

struct Node
{
    HOCSINH hocsinh;
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
NODE *GetNode(HOCSINH data)
{
    NODE *p = new NODE; // khởi tạo con trỏ p
    if (p == NULL)
    {
        printf("\nKhong du bo nho de cap phat con tro");
        getch();
        return NULL; // trả về rỗng
    }
    p->hocsinh.DiemThi = data.DiemThi;
    strcpy(p->hocsinh.HoTen, data.HoTen);
    strcpy(p->hocsinh.MaSo, data.MaSo);
    strcpy(p->hocsinh.Lop, data.Lop);
    p->pNext = NULL;
    return p;
}

// Bước 4: thêm Node p vào đầu/thêm Node p vào cuối vào danh sách liên kết
// thêm đầu
void AddHead(LIST &l, Node *p)
{
    if (l.pHead == NULL) // nếu head rỗng cho head = tail
    {
        l.pHead = l.pTail = p;
    }
    else // nếu tồn tại head thì cập nhật lại head
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
void NhapHocSinh(HOCSINH &hs)
{
    fflush(stdin);
    printf("\nNhap ma so: ");
    gets(hs.MaSo);
    printf("\nNhap ho ten: ");
    gets(hs.HoTen);
    printf("\nNhap lop: ");
    gets(hs.Lop);
    printf("\nNhap diem thi: ");
    scanf("%f", &hs.DiemThi);
}
void XuatHocSinh(HOCSINH hs)
{
    printf("\nHo ten: %s", hs.HoTen);
    printf("\nMa so: %s", hs.MaSo);
    printf("\nLop: %s", hs.Lop);
    printf("\nDiem thi: %f", hs.DiemThi);
}
void NhapDanhSach(LIST &l)
{
    Init(l); // khổi tạo danh sách = NULL
    int n;
    do
    {
        printf("\nNhap so luong hoc sinh: ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("\nSo luong khong hop le");
        }
    } while (n < 0);

    // vòng lập chạy n lần, mỗi lần nhập 1 Node
    for (int i = 0; i < n; i++)
    {
        HOCSINH data;
        NhapHocSinh(data);
        // đóng gói data vào Node
        NODE *p; // khai báo Node p
        p = GetNode(data);
        AddHead(l, p); // thêm node p vào đầu danh sáchch1f
    }
}
void XuatDanhSach(LIST l)
{
    int dem = 1;
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        printf("\n--------thong tin hoc sinh thu %d----------", dem++);
        XuatHocSinh(p->hocsinh);
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
void SapXepTheoDiem();
void SapXepTheoTen();
void XepLoaiHocSinh();

void ThemDanhSach();
void XoaDanhSach();


int main()
{
    LIST l;
    NhapDanhSach(l);
    XuatDanhSach(l);
    GiaiPhong(l);
    return 0;
}
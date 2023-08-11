#include <iostream>
#include <stack>
using namespace std;

// Bước 1: khai báo cấu trúc dữ liệu stack
struct Sach
{
    char TenSach[30];
    char NhaXuatBan[30];
    int GiaBan;
};
typedef struct Sach SACH;

// Bước 2: viết Input/Output
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
void InPut(stack<SACH> &s)
{
    int n;
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
        s.push(data);
    }
}
void OutPut(stack<SACH> &s)
{
    // vòng lặp liên tục đến khi stack rỗng
    printf("\nStack: \n");
    int dem = 1;
    while (!s.empty())
    {
        printf("\n----------Xuat sach thu %d---------", dem++);
        SACH x = s.top();
        s.pop();
        XuatThongTinSach(x);
    }
}

string DaoNguocChuoi(string str)
{
    int len = str.size();
    string res = "";
    stack<char> s;
    for (int i = 0; i < len; i++)
    {
        s.push(str[i]);
    }
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }
    return res;
}

int main()
{
    stack<SACH> s;
    InPut(s);
    OutPut(s);

    // string str = DaoNguocChuoi("ngoc tu");
    // cout << str;
    return 0;
}
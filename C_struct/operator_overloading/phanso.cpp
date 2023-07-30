// printf scanf 
#include <stdio.h>
#include <conio.h>
// cin cout 
#include <iostream>
using namespace std;

/*
PHANSO ps1, ps2, ps3, ps4
muon tinh tong ca 4 cai thi sao ?

=> GIAI PHAP

CACH 1:
Tong = TinhTong(ps1, ps2);

Tong = TinhTong(ps3, Tong);

Tong = TinhTong(ps4, Tong);

CACH 2:
Tong = TinhTong(TinhTong(TinhTong(ps1, ps2), ps3), ps4);

CACH 3:
Tong = ps1 + ps2 + ps3 + ps4;
*/

struct PhanSo
{
    int TuSo, MauSo;
};
typedef struct PhanSo PHANSO;

void NhapPhanSo(PHANSO *ps)
{
    printf("\nNhap vao tu so: ");
    scanf("%d", &ps->TuSo);
    do
    {
        printf("\nNhap vao mau so: ");
        scanf("%d", &ps->MauSo);
        if (ps->MauSo == 0)
        {
            printf("\nMau so phai khac khong");
        }
    } while (ps->MauSo == 0);
}

PHANSO TinhTong(PHANSO ps1, PHANSO ps2)
{
    PHANSO ps;
    ps.TuSo = (ps1.TuSo * ps2.MauSo) + (ps1.MauSo * ps2.TuSo);
    ps.MauSo = ps1.MauSo * ps2.MauSo;
    return ps;
}

// operator nhap
istream &operator>>(istream &is, PHANSO &ps) // is, ps la cac bien tu dat
{
    cout << "\nNhap vao tu so: ";
    is >> ps.TuSo;
    do
    {
        cout << "\nNhap vao mau so: ";
        is >> ps.MauSo;
        if (ps.MauSo == 0)
        {
            cout << "\nMau so phai khac khong";
        }
    } while (ps.MauSo == 0);
    return is;
}

// operator xuat
ostream &operator<<(ostream &os, PHANSO ps) // os, ps la cac bien tu dat
{
    os << ps.TuSo << "/" << ps.MauSo;
    return os;
}

// PS1 + PS2
PHANSO operator+(PHANSO ps1, PHANSO ps2)
{
    PHANSO ps;
    ps.TuSo = (ps1.TuSo * ps2.MauSo) + (ps1.MauSo * ps2.TuSo);
    ps.MauSo = ps1.MauSo * ps2.MauSo;
    return ps;
}

// PS1 + so nguyen
PHANSO operator+(PHANSO ps1, int songuyen)
{
    PHANSO ps;
    ps.TuSo = (ps1.TuSo * 1) + (ps1.MauSo * songuyen);
    ps.MauSo = ps1.MauSo * 1;
    return ps;
}

// so nguyen + PS1
PHANSO operator+(int songuyen, PHANSO ps1)
{
    PHANSO ps;
    ps.TuSo = (ps1.TuSo * 1) + (ps1.MauSo * songuyen);
    ps.MauSo = ps1.MauSo * 1;
    return ps;
}

// PS1 - PS2
PHANSO operator-(PHANSO ps1, PHANSO ps2)
{
    PHANSO ps;
    ps.TuSo = (ps1.TuSo * ps2.MauSo) - (ps1.MauSo * ps2.TuSo);
    ps.MauSo = ps1.MauSo * ps2.MauSo;
    return ps;
}

// PS1 * PS2
PHANSO operator*(PHANSO ps1, PHANSO ps2)
{
    PHANSO ps;
    ps.TuSo = ps1.TuSo * ps2.TuSo;
    ps.MauSo = ps1.MauSo * ps2.MauSo;
    return ps;
}

// PS1 / PS2
PHANSO operator/(PHANSO ps1, PHANSO ps2)
{
    PHANSO ps;
    ps.TuSo = ps1.TuSo * ps2.MauSo;
    ps.MauSo = ps1.MauSo * ps2.TuSo;
    return ps;
}

int TimUCLN(int a, int b)
{
    // loai bo dau am
    if (a < 0)
    {
        a *= -1;
    }
    if (b < 0)
    {
        b *= -1;
    }
    // neu a % b = 0 return b
    int min = a < b ? a : b;
    int max = a < b ? b : a;
    if (max % min == 0)
    {
        return min;
    }
    // neu a % b != 0
    for (int i = min / 2; i > 1; i--)
    {
        if (min % i == 0 && max % i == 0)
        {
            return i;
        }
    }
    return 1;
}

void RutGonPhanSo(PHANSO *ps)
{
    int UCLN = TimUCLN(ps->TuSo, ps->MauSo);
    ps->TuSo /= UCLN;
    ps->MauSo /= UCLN;
}

void XuatPhanSo(PHANSO *ps)
{
    if (ps->MauSo < 0)
    {
        ps->MauSo *= -1;
        ps->TuSo *= -1;
    }
    printf("%d/%d", ps->TuSo, ps->MauSo);
}

int main()
{
    PHANSO ps1, ps2;

    cin >> ps1;
    cout << ps1;

    cin >> ps2;
    cout << ps2;

    PHANSO Tong = 5 + ps1;
    RutGonPhanSo(&Tong);
    printf("\nKet qua tong: ");
    XuatPhanSo(&Tong);

    PHANSO Hieu = ps1 - ps2;
    RutGonPhanSo(&Hieu);
    printf("\nKet qua hieu: ");
    XuatPhanSo(&Hieu);

    PHANSO Nhan = ps1 * ps2;
    RutGonPhanSo(&Nhan);
    printf("\nKet qua nhan: ");
    XuatPhanSo(&Nhan);

    PHANSO Chia = ps1 / ps2;
    RutGonPhanSo(&Chia);
    printf("\nKet qua chia: ");
    XuatPhanSo(&Chia);

    return 0;
}
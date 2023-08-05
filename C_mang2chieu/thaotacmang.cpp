#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 100

void NhapMang(int a[][MAX], int sodong, int socot)
{
    for (int i = 0; i < sodong; i++)
    {
        for (int j = 0; j < socot; j++)
        {
            printf("\nNhap a[%d][%d]:", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void XuatMang(int a[][MAX], int sodong, int socot)
{
    for (int i = 0; i < sodong; i++)
    {
        for (int j = 0; j < socot; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
}

int TinhTongMang(int a[][MAX], int sodong, int socot)
{
    int tong = 0;
    for (int i = 0; i < sodong; i++)
    {
        for (int j = 0; j < socot; j++)
        {
            tong += a[i][j];
        }
    }
    return tong;
}

int DemSoLuongChan(int a[][MAX], int sodong, int socot)
{
    int dem = 0;
    for (int i = 0; i < sodong; i++)
    {
        for (int j = 0; j < socot; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                dem++;
            }
        }
    }
    return dem;
}

/*
liet ke cac so chinh phuong trong mang
*/
bool KiemTraSoChinhPhuong(int so)
{
    if (so == 0)
    {
        return false;
    }
    return (sqrt(so) * sqrt(so) == so);
}

void LietKeSoChinhPhuong(int a[][MAX], int sodong, int socot)
{
    for (int i = 0; i < sodong; i++)
    {
        for (int j = 0; j < socot; j++)
        {
            if (KiemTraSoChinhPhuong(a[i][j]))
            {
                printf("\na[%d][%d]= %d", i, j, a[i][j]);
            }
        }
    }
}

/*
Tim kiem phan tu
*/
int TimKiemPhanTu(int a[][MAX], int sodong, int socot, int phantu)
{
    for (int i = 0; i < sodong; i++)
    {
        for (int j = 0; j < socot; j++)
        {
            if (phantu == a[i][j])
            {
                return i;
            }
        }
    }
    return -1;
}

/*
Tim min max
*/
int TimMinMax(int a[][MAX], int sodong, int socot, int phanloai) // phanloai = 1 => max phanloai = 2 => min
{
    int minmax = a[0][0];
    for (int i = 0; i < sodong; i++)
    {
        for (int j = 0; j < socot; j++)
        {
            if (phanloai == 1) // max
            {
                if (minmax < a[i][j])
                {
                    minmax = a[i][j];
                }
            }
            else if (phanloai == 2) // min
            {
                if (minmax > a[i][j])
                {
                    minmax = a[i][j];
                }
            }
        }
    }
    return minmax;
}

/*
Liet ke cac phan tu phan biet
*/
void LietKePhanBiet(int a[][MAX], int sodong, int socot)
{
    for (int i = 0; i < sodong * socot; i++)
    {
        bool check = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j / socot][j % socot] == a[i / socot][i % socot])
            {
                check = true;
            }
        }
        if (check == false)
        {
            printf(" %d", a[i / socot][i % socot]);
        }
    }
}
/*
Sap xep tang dan tu trai qua phai, tu tren xuong duoi
*/
void HoanVi(int &a, int &b)
{
    int tam = a;
    a = b;
    b = tam;
}

void SapXepMang(int a[][MAX], int sodong, int socot, char phanloai)
{
    for (int i = 0; i < socot * sodong - 1; i++)
    {
        for (int j = i + 1; j < socot * sodong; j++)
        {
            if (phanloai == 't')
            {

                if (a[i / socot][i % socot] > a[j / socot][j % socot])
                {
                    HoanVi(a[i / socot][i % socot], a[j / socot][j % socot]);
                }
            }
            else if (phanloai == 'g')
            {
                if (a[i / socot][i % socot] < a[j / socot][j % socot])
                {
                    HoanVi(a[i / socot][i % socot], a[j / socot][j % socot]);
                }
            }
        }
    }
}

int main()
{
    int a[MAX][MAX];
    int sodong, socot;
    do
    {
        printf("\nNhap so dong: ");
        scanf("%d", &sodong);
        if (sodong < 0 || sodong > MAX)
        {
            printf("\nSo dong khong hop le");
        }
    } while (sodong < 0 || sodong > MAX);
    do
    {
        printf("\nNhap so cot: ");
        scanf("%d", &socot);
        if (socot < 0 || socot > MAX)
        {
            printf("\nSo cot khong hop le");
        }
    } while (socot < 0 || socot > MAX);

    NhapMang(a, sodong, socot);
    XuatMang(a, sodong, socot);
    printf("\nTong mang: %d", TinhTongMang(a, sodong, socot));
    printf("\nSo luong phan tu chan: %d", DemSoLuongChan(a, sodong, socot));
    printf("\nLiet ke cac so chinh phuong");
    LietKeSoChinhPhuong(a, sodong, socot);
    if (TimKiemPhanTu(a, sodong, socot, 5) < 0)
    {
        printf("\nKhong tim thay");
    }
    else
    {
        printf("\nCo tim thay");
    }
    printf("\nMax: %d", TimMinMax(a, sodong, socot, 1));
    printf("\nLiet ke phan tu phan biet: ");
    LietKePhanBiet(a, sodong, socot);
    printf("\nSap tang dan\n");
    SapXepMang(a, sodong, socot, 't');
    XuatMang(a, sodong, socot);
    printf("\nSap giam dan\n");
    SapXepMang(a, sodong, socot, 'g');
    XuatMang(a, sodong, socot);

    return 0;
}
#include <stdio.h>
#include <conio.h>
#define MAX 100

void NhapMaTran(int a[][MAX], int n)
{
    for (int i = 0; i < n * n; i++)
    {
        printf("\nNhap a[%d][%d]:", i / n, i % n);
        scanf("%d", &a[i / n][i % n]);
    }
}

void XuatMaTran(int a[][MAX], int n)
{
    for (int i = 0; i < n * n; i++)
    {
        printf("%4d", a[i / n][i % n]);
        if ((i + 1) % n == 0) // n là so cot
        {
            printf("\n");
        }
    }
}
/*
viet ham tra ve tong cac phan tu tren 1 dong
*/
int TongCuaDong(int a[][MAX], int n, int vitri)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += a[vitri][i];
    }
    return tong;
}
int TichCuaCot(int a[][MAX], int n, int vitri)
{
    int tich = 1;
    for (int i = 0; i < n; i++)
    {
        tich *= a[i][vitri];
    }
    return tich;
}

void TinhTongVaTich(int a[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\ndong %d: Co tong=%d", i, TongCuaDong(a, n, i));
    }
    for (int i = 0; i < n; i++)
    {
        printf("\ncot %d: Co tich=%d", i, TichCuaCot(a, n, i));
    }
}
/*
Tinh tong tren duong cheo
*/
void TongCuaDuongCheoChinh(int a[][MAX], int n)
{
    int tong = 0;
    printf("\nCac phan tu tren duong cheo chinh la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%4d", a[i][i]);
        tong += a[i][i];
    }
    printf("\nTong duong cheo chinh la: %d", tong);
}

void TongCuaDuongCheoPhu(int a[][MAX], int n)
{
    int tong = 0;
    printf("\nCac phan tu tren duong cheo phu la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%4d", a[i][n - i - 1]);
        tong += a[i][n - i - 1];
    }
    printf("\nTong duong cheo phu la: %d", tong);
}
/*
Tim min max tren duong cheo phu
*/
int TimMinMaxTrenDuongCheoPhu(int a[][MAX], int n, int phanloai)
{
    int minmax = a[0][n - 1];
    for (int i = 0; i < n; i++)
    {
        if (phanloai == 1) // max
        {
            if (minmax < a[i][n - 1 - i])
            {
                minmax = a[i][n - 1 - i];
            }
        }
        else if (phanloai == 2)
        {
            if (minmax > a[i][n - 1 - i])
            {
                minmax = a[i][n - 1 - i];
            }
        }
    }
    return minmax;
}
/*
Liet ke va dem so chan trong vung tam giac tren duong cheo chinh, khong tinh duong cheo
*/
void LietKeDemSoChanTrongTamGiacTrenDuongCheoChinh(int a[][MAX], int n)
{
    printf("\nCac phan tu trong tam giac tren duong cheo chinh: ");
    int dem = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf("%4d", a[i][j]);
            if (a[i][j] % 2 == 0)
            {
                dem++;
            }
        }
    }
    printf("\nSo luong phan tu trong tam giac la: %d", dem);
}
/*
Liet ke va dem so chan trong vung tam giac duoi duong cheo chinh, khong tinh duong cheo
*/
void LietKeDemSoChanTrongTamGiacDuoiDuongCheoChinh(int a[][MAX], int n)
{
    printf("\nCac phan tu trong tam giac duoi duong cheo chinh: ");
    int dem = 0;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         printf("%4d", a[j][i]);
    //         if (a[j][i] % 2 == 0)
    //         {
    //             dem++;
    //         }
    //     }
    // }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%4d", a[i][j]);
            if (a[i][j] % 2 == 0)
            {
                dem++;
            }
        }
    }
    printf("\nSo luong phan tu trong tam giac la: %d", dem);
}
/*
Liet ke va Tim phan tu trong vung tam giac tren duong cheo phu, khong tinh duong cheo
*/
void LietKeTimPhanTuTrongTamGiacTrenDuongCheoPhu(int a[][MAX], int n, int phantu)
{
    printf("\nCac phan tu trong tam giac tren duong cheo phu: ");
    int check = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf("%4d", a[i][j]);
            if (phantu == a[i][j])
            {
                check = 1;
            }
        }
    }
    if (check == 1)
    {
        printf("\nTim thay phan tu");
    }
    else
    {
        printf("\nKhong tim thay phan tu");
    }
}
/*
Liet ke va Tim phan tu trong vung tam giac duoi duong cheo phu, khong tinh duong cheo
*/
void LietKeTimPhanTuTrongTamGiacDuoiDuongCheoPhu(int a[][MAX], int n, int phantu)
{
    printf("\nCac phan tu trong tam giac duoi duong cheo phu: ");
    int check = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%4d", a[i][j]);
            if (phantu == a[i][j])
            {
                check = 1;
            }
        }
    }
    if (check == 1)
    {
        printf("\nTim thay phan tu");
    }
    else
    {
        printf("\nKhong tim thay phan tu");
    }
}

int main()
{
    int a[MAX][MAX];
    int n;
    do
    {
        printf("\nNhap n: ");
        scanf("%d", &n);
        if (n < 0 || n > MAX)
        {
            printf("\nn khong hop le");
        }
    } while (n < 0 || n > MAX);
    NhapMaTran(a, n);
    XuatMaTran(a, n);
    TinhTongVaTich(a, n);
    TongCuaDuongCheoChinh(a, n);
    TongCuaDuongCheoPhu(a, n);
    printf("\nMax cua duong cheo phu: %d", TimMinMaxTrenDuongCheoPhu(a, n, 1));
    printf("\nMin cua duong cheo phu: %d", TimMinMaxTrenDuongCheoPhu(a, n, 2));
    LietKeDemSoChanTrongTamGiacTrenDuongCheoChinh(a, n);
    LietKeDemSoChanTrongTamGiacDuoiDuongCheoChinh(a, n);
    LietKeTimPhanTuTrongTamGiacTrenDuongCheoPhu(a, n, 3);
    LietKeTimPhanTuTrongTamGiacDuoiDuongCheoPhu(a, n, 4);
    return 0;
}
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int **a, int sodong, int socot)
{
    int len = sodong * socot;
    printf("len = %d", len);
    for (int i = 0; i < len; i++)
    {
        printf("\nNhap a[%d][%d]: ", i / socot, i % socot);
        scanf("%d", &a[i / socot][i % socot]);
    }
}

void XuatMang(int **a, int sodong, int socot)
{
    printf("\nXuat mang:\n");
    for (int i = 0; i < sodong; i++)
    {
        for (int j = 0; j < socot; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

int TinhTongSoDuong(int **a, int sodong, int socot)
{
    int tong = 0;
    for (int i = 0; i < sodong * socot; i++)
    {
        if (a[i / socot][i % sodong] > 0)
        {
            tong += a[i / socot][i % sodong];
        }
    }
    return tong;
}

void GiaiPhong(int **a, int sodong)
{
    for (int i = 0; i < sodong; i++)
    {
        free(a[i]);
    }
    free(a);
}

int main()
{
    int **a;
    int sodong, socot;

    do
    {
        printf("\nNhap so dong: ");
        scanf("%d", &(sodong));
        if (sodong < 0)
        {
            printf("\nSo dong khong hop le");
        }
    } while (sodong < 0);
    do
    {
        printf("\nNhap so cot: ");
        scanf("%d", &(socot));
        if (socot < 0)
        {
            printf("\nSo cot khong hop le");
        }
    } while (socot < 0);
    a = (int **)malloc((sodong) * sizeof(int));
    for (int i = 0; i < (sodong); i++)
    {
        a[i] = (int *)malloc((socot) * sizeof(int));
    }

    NhapMang(a, sodong, socot);
    XuatMang(a, sodong, socot);
    printf("\nTong cac so duong = %d", TinhTongSoDuong(a, sodong, socot));
    GiaiPhong(a, sodong);
    return 0;
}
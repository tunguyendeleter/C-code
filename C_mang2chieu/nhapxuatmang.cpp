#include <stdio.h>
#include <conio.h>
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
    return 0;
}
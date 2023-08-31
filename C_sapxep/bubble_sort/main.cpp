#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int **a, int n)
{
    *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", &(*a)[i]);
    }
}
void XuatMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}

void HoanVi(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_sort(int *a, int n)
{
    bool checkTangDan = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                HoanVi(&a[j], &a[j + 1]);
                checkTangDan = false;
            }
        }
        if (checkTangDan == true)   // kiem tra neu mang tang dan thi ko can sap xep nua
        {
            break;
        }
    }
}

int main()
{
    int *a;
    int n;
    do
    {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("\nSo luong khong hop le");
        }
    } while (n <= 0);
    NhapMang(&a, n);
    Bubble_sort(a, n);
    XuatMang(a, n);
    free(a);
    return 0;
}
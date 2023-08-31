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


void Selection_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int idx_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[idx_min] > a[j])
            {
                idx_min = j;
            }
        }
        HoanVi(&a[idx_min], &a[i]);
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
    Selection_sort(a, n);
    XuatMang(a, n);
    free(a);
    return 0;
}
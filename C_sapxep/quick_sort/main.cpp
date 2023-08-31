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

void Quick_sort(int *a, int left, int right)
{
    if (right == left)
    {
        return;
    }
    int pivot = right - 1;
    int j = left;
    for (int i = left; i < pivot; i++)
    {
        if (a[i] < a[pivot])
        {
            HoanVi(&a[i], &a[j]);
            j++;
        }
    }
    HoanVi(&a[j], &a[pivot]);
    Quick_sort(a, left, j);
    Quick_sort(a, j + 1, right);
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
    Quick_sort(a, 0, n);
    XuatMang(a, n);
    free(a);
    return 0;
}
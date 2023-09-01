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

void Merge(int *a, int middle, int left, int right)
{
    int leftsize = middle - left + 1;
    int rightsize = right - middle;
    int left_arr[leftsize];
    int right_arr[rightsize];
    // copy values to 2 new sub arrays
    for (int i = 0; i < leftsize; i++)
    {
        left_arr[i] = a[left + i];
    }
    for (int i = 0; i < rightsize; i++)
    {
        right_arr[i] = a[middle + i + 1];
    }
    int i = 0, j = 0; // starting index of 2 sub arrays
    int idx = left;   // starting idx of original array
    while (i < leftsize && j < rightsize)
    {
        if (left_arr[i] < right_arr[j])
        {
            a[idx++] = left_arr[i++];
        }
        else
        {
            a[idx++] = right_arr[j++];
        }
    }
    while (i < leftsize)
    {
        a[idx++] = left_arr[i++];
    }
    while (j < rightsize)
    {
        a[idx++] = right_arr[j++];
    }
}

void Merge_sort(int *a, int left, int right)
{
    if (left < right)
    {
        // divide array
        int middle = left + (right - left) / 2;
        Merge_sort(a, left, middle);
        Merge_sort(a, middle + 1, right);
        // merge 2 arrays
        Merge(a, middle, left, right);
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
    Merge_sort(a, 0, n - 1);
    XuatMang(a, n);
    free(a);
    return 0;
}
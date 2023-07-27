#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void xuatmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\na[%d] = %d", i, a[i]);
    }
}

void nhapmang2(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d] = ", i);
        // scanf("%d", &a[i]);
        // scanf("%d", a + i); //  a = a[0]   // a + 1 = a[1]
        // scanf("%d", a++);
        scanf("%d", &i[a]);  // a[i] = a + i
    }
}

void xuatmang2(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\na[%d] = %d", i, i[a]);
    }
}

int main()
{
    int n;
    int *a;
    do
    {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n < 0);
    a = (int *)malloc(n * sizeof(int));

    nhapmang2(a, n);
    xuatmang2(a, n);
    printf("\nsizeof(a) = %d", sizeof(a));

    getch();
    return 0;
}
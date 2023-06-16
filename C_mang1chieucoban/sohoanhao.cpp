#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 100

void nhapmang(int a[], int &n)
{
    do
    {
        printf("\nNhap so luong phan tu n: ");
        scanf("%d", &n);
    } while (n < 0 || n > MAX);
    for (int i = 0; i < n; i++)
    {
        a[i] = 0 + rand() % 61;
    }
}

void xuatmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}
int sohoanthien(int n)
{
    int tong = 0;
    if (n < 1)
    {
        return false;
    }
    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                tong += i;
            }
        }
    }
    return tong == n;
}
int sohoanthiencuoimang(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        if (sohoanthien(a[i]))
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    srand(time(NULL));
    int a[MAX];
    int n;
    nhapmang(a, n);
    xuatmang(a, n);
    printf("\nVi tri so hoan thien cuoi mang la: %d", sohoanthiencuoimang(a, n));
    // getch();
    return 0;
}
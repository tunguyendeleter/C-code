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

int checksonguyento(int n)
{
    if (n < 2)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void thaysonguyento(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (checksonguyento(a[i]) == 1)
        {
            a[i] = 0;
        }
    }
}
void hoanvi(int &a, int &b)
{
    a = a - b;
    b = b + a;
    a = b - a;
}
void chensokhongvaosaunguyento(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (checksonguyento(a[i]))
        {
            for (int j = n - 1; j > i; j--)
            {
                hoanvi(a[j], a[j + 1]);
            }
            a[i + 1] = 0;
            i++;
            n++;
        }
    }
}
void xoatatcasonguyento(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        if (checksonguyento(a[i]))
        {
            for (int j = i; j < n - 1; j++)
            {
                hoanvi(a[j], a[j + 1]);
            }
            i--;
            n--;
        }
    }
}
int main()
{
    srand(time(NULL));
    int a[MAX];
    int n;
    nhapmang(a, n);
    printf("\nHam truoc khi sua\n");
    xuatmang(a, n);
    // printf("\nHam sau khi thay doi cac so nguyen to thanh 0\n");
    // thaysonguyento(a, n);
    // printf("\nHam sau khi them 0 vao sau cac so nguyen to\n");
    // chensokhongvaosaunguyento(a, n);
    printf("\nHam sau khi xoa tat ca cac so nguyen to\n");
    xoatatcasonguyento(a, n);
    xuatmang(a, n);

    // getch();
    return 0;
}
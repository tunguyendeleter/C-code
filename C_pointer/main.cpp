#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void hoanvi_c1(int &x, int &y)
{
    x = x + y; // x = x + y
    y = x - y; // y = x + y - y = x
    x = x - y; // x = x + y - x = y
}

void hoanvi_c2(int *x, int *y)
{
    *x = *x + *y; // x = x + y
    *y = *x - *y; // y = x + y - y = x
    *x = *x - *y; // x = x + y - x = y
}

void sapxepmang(int *a, int n, char phanloai)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j] && phanloai == '-')
            {
                hoanvi_c1(a[j], a[i]);
            }
            else if (a[i] > a[j] && phanloai == '+')
            {
                hoanvi_c1(a[j], a[i]);
            }
        }
    }
}

void themphantu(int *&a, int &n, int phantuthem, int vitri)
{
    realloc(a, (n + 1) * sizeof(int));
    for (int i = n + 1; i > vitri; i--)
    {
        a[i] = a[i - 1];
    }
    a[vitri] = phantuthem;
    n++;
}

void xoaphantu(int *&a, int &n, int vitri)
{
    for (int i = vitri; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    realloc(a, (n - 1) * sizeof(int));
    n--;
}

int *timMax(int *a, int n)
{
    int *max = &a[0];
    for (int i = 1; i < n; i++)
    {
        if (*max < a[i])
        {
            max = &a[i];
        }
    }
    return max;
}

void nhapmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap phan tu a[%d]: ", i);
        // scanf("%d", &a[i]);
        // scanf("%d", a + i);
        scanf("%d", a++); // a++ = a[0]++
    }
}

void xuatmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        // printf("\na[%d] = ", i, a[i]);
        // printf("\na[%d] = %d", i, *(a + i));
        printf("\na[%d] = %d", i, *(a++));
    }
}

int main()
{
    int *max;
    int n, *a;
    do
    {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n < 0);

    a = (int *)malloc(n * sizeof(int)); // int:4 byte * n

    nhapmang(a, n);
    max = timMax(a, n);
    printf("\nGia tri Max la: %d", *max);
    sapxepmang(a, n, '+');
    themphantu(a, n, 100, 0);
    xoaphantu(a, n, n);
    xuatmang(a, n);

    // printf("\nGia tri cua y: %d", *py);
    // printf("\nKich thuoc con tro pa: %d", sizeof(pa));

    getch();
    return 0;
}

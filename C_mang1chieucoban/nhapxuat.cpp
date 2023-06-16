#include <stdio.h>
#include <conio.h>
#define MAX 100

void nhapmang(int a[], int &n)
{
    do
    {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n < 0 || n > 100);
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap phan tu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    return;
}
void xuatmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nPhan tu thu %d: %d", i + 1, a[i]);
    }
}

int main()
{
    int n = 0;
    int a[MAX];
    nhapmang(a, n);
    xuatmang(a, n);

    getch();
    return 0;
}
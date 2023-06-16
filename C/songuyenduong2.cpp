#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n;
    int n1;
    int num = 0;
    int check = 0;
    int giua;
    do
    {
        printf("\nNhap so nguyen duong: ");
        scanf("%d", &n);
    } while (n < 0);
    n1 = n;
    while (n > 0)
    {
        int temp = n % 10;
        num *= 10;
        num += temp;
        n /= 10;
    }
    if (num == n1)
    {
        printf("\nDay la doi so");
    }

    n = n1;
    int i = 1;
    while (i * i <= n)
    {
        if (i * i == n)
        {
            check = 1;
            break;
        }
        i++;
    }

    if (check == 1)
    {
        printf("\nDay la so chinh phuong");
    }

    check = 0;
    giua = n / 2;
    for (int j = 2; j <= giua; j++)
    {
        if (n % j == 0)
        {
            check = 1;
        }
    }
    if (check == 0 && n != 1)
    {
        printf("\nDay la so nguyen to");
    }


    



    return 0;
}
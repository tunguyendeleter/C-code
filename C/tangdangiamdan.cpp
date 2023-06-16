#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n;
    int k = 0;
    int check = 0;
    int checknn = 0;
    do
    {
        printf("\nNhap so nguyen duong : ");
        scanf("%d", &n);
    } while (n < 0);
    /*
    lấy kích thước n
    lặp lấy só đầu tiên 123/100 = 1%10 = 1  1234/1000 = 12%10 = 2   
    so sách 1<2 => neu 2>1 tang

    */

    int len = (int)log10((float)n) + 1;
    for (int i = len - 1; i >= 0; i--)
    {
        long long sobichia = pow(10, i) + 0.5;
        int temp = (n / sobichia) % 10;
        printf("\n%d", sobichia);
        printf("\n%d", temp);
        if (k < temp)
        {
            check = 1;
            k = temp;
        }
        else if (k == temp)
        {
            checknn = 1;
        }
        else
        {
            check = 0;
            printf("\nKhong phai so tang dan");
            return 0;
        }
    }
    if (checknn == 1)
    {
        printf("\nSo tang dan khong nghiem ngat");
    }
    else
    {
        printf("\nSo tang dan nghiem ngat");
    }

    return 0;
}
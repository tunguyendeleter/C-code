#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float a, b, c;
    int check = 0;
    printf("\nNhap cach a: ");
    scanf("%d", &a);
    printf("\nNhap cach b: ");
    scanf("%d", &b);
    printf("\nNhap cach c: ");
    scanf("%d", &c);

    if ((a + b <= c) || (b + c <= a) || (a + c <= b))
    {
        printf("\nDay khong phai tam giac");
    }
    else
    {
        if (a == b && b == c)
        {
            printf("\nDay la tam giac deu");
            getch();
            return 0;
        }
        else if (a == b || b == c || c == a)
        {
            check = 1;
        }
        if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a)
        {
            if (check == 1)
            {
                printf("\nDay la tam giac vuong can");
                getch();
                return 0;
            }
            else
            {
                printf("\nDay la tam giac vuong");
                getch();
                return 0;
            }
        }
        else
        {
            if (check == 1)
            {
                printf("\nDay la tam giac can");
                getch();
                return 0;
            }
            else
            {
                printf("\nDay la tam giac thuong");
            }
        }
    }

    getch();
    return 0;
}
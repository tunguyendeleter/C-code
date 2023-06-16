#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    float a, b, c;
    float delta;
    printf("\nNhap a = ");
    scanf("%f", &a);
    printf("\nNhap b = ");
    scanf("%f", &b);
    printf("\nNhap c = ");
    scanf("%f", &c);
    delta = b * b - 4 * a * c;

    if (a == 0) // bx + c =0
    {
        if (b == 0)
        {
            printf("\nPuong trinh vo nghiem");
        }
        else
        {
            if (c == 0) // bx = 0
            {
                if (b == 0) // 0x = 0
                {
                    printf("\nPhuong trinh vo so nghiem");
                }
                else
                {
                    printf("\nPhuong trinh co nghiem x = 0");
                }
            }
            else
            {
                float x = -c / b;
                if (x > 0)
                {
                    x = sqrt(x);
                    printf("\nx1 = %f", x);
                    printf("\nx2 = %f", -x);
                }
                else
                {
                    printf("\nPuong trinh vo nghiem");
                }
            }
        }
    }
    else
    {
        if (delta > 0)
        {
            float x1 = (-b - sqrt(delta)) / (2 * a);
            float x2 = (-b + sqrt(delta)) / (2 * a);
            if (x1 > 0)
            {
                x1 = sqrt(x1);
                printf("\nx1 = %f", x1);
                printf("\nx2 = %f", -x1);
            }
            if (x2 > 0)
            {
                x2 = sqrt(x2);
                printf("\nx3 = %f", x2);
                printf("\nx4 = %f", -x2);
            }
        }
        else if (delta == 0)
        {
            float x = -b / (2 * a);
            if (x > 0)
            {
                x = sqrt(x);
                printf("\nx1 = %f", x);
                printf("\nx2 = %f", -x);
            }
            else
            {
                printf("\nPuong trinh vo nghiem");
            }
        }
        else
        {
            printf("\nPhuong trinh vo nghiem");
        }
    }
    return 0;
}
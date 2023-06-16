#include <stdio.h>
#include <conio.h>

int main()
{
    int nam, thang;
    int check = 0;
    printf("\nNhap vao thang: ");
    scanf("%d", &thang);
    if (thang > 12 || thang < 1)
    {
        printf("\nThang khong dung");
        return 0;
    }
    printf("\nNhap vao nam: ");
    scanf("%d", &nam);
    if ((nam % 4 == 0) && (nam % 100 != 0) || (nam % 400 == 0))
        {
            printf("\nnam %d la nam nhuan");
        }
    else
    {
        check = 1;
        printf("\nnam %d khong phai nam nhuan");
    }

    if (thang == 1)
    {
        printf("\nthang %d co %d", thang, 31);
    }
    else if (thang == 2)
    {
        if (check == 1)
        {
            printf("\nthang %d co %d", thang, 28);
        }
        else
        {
            printf("\nthang %d co %d", thang, 29);
        }
    }
    else if (thang == 3)
    {
        printf("\nthang %d co %d", thang, 31);
    }
    else if (thang == 4)
    {
        printf("\nthang %d co %d", thang, 30);
    }
    else if (thang == 5)
    {
        printf("\nthang %d co %d", thang, 31);
    }
    else if (thang == 6)
    {
        printf("\nthang %d co %d", thang, 30);
    }
    else if (thang == 7)
    {
        printf("\nthang %d co %d", thang, 31);
    }
    else if (thang == 8)
    {
        printf("\nthang %d co %d", thang, 31);
    }
    else if (thang == 9)
    {
        printf("\nthang %d co %d", thang, 30);
    }
    else if (thang == 10)
    {
        printf("\nthang %d co %d", thang, 31);
    }
    else if (thang == 11)
    {
        printf("\nthang %d co %d", thang, 30);
    }
    else if (thang == 12)
    {
        printf("\nthang %d co %d", thang, 31);
    }
    return 0;
}
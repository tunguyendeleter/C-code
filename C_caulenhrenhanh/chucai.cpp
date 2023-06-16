#include <stdio.h>
#include <conio.h>

int main()
{
    char c;
    printf("\nNhap mot chu cai tu ban phim");
    scanf("%c", &c);
    if ((c < 62) || c > 122 || (c > 90 && c < 97))
    {
        printf("\nKhong phai chu cai");
        getch();
        return 0;
    }
    else
    {
        if (c < 97)
        {
            c += 32;
            printf("\n%c", c);
        }
        else
        {
            c -= 32;
            printf("\n%c", c);
        }
    }

    getch();
    return 0;
}
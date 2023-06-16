#include <stdio.h>
#include <conio.h>
#define LCB 650000

int main()
{
    float TNCT;
    float heso;
    float luong;
    printf("\nNhap TNCT : ");
    scanf("%f", &TNCT);
    if (TNCT < 12)
    {
        heso = 1.92;
    }
    else if (12 < TNCT && TNCT < 36)
    {
        heso = 2.34;
    }
    else if (36 < TNCT && TNCT < 60)
    {
        heso = 3;
    }
    else
    {
        heso = 4.5;
    }
    luong = heso*LCB;
    printf("muc luong can ban la: %f", luong);

    getch();
    return 0;
}
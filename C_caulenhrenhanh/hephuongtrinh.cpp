#include <stdio.h>
#include <conio.h>

int main()
{
    float a, b, c, d, e, f;
    float x, y;
    printf("\nNhap a: ");
    scanf("%f", &a);
    printf("\nNhap b: ");
    scanf("%f", &b);
    printf("\nNhap c: ");
    scanf("%f", &c);

    printf("\nNhap d: ");
    scanf("%f", &d);
    printf("\nNhap e: ");
    scanf("%f", &e);
    printf("\nNhap f: ");
    scanf("%f", &f);

    if (a == 0)
    {
        y = c / b;
        x = (f - e * y) / d;
    }
    else if (b == 0)
    {
        x = c / a;
        y = (f - d * x) / e;
    }
    else if (d == 0)
    {
        y = f / e;
        x = (c - b * y) / a;
    }
    else if (e == 0)
    {
        x = f / d;
        y = (c - a * x) / b;
    }
    else
    {
        float heso = d / a;
        b *= heso;
        c *= heso;
        b -= e;
        c -= f;
        y = c / b;
        x = (f - e * y) / d;
    }

    printf("\nx = %f", x);
    printf("\ny = %f", y);

    return 0;
}
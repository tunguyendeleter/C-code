#include <stdio.h>
#include <conio.h>

int TongCuaChuSo(int n)
{
    // dieu khien dung
    if (n == 0)
    {
        return 0;
    }
    // hanh dong de quy
    return n % 10 + TongCuaChuSo(n / 10);
}

int main()
{
    printf("\nTong cua chu so 123456 la: %d", TongCuaChuSo(123456));
    return 0;
}
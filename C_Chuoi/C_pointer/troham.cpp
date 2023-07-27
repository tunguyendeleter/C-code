#include <iostream>
#include <string>
using namespace std;


template <class hamhoanvi>
void hoanvi(hamhoanvi &a, hamhoanvi &b)
{
    hamhoanvi temp = a;
    a = b;
    b = temp;
}

int tinhtong(int a, int b)
{
    return a + b;
}
int tinhhieu(int a, int b)
{
    return a - b;
}

int (*tinhtoan(char phep))(int, int)
{
    if (phep == '+')
    {
        return tinhtong;
    }
    else if (phep == '-')
    {
        return tinhhieu;
    }
}

int main()
{
    float a = 5.5, b = 10.5;

    hoanvi<float>(a, b);

    cout << "\na la: " << a;
    cout << "\nb la: " << b;

    // int (*controham)(int, int);
    // controham = tinhtoan('-');
    // printf("\nGia tri ket qua la : %d", controham(a, b));

    return 0;
}
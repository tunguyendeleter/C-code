#include <iostream>
using namespace std;

void REALLOC(int *&a, int oldSize, int newSize)
{
    // tạo 1 mảng mới cùng kích thước
    int *b = new int[oldSize];
    for (int i = 0; i < oldSize; i++)
    {
        b[i] = a[i];
    }
    // xoa mang cũ và tạo mảng mới
    delete[] a;
    a = new int[newSize];
    int min = oldSize < newSize ? oldSize : newSize;
    for (int i = 0; i < min; i++)
    {
        a[i] = b[i];
    }
    delete[] b;
}

void nhapmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap a[" << i << "]:";
        // cin >> a[i];
        cin >> *(a + i);
    }
}

void xuatmang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\na[" << i << "] = " << a[i];
    }
}

void themphantu(int *&a, int &n, int phantuthem, int vitri)
{
    REALLOC(a, n, n + 1);
    for (int i = n; i > vitri; i--)
    {
        a[i] = a[i - 1];
    }
    a[vitri] = phantuthem;
    n++;
}

void xoaphantu(int *&a, int &n, int vitri)
{
    for (int i = vitri; i > n; i++)
    {
        a[i] = a[i + 1];
    }
    REALLOC(a, n, n - 1);
    n--;
}

int main()
{
    int n = 5;
    int *a = new int[n];
    nhapmang(a, n);
    // xuatmang(a, n);
    xoaphantu(a, n, 3);
    xuatmang(a, n);

    delete[] a;
    return 0;
}
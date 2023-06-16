#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100

void nhapmang(int a[], int &n)
{
    do
    {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
    } while (n < 0 || n > MAX);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("\nNhap phan tu %d: ", i + 1);
    //     scanf("%d", &a[i]);
    // }
    for (int i = 0; i < n; i++)
    {
        a[i] = -20 + rand() % 51;
    }

    return;
}
void xuatmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nPhan tu thu %d: %d", i + 1, a[i]);
    }
}

bool mangtoanchan(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            return false;
        }
    }
    return true;
}

bool mangtoansonguyento(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 || a[i] == 0)
        {
            return false;
        }
        for (int j = 2; j < a[i] / 2; j++)
        {
            if (a[i] % j == 0)
            {
                return false;
            }
        }
    }

    return true;
}

bool mangcotangdan(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            return false;
        }
    }
    return true;
}

int chiahet4khongchiahet5(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 4 == 0 && a[i] % 5 != 0)
        {
            count++;
        }
    }
    return count;
}

int tongsonguyento(int a[], int n)
{
    int count = 0;
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 || a[i] == 0)
        {
            check = false;
        }
        else if (a[i] > 1)
        {
            for (int j = 2; j <= a[i] / 2; j++)
            {
                if (a[i] % j == 0)
                {
                    check = false;
                }
            }
        }
        else
        {
            check = false;
        }
        if (check == true)
        {
            count += a[i];
        }
        else
        {
            check = true;
        }
    }

    return count;
}

int vitricuoicungcuax(int a[], int n)
{
    int x;
    printf("\nNhap phan tu x: ");
    scanf("%d", &x);
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == x)
        {
            return i + 1;
        }
    }
    return -1;
}
int songuyendautien(int a[], int n)
{
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 || a[i] == 0)
        {
            check = false;
        }
        else if (a[i] > 1)
        {
            for (int j = 2; j <= a[i] / 2; j++)
            {
                if (a[i] % j == 0)
                {
                    check = false;
                }
            }
        }
        else
        {
            check = false;
        }
        if (check == true)
        {
            return i + 1;
        }
        else
        {
            check = true;
        }
    }
    return -1;
}

int timmin(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int timminduong(int a[], int n)
{
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            min = a[i];
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            if (a[i] < min)
            {
                min = a[i];
            }
        }
    }
    return min;
}

void hoanvi(int &a, int &b)
{
    a = a - b; // a = a - b
    b = a + b; // b = (a - b) + b = a
    a = b - a; // a = a - (a - b) = b
}
void interchange_sort(int a[], int n, char key)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (key == 't')
            {
                if (a[i] > a[j])
                {
                    hoanvi(a[i], a[j]);
                }
            }
            else if (key == 'g')
            {
                if (a[i] < a[j])
                {
                    hoanvi(a[i], a[j]);
                }
            }
        }
    }
}

void tachmang(int a[], int b[], int c[], int n, int &index1, int &index2)
{
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 || a[i] == 0)
        {
            check = false;
        }
        else if (a[i] > 1)
        {
            for (int j = 2; j <= a[i] / 2; j++)
            {
                // printf("\n%d", a[i]);
                if (a[i] % j == 0)
                {
                    check = false;
                }
            }
        }
        else
        {
            check = false;
        }
        if (check == true)
        {
            b[index1++] = a[i];
        }
        else
        {
            c[index2++] = a[i];
            check = true;
        }
    }
}

void sapxepmang(int a[], int n)
{
    int b[MAX];
    int index1 = 0;
    int c[MAX];
    int index2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            b[index1++] = a[i];
        }
        else if (a[i] < 0)
        {
            c[index2++] = a[i];
        }
    }
    interchange_sort(b, index1, 'g');
    interchange_sort(c, index1, 't');
    for (int i = 0; i < index2; i++)
    {
        b[index1++] = c[i];
    }
    xuatmang(b, index1);
}

int main()
{
    srand(time(NULL));
    int a[MAX];
    int b[MAX];
    int c[MAX];
    int n = 0;
    int n1 = 0;
    int n2 = 0;
    nhapmang(a, n);
    xuatmang(a, n);
    if (mangtoanchan(a, n))
    {
        printf("\nMang toan chan");
    }
    else
    {
        printf("\nMang ko phai toan chan");
    }
    if (mangtoansonguyento(a, n))
    {
        printf("\nMang toan so nguyen to");
    }
    else
    {
        printf("\nMang ko phai toan so nguyen to");
    }
    if (mangcotangdan(a, n))
    {
        printf("\nMang tang dan");
    }
    else
    {
        printf("\nMang ko tang dan");
    }
    int dem = chiahet4khongchiahet5(a, n);
    printf("\nCo %d so chia het cho 4 nhung khong chia het cho 5", dem);
    dem = tongsonguyento(a, n);
    printf("\nTong so nguyen to la: %d ", dem);
    dem = vitricuoicungcuax(a, n);
    printf("\nVi tri cuoi cung cua x la: %d ", dem);
    dem = songuyendautien(a, n);
    printf("\nVi tri so nguyen dau tien la: %d ", dem);
    dem = timmin(a, n);
    printf("\nSo nho nhat trong mang la: %d ", dem);
    dem = timminduong(a, n);
    printf("\nSo duong nho nhat trong mang la: %d ", dem);

    printf("\nMang b sau khi copy cac so nguyen to");
    tachmang(a, b, c, n, n1, n2);
    xuatmang(b, n1);
    printf("\nMang b sau khi copy cac con lai");
    xuatmang(c, n2);

    printf("\nMang a sau sap xep giam dan");
    interchange_sort(a, n, 'g');
    xuatmang(a, n);
    printf("\nSap xep mang duong tang am giam");
    sapxepmang(a, n);
    getch();
    return 0;
}
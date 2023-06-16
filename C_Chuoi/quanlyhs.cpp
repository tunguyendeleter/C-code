#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

bool kiemtratrung(char maso[MAX][10], int n, char so[10])
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(so, maso[i]) == 0)
        {
            dem++;
            if (dem == 2)
            {
                return true;
            }
        }
    }
    return false;
}
    void nhapten(char ten[MAX][30], char maso[MAX][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap thong tin hoc sinh (thu %d): ", i + 1);
        printf("\nNhap ten: ", i + 1);
        fflush(stdin);
        gets(ten[i]);
        do
        {
            printf("\nNhap ma so: ", i + 1);
            fflush(stdin);
            gets(maso[i]);
        } while (kiemtratrung(maso, i + 1, maso[i]));
    }
}
void nhapdiem(float toan[], float ly[], float hoa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        toan[i] = (float)(1 + rand() % 10);
        ly[i] = (1 + rand() % 10);
        hoa[i] = (1 + rand() % 10);
    }
}
void xeploai(float toan[], float ly[], float hoa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        float diemtb = (toan[i] + ly[i] + hoa[i]) / 3;
        if (diemtb >= 5 && diemtb < 6.5)
        {
            printf("\nHoc sinh %d: Trung binh", i + 1);
        }
        else if (diemtb >= 6.5 && diemtb < 8)
        {
            printf("\nHoc sinh %d: Kha", i + 1);
        }
        else if (diemtb >= 8)
        {
            printf("\nHoc sinh %d: Gioi", i + 1);
        }
        else
        {
            printf("\nHoc sinh %d: Yeu", i + 1);
        }
    }
}
void nhaphocsinh(char ten[MAX][30], char maso[MAX][10], float toan[], float ly[], float hoa[], int n)
{
    nhapten(ten, maso, n);
    nhapdiem(toan, ly, hoa, n);
    xeploai(toan, ly, hoa, n);
}
void xuathocsinh(float toan[], float ly[], float hoa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nDiem toan: %f", toan[i]);
        printf("\nDiem ly: %f", ly[i]);
        printf("\nDiem hoa: %f", hoa[i]);
    }
}
int main()
{
    int n;
    do
    {
        printf("\nNhap so luong hoc sinh: ");
        scanf("%d", &n);
    } while (n < 0 || n > MAX);
    srand(time(NULL));
    char maso[MAX][10];
    char ten[MAX][30];
    float toan[MAX];
    float ly[MAX];
    float hoa[MAX];
    // nhapdiem(toan, ly, hoa, n);
    // xuatdiem(toan, ly, hoa, n);
    // xeploai(toan, ly, hoa, n);
    nhaphocsinh(ten, maso, toan, ly, hoa, n);
    return 0;
}
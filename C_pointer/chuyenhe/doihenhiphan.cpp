// Viết chương trình nhập vào 1 số nguyên dương x. Đổi x sang 3 hệ gồm hệ 2, hệ 8 và hệ 16.

/*
vd: x = 250

* Hệ 2 *
250 : 2 bằng 125 dư 0
125 : 2 bằng 62 dư 1
62 : 2 bằng 31 dư 0
31 : 2 bằng 15 dư 1
15 : 2 bằng 7 dư 1
7 : 2 bằng 3 dư 1
3 : 2 bằng 1 dư 1
1 : 2 bằng 0 dư 1

=> 250 = 11111010
=> đánh số         : 8 7 6 5 4 3 2 1 0
=> dãy nhị phân: 0 1 1 1 1 1 0 1 0

Đánh số từ phải qua trái bắt đầu từ 0
thử: 0 * 2^0 + 1 * 2^1 + 0 * 2^2 + 1 * 2^3 + 1 * 2^4 + 1 * 2^5 + 1 * 2^6 + 1 * 2^7 + 0 * 2^8

= 2 + 8 + 16 + 32 + 64 + 128
=> 250
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int POW(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }
    int tam = a;
    for (int i = 2; i <= b; i++)
    {
        a *= tam;
    }
    return a;
}

int STRLEN(char *str)
{
    int dem = 0;
    while (str[dem] != '\0')
    {
        dem++;
    }
    return dem;
}

char *DoiNhiPhan(int so)
{
    int nhiphan[100];
    int dem = 0;
    while (so != 0)
    {
        int tam = (so % 2);
        so /= 2;
        nhiphan[dem] = tam;
        dem++;
    }
    char *kq = (char *)malloc((dem + 1) * sizeof(char));
    int j = 0;
    for (int i = dem - 1; i >= 0; i--)
    {
        kq[j] = nhiphan[i] + 48; // +48 chuyen int sang char
        j++;
    }
    kq[dem] = '\0';
    return kq;
}

int DoiThapPhan(char *nhiphan)
{
    int kq = 0;
    int len = STRLEN(nhiphan);
    int j = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        kq += (nhiphan[i] - 48) * POW(2, j);
        j++;
    }
    return kq;
}

int main()
{
    int so, so2;
    char *nhiphan;
    do
    {
        printf("\nNhap so nguyen duong x: ");
        scanf("%d", &so);
        if (so <= 0)
        {
            printf("\nSo khong hop le");
        }
    } while (so <= 0);

    nhiphan = DoiNhiPhan(so);
    printf("\nSo nhi phan: %s", nhiphan);

    so2 = DoiThapPhan(nhiphan);
    printf("\nSo thap phan: %d", so2);

    free(nhiphan);
    return 0;
}
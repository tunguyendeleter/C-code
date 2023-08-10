/*
* Hệ 16 *
250 : 16 = 15 dư 10
15 : 16 = 0 dư 15

Đối với hệ 16 sẽ có quy tắc sau:
- Nếu kết quả vượt qua 9 thì sẽ có quy tắc:

10 là A
11 là B
12 là C
13 là D
14 là E
15 là F

=> 250 đổi sang hệ 16 sẽ là: FA
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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

char *DoiThapLuc(int so)
{
    char *kq;
    int thapluc[100];
    int dem = 0;
    while (so != 0)
    {
        int tam = so % 16;
        thapluc[dem] = tam;
        so /= 16;
        dem++;
    }
    kq = (char *)malloc((dem + 1) * sizeof(char));
    int j = 0;
    for (int i = dem - 1; i >= 0; i--)
    {
        if (thapluc[i] > 9)
        {
            kq[j++] = thapluc[i] + 55; // chuyen 10-15  sang 'A'-'F'
        }
        else
        {
            kq[j++] = thapluc[i] + 48; // chuyen 0-9 sang '0'-'9'
        }
    }
    kq[dem] = '\0';
    return kq;
}

int DoiThapPhan(char *thapluc)
{
    int kq = 0;
    int j = 0;
    int len = STRLEN(thapluc);
    for (int i = len - 1; i >= 0; i--)
    {
        if (thapluc[i] >= 65) // ASCII 65 = 'A'
        {
            kq += (thapluc[i] - 55) * POW(16, j);
        }
        else
        {
            kq += (thapluc[i] - 48) * POW(16, j);
        }
        j++;
    }
    return kq;
}

int main()
{
    int x;
    char *thapluc;
    int thapphan;
    do
    {
        printf("\nNhap so nguyen duong x: ");
        scanf("%d", &x);
        if (x <= 0)
        {
            printf("\nSo khong hop le");
        }

    } while (x <= 0);

    thapluc = DoiThapLuc(x);
    printf("\nHe thap luc: %s", thapluc);
    thapphan = DoiThapPhan(thapluc);
    printf("\nHe thap phan: %d", thapphan);
    free(thapluc);
    return 0;
}
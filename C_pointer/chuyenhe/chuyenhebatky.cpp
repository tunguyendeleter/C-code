#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// co 3 he: 2, 8, 16

char *ChuyenHe(int x, int he)
{
    int chuyenhe[100];
    int dem = 0;
    while (x != 0)
    {
        int tam = x % he;
        chuyenhe[dem] = tam;
        x /= he;
        dem++;
    }
    char *kq = (char *)malloc((dem + 1) * sizeof(char));
    int j = 0;
    for (int i = dem - 1; i >= 0; i--)
    {
        if (chuyenhe[i] > 9)
        {
            kq[j] = chuyenhe[i] + 55;
        }
        else
        {
            kq[j] = chuyenhe[i] + 48;
        }
        j++;
    }
    kq[dem] = '\0';
    return kq;
}

int main()
{
    char *kq;
    int x, y;
    do
    {
        printf("\nNhap so nguyen duong x: ");
        scanf("%d", &x);
        if (x <= 0)
        {
            printf("\nSo khong hop le");
        }

    } while (x <= 0);
    do
    {
        printf("\nNhap he: ");
        scanf("%d", &y);
        if (y != 2 && y != 8 && y != 16)
        {
            printf("\nHe khong hop le");
        }

    } while (y != 2 && y != 8 && y != 16);
    kq = ChuyenHe(x, y);
    printf("\nKet qua sau khi chuyen he: %s", kq);
    free(kq);
    return 0;
}
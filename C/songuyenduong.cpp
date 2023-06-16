#include <stdio.h>
#include <conio.h>

int main()
{
    float S1 = 0;
    float S2 = 0;
    float S3 = 0;
    float S4 = 1;
    float S5 = 0;
    int n;
    do
    {
        printf("\nNhap so nguyen duong : ");
        scanf("%d", &n);
    } while (n < 0);

    for (int i = 1; i <= n; i++)
    {
        S1 += i;
        S2 += i * i;
        S3 += (float)1 / i;
        S4 *= i;
    }
    for (int i = 1; i <= n; i++)
    {
        int temp = 1;
        for (int j = 1; j <= n; j++)
        {
            temp *= j;
        }
        S5 += temp;
    }

    printf("\nS1 = %f", S1);
    printf("\nS2 = %f", S2);
    printf("\nS3 = %f", S3);
    printf("\nS4 = %f", S4);
    printf("\nS5 = %f", S5);
    return 0;
}
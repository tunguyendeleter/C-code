#include <stdio.h>
#include <conio.h>

int main()
{
    int n;
    do
    {
        printf("\nNhap n: ");
        scanf("%d", &n);
    } while (n < 1);

    int fibo_2 = 1;
    int fibo = 1;
    int fibo_1 = 1;
    printf("\n%d", fibo_1);
    printf("\n%d", fibo_2);
    for (int i = 2; i <= n; i++)
    {
        fibo = fibo_1 + fibo_2;
        fibo_2 = fibo_1;
        fibo_1 = fibo;
        printf("\n%d", fibo);
    }

    getch();
    return 0;
}
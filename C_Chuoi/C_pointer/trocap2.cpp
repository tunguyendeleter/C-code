#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void nhapmang(int **a, int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            printf("\nNhap a[%d][%d]: ", i, j);
            // scanf("%d", &a[i][j]);
            // scanf("%d", a[i] + j);   
            scanf("%d", *((a + i) + j)); 
        }
    }
}

void xuatmang(int **a, int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            // printf("%4d", a[i][j]);
            // printf("%4d", *(a[i] + j));
            printf("%4d", *(*(a + i)) + j);
        }
        printf("\n");
    }
}


int main()
{
    int dong = 2;
    int cot = 3;
    int **a;
    a = (int **)malloc(dong * sizeof(int));
    for (int i = 0; i < dong; i++)
    {
        a[i] = (int *)malloc(cot * sizeof(int));
    }
    nhapmang(a, dong, cot);
    xuatmang(a, dong, cot);

    for (int i = 0; i < dong; i++)
    {
        free(a[i]);
    }
    free(a);
    
    getch();
    return 0;
}
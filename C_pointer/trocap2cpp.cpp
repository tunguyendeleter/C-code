#include <iostream>
using namespace std;

void nhapmang(int **a, int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            printf("\nNhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
            // scanf("%d", a[i] + j);
            // scanf("%d", *(a + i) + j);
        }
    }
}

void xuatmang(int **a, int dong, int cot)
{
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {       
            cout << "a[]"
        }
        printf("\n");
    }
}

int main()
{
    int **a;
    int dong = 2, cot = 3;
    a = new int *[dong];
    for (int i = 0; i < dong; i++)
    {
        a[i] = new int[cot];
    }

    for (int i = 0; i < dong; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
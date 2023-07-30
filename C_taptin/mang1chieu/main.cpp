#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void MoFile(FILE **FileIn)
{
    *FileIn = fopen("INPUT.txt", "r");
    if (*FileIn == NULL)
    {
        printf("\nKhong tim thay tap tin");
        exit(0);
    }
}

void HoanVi(int &a, int &b)
{
    int tam = a;
    a = b;
    b = tam;
}

void SapXepTangDan(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                HoanVi(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    // doc du lieu tu tap tin
    FILE *FileIn;
    MoFile(&FileIn);
    int *n;
    int soluong;
    fscanf(FileIn, "%d", &soluong);
    n = (int *)malloc(soluong * sizeof(int));
    for (int i = 0; i < soluong; i++)
    {
        fscanf(FileIn, "%d", &n[i]);
    }
    SapXepTangDan(n, soluong);
    fclose(FileIn);

    // ghi du lieu vao tap tin
    FILE *FileOut;
    FileOut = fopen("OUTPUT.txt", "w");
    for (int i = 0; i < soluong; i++)
    {
        fprintf(FileOut, "%d ", n[i]);
    }
    fclose(FileOut);

    return 0;
}
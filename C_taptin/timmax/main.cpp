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

float TimDiemMax(FILE **FileIn)
{
    float max;
    while (!feof(*FileIn))
    {
        float sosanh;
        fscanf(*FileIn, "%f", &sosanh);
        if (max < sosanh)
        {
            max = sosanh;
        }
    }
    return max;
}

int main()
{
    // doc du lieu tu tap tin
    FILE *FileIn;
    MoFile(&FileIn);
    float max = TimDiemMax(&FileIn);
    fclose(FileIn);

    // ghi du lieu vao tap tin
    FILE *FileOut;
    FileOut = fopen("OUTPUT.txt", "w");
    fprintf(FileOut, "\nMax = %f", max);
    fclose(FileOut);

    return 0;
}
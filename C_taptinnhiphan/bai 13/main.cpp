#include <stdio.h>
#include <conio.h>

void NhapDuLieu(int &a, int &b, int &c)
{
    printf("\nNhap a = ");
    scanf("%d", &a);

    printf("\nNhap b = ");
    scanf("%d", &b);

    printf("\nNhap c = ");
    scanf("%d", &c);
}

void GhiFile(FILE *&FileOut, int a, int b, int c) // tham chiếu nếu mở tập tin trong hàm
{
    FileOut = fopen("OUTPUT.TXT", "w");
    if (FileOut != NULL)
    {
        fprintf(FileOut, "a = %d\nb = %d\nc = %d", a, b, c);
    }
    fclose(FileOut);
}

int main()
{
    int a, b, c;
    NhapDuLieu(a, b, c);
    FILE *FileIn;
    GhiFile(FileIn, a, b, c);
    return 0;
}
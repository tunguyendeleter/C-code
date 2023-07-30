#include <stdio.h>
#include <conio.h>

int main()
{
    /* DOC DU LIEU TU TAP TIN */
    // B1: khai bao con tro file
    FILE *FileIn;
    // B2: tro toi vung nho chua file
    FileIn = fopen("INPUT.TXT", "r");
    // B3: kiem tra neu tap tin co ton tai
    if (FileIn == NULL)
    {
        printf("\nKhong tim thay tap tin INPUT.TXT! xin kiem tra lai");
        return 0;
    }
    // B4: doc du lieu tu tap tin
    int a, b;
    fscanf(FileIn, "%d%d", &a, &b);
    // B5: dong tap tin
    fclose(FileIn);

    printf("\na = %d & b = %d", a, b);
    int max = a > b ? a : b;

    /* GHI DU LIEU VAO TAP TIN */
    // B1: mo tap tin
    FILE *FileOut;
    FileOut = fopen("OUTPUT.TXT", "a");
    // B2: ghi du lieu
    fprintf(FileOut, "\nMax = %d", max);
    // B3: dong file
    fclose(FileOut);

    return 0;
}
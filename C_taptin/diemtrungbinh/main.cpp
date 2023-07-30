#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

float TinhDiemTrungBinh(float toan, float ly, float hoa)
{
    return (toan + ly + hoa) / 3;
}

char *XepLoai(float diem)
{
    if (diem < 2)
    {
        return (char *)"Kem";
    }
    if (diem < 5)
    {
        return (char *)"Yeu";
    }
    if (diem < 7)
    {
        return (char *)"Trung Binh";
    }
    if (diem < 8)
    {
        return (char *)"Kha";
    }
    if (diem < 9)
    {
        return (char *)"Gioi";
    }
    return (char *)"Xuat sac";
}

void MoFile(FILE **FileIn)
{
    // B1: mo file
    *FileIn = fopen("INPUT.TXT", "r");
    // kiem tra file
    if (!*FileIn)
    {
        printf("\nKhong tim thay file INPUT.TXT");
        exit(0); // ket thuc toan bo chuong trinh
    }
}

int main()
{
    // Mo file INPUT.TXT va doc du lieu
    // B2: doc file
    FILE *FileIn;
    MoFile(&FileIn);
    char ten[30];
    float toan, ly, hoa;
    fgets(ten, 30, FileIn);
    fscanf(FileIn, "%f%f%f", &toan, &ly, &hoa);
    // B3: dong file
    fclose(FileIn);

    // printf("\nTen: %s", ten);
    // printf("\nToan: %f", toan);
    // printf("\nLy: %f", ly);
    // printf("\nHoa: %f", hoa);

    FILE *FileOut;
    FileOut = fopen("OUTPUT.txt", "w");
    char xeploai[30];
    float diemtb = TinhDiemTrungBinh(toan, ly, hoa);
    strcpy(xeploai, XepLoai(diemtb));

    fprintf(FileOut, "\nTen: %s", ten);
    fprintf(FileOut, "\nDiem trung binh: %f", diemtb);
    fprintf(FileOut, "\nXep loai: %s", xeploai);
    fclose(FileOut);

    return 0;
}
#include "LopHoc.h"

void NhapLopHoc(LOPHOC *lh)
{
    do
    {
        printf("\nNhap so luong sinh vien: ");
        scanf("%d", &lh->n);
        if (lh->n < 0)
        {
            printf("\nSo luong lop hoc khong hop le");
        }
    } while (lh->n < 0);
    lh->sinhvien = (SINHVIEN *)malloc(lh->n * sizeof(SINHVIEN));
    for (int i = 0; i < lh->n; i++)
    {
        int check;
        printf("\n==========Nhap sinh vien thu %d==========", i + 1);
        // kiem tra bi trung ma so sinh vien
        do
        {
            check = 0;
            fflush(stdin);
            printf("\nNhap ma so: ");
            gets(lh->sinhvien[i].Maso);
            for (int j = 0; j < i; j++)
            {
                if (strcmp(lh->sinhvien[i].Maso, lh->sinhvien[j].Maso) == 0)
                {
                    check = 1;
                    break;
                }
            }
            if (check)
            {
                printf("\nMa so bi trung, vui long nhap lai");
            }
        } while (check);
        NhapSinhVien(&lh->sinhvien[i]);
    }
}

void XuatLopHoc(LOPHOC lh)
{
    for (int i = 0; i < lh.n; i++)
    {
        printf("\n==========Xuat sinh vien thu %d==========", i + 1);
        XuatSinhVien(&lh.sinhvien[i]);
    }
}

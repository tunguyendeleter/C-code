#include "MonHoc.h"

void NhapMonHoc(MONHOC *mh)
{
    fflush(stdin);
    printf("\nNhap ten mon hoc: ");
    gets(mh->TenMon);
    do
    {
        printf("\nNhap so diem: ");
        scanf("%f", &mh->SoDiem);
        if (mh->SoDiem < 0 || mh->SoDiem > 10)
        {
            printf("\nSo diem khong hop le");
        }

    } while (mh->SoDiem < 0 || mh->SoDiem > 10);
    do
    {
        printf("\nNhap so chi: ");
        scanf("%d", &mh->SoChi);
        if (mh->SoChi <= 0)
        {
            printf("\nSo chi khong hop le");
        }
    } while (mh->SoChi <= 0);
}

void XuatMonHoc(MONHOC *mh)
{
    printf("\nTen mon hoc: %s", mh->TenMon);
    printf("\nDiem thi: %f", mh->SoDiem);
    printf("\nSo tin chi: %d", mh->SoChi);
}
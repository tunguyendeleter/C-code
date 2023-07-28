#include "DanhSachMonHoc.h"

void NhapDanhSachMon(DANHSACHMONHOC *ds)
{
    do
    {
        printf("\nNhap so luong mon hoc: ");
        scanf("%d", &(ds->n));
        if (ds->n < 0)
        {
            printf("\nSo luong khong hop le");
        }

    } while (ds->n < 0);
    ds->arr = (MONHOC *)malloc((ds->n) * sizeof(MONHOC));
    for (int i = 0; i < ds->n; i++)
    {
        printf("\n------Nhap vao mon hoc thu %d------", i + 1);
        NhapMonHoc(&ds->arr[i]);
    }
}

void XuatDanhSachMon(DANHSACHMONHOC *ds)
{
    printf("\n------Xuat danh sach mon hoc------");
    for (int i = 0; i < ds->n; i++)
    {
        printf("\nMon thu --- %d", i + 1);
        XuatMonHoc(&ds->arr[i]);
    }
}

#ifndef __SINHVIEN__
#define __SINHVIEN__

#include "DanhSachMonHoc.h"

struct SinhVien
{
    char Ten[50];
    char Maso[10];
    DANHSACHMONHOC *DanhSachMon;
};
typedef struct SinhVien SINHVIEN;

void NhapSinhVien(SINHVIEN *);

void XuatSinhVien(SINHVIEN *);

float TinhDiemTrungBinh(SINHVIEN);

char *Xeploai(SINHVIEN);

#endif
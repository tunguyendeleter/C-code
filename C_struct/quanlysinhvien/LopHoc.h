#ifndef __LOPHOC__
#define __LOPHOC__

#include "SinhVien.h"

struct LopHoc
{
    int n;              // so luong sinh vien
    SINHVIEN *sinhvien; // mang 1 chieu
};
typedef LopHoc LOPHOC;

void NhapLopHoc(LOPHOC *);

void XuatLopHoc(LOPHOC);

void SapXepLopHoc(LOPHOC *, char);

int DemDanhSachHocBong(LOPHOC);

void XuLyHocLai(LOPHOC, int &, float &);

SINHVIEN *TimKiemMaSo(LOPHOC, char *);

void ThemSinhVien(LOPHOC *);

void XoaSinhVien(LOPHOC *, int);

void XoaSinhVienTheoMaSo(LOPHOC *, char *);

void XoaSinhVienRotMon(LOPHOC *);

void CapNhatSinhVienTheoMaSo(LOPHOC *, char *);

float TinhTienHocBong(LOPHOC);

void SapXepSinhVienTheoTen(LOPHOC *);

void ChuanHoaTen(char *ten);

void XoaKyTuTrongTen(char *ten, int vitrixoa);

char *TachTen(char *ten);

#endif
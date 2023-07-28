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

#endif
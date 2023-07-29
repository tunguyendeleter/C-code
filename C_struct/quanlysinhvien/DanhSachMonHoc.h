#ifndef __DANHSACHMONHOC__
#define __DANHSACHMONHOC__

#include "MonHoc.h"

struct DanhSachMonHoc
{
    int n;
    MONHOC *arr;
};
typedef struct DanhSachMonHoc DANHSACHMONHOC;


void NhapDanhSachMon(DANHSACHMONHOC *ds);

void XuatDanhSachMon(DANHSACHMONHOC *ds);


#endif
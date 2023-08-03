#ifndef __DANHSACHCONTHU__
#define __DANHSACHCONTHU__

#include "ConThu.h"

struct DanhSachConThu
{
    int n; // so luong con thu
    CONTHU *conthu;
};
typedef struct DanhSachConThu DANHSACHCONTHU;

void NhapDanhSachConThu(DANHSACHCONTHU *);

void XuatDanhSachConThu(DANHSACHCONTHU);

void LoaiBoConThuBoCuoc(DANHSACHCONTHU *);

void XoaDanhSachConThu(DANHSACHCONTHU *, int);

void SapXepDanhSach(DANHSACHCONTHU *);

void XuatKetQua(DANHSACHCONTHU);

#endif
#ifndef __MONHOC__
#define __MONHOC__

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct MonHoc
{
    char TenMon[30];
    float SoDiem;
    int SoChi;
};
typedef struct MonHoc MONHOC;

void NhapMonHoc(MONHOC *);

void XuatMonHoc(MONHOC *);

#endif
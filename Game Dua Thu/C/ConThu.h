#ifndef __CONTHU__
#define __CONTHU__

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct ConThu
{
    char m_Code[10000]; // ma so
    int m_Speed;        // toc do
    int m_Equipment;    // trang bi (0 - 1)
};
typedef struct ConThu CONTHU;

void NhapConThu(FILE **, CONTHU *);

void XuatConThu(CONTHU);

float TinhThoiGian210km(CONTHU);

void HoanViConThu(CONTHU *, CONTHU *);

#endif
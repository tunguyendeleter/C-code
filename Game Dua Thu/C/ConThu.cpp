#include "ConThu.h"

void NhapConThu(FILE **FileIn, CONTHU *conthu)
{
    fscanf(*FileIn, "%s", &conthu->m_Code);
    fscanf(*FileIn, "%d", &conthu->m_Speed);
    fscanf(*FileIn, "%d", &conthu->m_Equipment);
}

void XuatConThu(CONTHU conthu)
{
    printf("\nMa so: %s", conthu.m_Code);
    printf("\nSpeed: %d", conthu.m_Speed);
    printf("\nEquipment: %d", conthu.m_Equipment);
}

float TinhThoiGian210km(CONTHU conthu)
{
    if (conthu.m_Equipment == 1)
    {
        if (conthu.m_Code[0] == 'L') // SU TU
        {
            conthu.m_Speed *= 2;
        }
        else if (conthu.m_Code[0] == 'R') // THO
        {
            conthu.m_Speed += 30;
        }
        else // RUA
        {
            conthu.m_Speed *= 5;
        }
    }
    if (conthu.m_Code[0] == 'L') // SUTU
    {
        return (float)210 / conthu.m_Speed;
    }
    else if (conthu.m_Code[0] == 'R') // THO
    {
        return ((float)210 / conthu.m_Speed) - 1;
    }
    return ((float)135 / conthu.m_Speed) - 2; // RUA
}

void HoanViConThu(CONTHU *ct1, CONTHU *ct2)
{
    CONTHU tam = *ct1;
    *ct1 = *ct2;
    *ct2 = tam;
}
#include "DanhSachConThu.h"

void NhapDanhSachConThu(DANHSACHCONTHU *ds)
{
    // mo file
    FILE *FileIn;
    FileIn = fopen("INPUT.TXT", "r");
    if (!FileIn)
    {
        printf("\nKhong tim thay thu muc");
        exit(0);
    }
    // doc so luong con thu
    fscanf(FileIn, "%d", &ds->n);
    ds->conthu = (CONTHU *)malloc(ds->n * sizeof(CONTHU));
    // doc thong tin con thu
    for (int i = 0; i < ds->n; i++)
    {
        NhapConThu(&FileIn, &ds->conthu[i]);
    }
    fclose(FileIn);
}

void XuatDanhSachConThu(DANHSACHCONTHU ds)
{
    // duyet danh sach con thu
    printf("\nDANH SACH CON THU");
    for (int i = 0; i < ds.n; i++)
    {
        printf("\n============ Con thu thu %d ============", i + 1);
        XuatConThu(ds.conthu[i]);
    }
}

void LoaiBoConThuBoCuoc(DANHSACHCONTHU *ds)
{
    // duyet danh sach con thu
    for (int i = 0; i < ds->n; i++)
    {
        // kiem tra con thu khong ve dich
        if (TinhThoiGian210km(ds->conthu[i]) > 3) // TINH TU THOI GIAN SU TU BAT DAU XUAT PHAT THOI GIAN CON LAI LA 3 GIO
        {
            XoaDanhSachConThu(ds, i);
            i--;
        }
    }
}

void XoaDanhSachConThu(DANHSACHCONTHU *ds, int vitrixoa)
{
    for (int i = vitrixoa; i < ds->n - 1; i++)
    {
        ds->conthu[i] = ds->conthu[i + 1];
    }
    ds->n--;
    ds->conthu = (CONTHU *)realloc(ds->conthu, ds->n);
}

void SapXepDanhSach(DANHSACHCONTHU *ds)
{
    for (int i = 0; i < ds->n - 1; i++)
    {
        for (int j = i + 1; j < ds->n; j++)
        {
            float num1 = TinhThoiGian210km(ds->conthu[i]);
            float num2 = TinhThoiGian210km(ds->conthu[j]);
            if (num1 > num2)
            {
                HoanViConThu(&ds->conthu[i], &ds->conthu[j]);
            }
        }
    }
    for (int i = 0; i < ds->n - 1; i++)
    {
        float num1 = TinhThoiGian210km(ds->conthu[i]);
        float num2 = TinhThoiGian210km(ds->conthu[i + 1]);
        if (num1 == num2)
        {
            if (strcmp(ds->conthu[i].m_Code, ds->conthu[i + 1].m_Code) < 0)
            {
                HoanViConThu(&ds->conthu[i], &ds->conthu[i + 1]);
            }
        }
    }
}

void XuatKetQua(DANHSACHCONTHU ds)
{
    printf("\n%d", ds.n);
    // duyet tat ca con thu
    for (int i = 0; i < ds.n; i++)
    {
        printf("\n%s", ds.conthu[i].m_Code);
        printf(" %d", ds.conthu[i].m_Speed);
        printf(" %d", ds.conthu[i].m_Equipment);
    }
}

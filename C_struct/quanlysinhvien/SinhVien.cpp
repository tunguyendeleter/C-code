#include "SinhVien.h"

void NhapSinhVien(SINHVIEN *sv)
{
    fflush(stdin);
    printf("\nNhap ho ten: ");
    gets(sv->Ten);
    // printf("\nNhap ma so: ");
    // gets(sv->Maso);
    sv->DanhSachMon = (DANHSACHMONHOC *)malloc(sizeof(DANHSACHMONHOC));
    NhapDanhSachMon(sv->DanhSachMon);
}

void XuatSinhVien(SINHVIEN *sv)
{
    printf("\nHo va Ten: %s", sv->Ten);
    printf("\nMa so: %s", sv->Maso);
    XuatDanhSachMon(sv->DanhSachMon);
    printf("\nDiem trung binh la: %f", TinhDiemTrungBinh(*sv));
}

float TinhDiemTrungBinh(SINHVIEN sv)
{
    float diemtrungbinh = 0;
    int sochia = 0;
    for (int i = 0; i < sv.DanhSachMon->n; i++)
    {
        sochia += sv.DanhSachMon->arr[i].SoChi;
        diemtrungbinh += sv.DanhSachMon->arr[i].SoDiem * sv.DanhSachMon->arr[i].SoChi;
    }
    if (sochia != 0)
    {
        diemtrungbinh /= sochia;
    }
    return diemtrungbinh;
}

char *Xeploai(SINHVIEN sv)
{
    char *kq;
    float diemtrungbinh = TinhDiemTrungBinh(sv);
    if (diemtrungbinh >= 9)
    {
        kq = strdup("XUAT SAC");
        return kq;
    }
    if (diemtrungbinh >= 8)
    {
        kq = strdup("GIOI");
        return kq;
    }
    if (diemtrungbinh >= 7)
    {
        kq = strdup("KHA");
        return kq;
    }
    if (diemtrungbinh >= 5)
    {
        kq = strdup("TRUNG BINH");
        return kq;
    }
    if (diemtrungbinh >= 2)
    {
        kq = strdup("YEU");
        return kq;
    }
    kq = strdup("KEM");
    return kq;
}

void HoanViSinhVien(SINHVIEN *sv1, SINHVIEN *sv2)
{
    SINHVIEN tam;
    tam = *sv1;
    *sv1 = *sv2;
    *sv2 = tam;
}

bool KiemTraSinhVienRotMon(SINHVIEN sv)
{
    for (int i = 0; i < sv.DanhSachMon->n; i++)
    {
        if (sv.DanhSachMon->arr[i].SoDiem < 5)
        {
            return true;
        }
    }
    return false;
}
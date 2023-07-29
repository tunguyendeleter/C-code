#include "LopHoc.h"
#define TIENMOTCHI 120000000
#define KHA 2000000000
#define GIOI 3000000000
#define XUATSAC 3500000000

void NhapLopHoc(LOPHOC *lh)
{
    do
    {
        printf("\nNhap so luong sinh vien: ");
        scanf("%d", &lh->n);
        if (lh->n < 0)
        {
            printf("\nSo luong lop hoc khong hop le");
        }
    } while (lh->n < 0);
    lh->sinhvien = (SINHVIEN *)malloc(lh->n * sizeof(SINHVIEN));
    for (int i = 0; i < lh->n; i++)
    {
        int check;
        printf("\n==========Nhap sinh vien thu %d==========", i + 1);
        // kiem tra bi trung ma so sinh vien
        do
        {
            check = 0;
            fflush(stdin);
            printf("\nNhap ma so: ");
            gets(lh->sinhvien[i].Maso);
            for (int j = 0; j < i; j++)
            {
                if (strcmp(lh->sinhvien[i].Maso, lh->sinhvien[j].Maso) == 0)
                {
                    check = 1;
                    break;
                }
            }
            if (check)
            {
                printf("\nMa so bi trung, vui long nhap lai");
            }
        } while (check);
        NhapSinhVien(&lh->sinhvien[i]);
        ChuanHoaTen(lh->sinhvien[i].Ten);
    }
}

void XuatLopHoc(LOPHOC lh)
{
    for (int i = 0; i < lh.n; i++)
    {
        printf("\n==========Xuat sinh vien thu %d==========", i + 1);
        XuatSinhVien(&lh.sinhvien[i]);
    }
}

void SapXepLopHoc(LOPHOC *lh, char phanloai)
{
    for (int i = 0; i < lh->n - 1; i++)
    {
        for (int j = i + 1; j < lh->n; j++)
        {
            float diemtb1 = TinhDiemTrungBinh(lh->sinhvien[i]);
            float diemtb2 = TinhDiemTrungBinh(lh->sinhvien[j]);
            if (phanloai == 't' || phanloai == 'T')
            {

                if (diemtb1 > diemtb2)
                {
                    HoanViSinhVien(&lh->sinhvien[i], &lh->sinhvien[j]);
                }
            }
            else if (phanloai == 'g' || phanloai == 'G')
            {

                if (diemtb1 < diemtb2)
                {
                    HoanViSinhVien(&lh->sinhvien[i], &lh->sinhvien[j]);
                }
            }
        }
    }
}

int DemDanhSachHocBong(LOPHOC lh)
{
    int dem = 0;
    for (int i = 0; i < lh.n; i++)
    {
        if (!strcmp(Xeploai(lh.sinhvien[i]), "GIOI") || !strcmp(Xeploai(lh.sinhvien[i]), "XUAT SAC"))
        {
            dem++;
        }
    }
    return dem;
}

void XuLyHocLai(LOPHOC lh, int &dem, float &tien)
{
    tien = 0;
    dem = 0;
    // duyet toan bo sinh vien
    for (int i = 0; i < lh.n; i++)
    {
        int check = 0;
        // duyet toan bo danh sach mon hoc
        for (int j = 0; j < lh.sinhvien[i].DanhSachMon->n; j++)
        {
            if (lh.sinhvien[i].DanhSachMon->arr[j].SoDiem < 5)
            {
                check = 1;
                tien += TIENMOTCHI * lh.sinhvien[i].DanhSachMon->arr[j].SoChi;
            }
        }
        if (check == 1)
        {
            dem++;
        }
    }
}

SINHVIEN *TimKiemMaSo(LOPHOC lh, char *MaSo)
{
    for (int i = 0; i < lh.n; i++)
    {
        if (!strcmp(lh.sinhvien[i].Maso, MaSo))
        {
            return &lh.sinhvien[i];
        }
    }
    return NULL;
}

// HAM REALLOC PHAI VIET DAY DU RA =(((
void ThemSinhVien(LOPHOC *lh)
{
    SINHVIEN sv;
    lh->sinhvien = (SINHVIEN *)realloc(lh->sinhvien, (lh->n + 1) * sizeof(SINHVIEN));
    lh->n++;

    fflush(stdin);
    char maso[10];
    printf("\nNhap ma so: ");
    gets(maso);
    strcpy(sv.Maso, maso);
    NhapSinhVien(&sv);
    lh->sinhvien[lh->n - 1] = sv;
}

void XoaSinhVien(LOPHOC *lh, int vitrixoa)
{
    for (int i = vitrixoa; i < lh->n - 1; i++)
    {
        HoanViSinhVien(&lh->sinhvien[i], &lh->sinhvien[i + 1]);
    }
    lh->n--;
    lh->sinhvien = (SINHVIEN *)realloc(lh->sinhvien, (lh->n) * sizeof(SINHVIEN));
}

void XoaSinhVienTheoMaSo(LOPHOC *lh, char *maso)
{
    int dem = -1;
    int check = 0;
    for (int i = 0; i < lh->n; i++)
    {
        dem++;
        if (!strcmp(maso, lh->sinhvien[i].Maso))
        {
            check = 1;
            break;
        }
    }
    if (!check)
    {
        printf("\nSinh vien khong ton tai");
    }
    XoaSinhVien(lh, dem);
}

void XoaSinhVienRotMon(LOPHOC *lh)
{
    // duyet qua danh sach sinh vien trong lop hoc
    for (int i = 0; i < lh->n; i++)
    {
        // kiem tra sinh vien rot
        if (KiemTraSinhVienRotMon(lh->sinhvien[i]))
        {
            XoaSinhVien(lh, i);
            i--;
        }
    }
}

void CapNhatSinhVienTheoMaSo(LOPHOC *lh, char *maso)
{
    // duyet tat ca sinh vien trong lop hoc
    for (int i = 0; i < lh->n; i++)
    {
        // tim sinh vien theo ma so
        if (!strcmp(lh->sinhvien[i].Maso, maso))
        {
            SINHVIEN sv;
            NhapSinhVien(&sv);
            strcpy(sv.Maso, maso);
            lh->sinhvien[i] = sv;
            break;
        }
    }
}

float TinhTienHocBong(LOPHOC sv)
{
    float TienHocBong = 0;
    for (int i = 0; i < sv.n; i++)
    {
        int diemtb = TinhDiemTrungBinh(sv.sinhvien[i]);
        if (diemtb >= 7 && diemtb < 8)
        {
            TienHocBong += KHA;
        }
        else if (diemtb >= 8 && diemtb < 9)
        {
            TienHocBong += GIOI;
        }
        else if (diemtb >= 9)
        {
            TienHocBong += XUATSAC;
        }
    }
    return TienHocBong;
}

void SapXepSinhVienTheoTen(LOPHOC *lh)
{
    // duyet qua tung sinh vien trong lop
    for (int i = 0; i < lh->n - 1; i++)
    {
        for (int j = i + 1; j < lh->n; j++)
        {
            // lay ten tu sinh vien
            char ten1[50], ten2[50];
            strcpy(ten1, TachTen(lh->sinhvien[i].Ten));
            strcpy(ten2, TachTen(lh->sinhvien[j].Ten));
            // so sanh ten
            if (strcmp(ten1, ten2) == 1)
            {
                HoanViSinhVien(&lh->sinhvien[i], &lh->sinhvien[j]);
            }
        }
    }
}

char *TachTen(char *ten)
{
    int len = strlen(ten);
    char *TenDuocTach = (char *)malloc(len * sizeof(char));
    int dem = 0;
    if (len == 1)
    {
        return ten;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        if (ten[i] == ' ')
        {
            for (int j = i + 1; j < len; j++)
            {
                TenDuocTach[dem] = ten[j];
                dem++;
            }
            break;
        }
    }
    TenDuocTach[dem] = '\0';
    return TenDuocTach;
}

void ChuanHoaTen(char *ten)
{
    // khoang trang o dau
    for (int i = 0; i < strlen(ten); i++)
    {
        if (ten[i] == ' ')
        {
            XoaKyTuTrongTen(ten, 0);
            i--;
        }
        else
        {
            if (ten[i] >= 'a' && ten[i] <= 'z')
            {
                ten[i] -= 32;
            }
            break;
        }
    }

    // khoang trang o giua
    for (int i = 1; i < strlen(ten); i++)
    {
        if (ten[i] == ' ' && ten[i + 1] == ' ')
        {
            XoaKyTuTrongTen(ten, i);
            i--;
        }
        if (ten[i] == ' ' && ten[i + 1] != ' ')
        {
            if (ten[i + 1] >= 'a' && ten[i + 1] <= 'z')
            {
                ten[i + 1] -= 32;
            }
        }
    }

    // khoang trang o sau
    if (ten[strlen(ten) - 1] == ' ')
    {
        ten[strlen(ten) - 1] = '\0';
    }
}

void XoaKyTuTrongTen(char *ten, int vitrixoa)
{
    int len = strlen(ten);
    for (int i = vitrixoa; i < len; i++)
    {
        ten[i] = ten[i + 1];
    }
    ten[len - 1] = '\0';
}
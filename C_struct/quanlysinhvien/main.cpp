/*
Viét chong trinh nh4p vao thong tin cia 1 sinh vién, biét rang sinh vién gom co cac
thong tin:
- Ma so

- Ho ten

- Danh sach cac mon hoc trong hoc ky do kém theo so tin chi twong ung

Yéu cau: Tinh diém trung binh & xép loai sinh vién theo quy tac:
Diém trung binh = (diém m6n 1 * so chi cua m6n 1) + (diém m6n 2 * so chi cua mon 2)
+... + ((diém mon n * so chi cua mon n)) / (so chi m6n 1 + so chi m6n 2 + ... + sO chi
mon n)

Xép loai theo nguyén tac
Dtb < 2: Kém
2 <= Dtb <5: Yéu
5 <= Dtb < 7: Trung binh
7 <= Dtb < 8: Kha
8 <= Dtb < 9: Gidi
9 <= Dtb <= 10: XuAt sac
*/

#include "LopHoc.h"

/*
su dung toan tu tham chieu <&> thi <.> de lay phan tu
su dung toan tu con tro <*> thi <->> de lay phan tu
tham chieu = con tro thi phai cap phat con tro
*/

int main()
{

    // char ten[50] = "      Nguyen  ngoc      tu       ";
    // printf("\nTen sau khi chuan hoa:|%s|", TachTen(ten));

    
    LOPHOC *lophoc;
    lophoc = (LOPHOC *)malloc(sizeof(LOPHOC));
    NhapLopHoc(lophoc);

    // printf("\nDANH SACH LOP SAU KHI SAP XEP TANG DAN LA");
    // SapXepLopHoc(lophoc, 't');
    // XuatLopHoc(*lophoc);
    // printf("\nDANH SACH LOP SAU KHI SAP XEP GIAM DAN LA");
    // SapXepLopHoc(lophoc, 'g');
    // XuatLopHoc(*lophoc);
    // int sohocbong = DemDanhSachHocBong(*lophoc);
    // printf("\nSo danh sach nhan hoc bong la: %d", sohocbong);



    // them sinh vien
    // ThemSinhVien(lophoc);
    // XuatLopHoc(*lophoc);



    // xoa sinh vien
    // int vitrixoa;
    // do
    // {
    //     printf("\nNhap vi tri xoa: ");
    //     scanf("%d", &vitrixoa);
    //     if (vitrixoa < 0)
    //     {
    //         printf("\nVi tri xoa khong hop le");
    //     }
    // } while (vitrixoa < 0);
    // XoaSinhVien(lophoc, vitrixoa);
    // printf("\nDANH SACH CAC SINH VIEN SAU KHI XOA");
    // XuatLopHoc(*lophoc);



    // // xoa sinh vien theo ma so
    // int vitrixoa;
    // char masoxoa[10];
    // fflush(stdin);
    // printf("\nNhap ma so sinh vien de xoa: ");
    // gets(masoxoa);
    // XoaSinhVienTheoMaSo(lophoc, masoxoa);
    // printf("\nDANH SACH CAC SINH VIEN SAU KHI XOA");
    // XuatLopHoc(*lophoc);


    
    // // xoa tat ca sinh vien rot mon
    // printf("\nDANH SACH CAC SINH VIEN SAU KHI XOA");
    // XoaSinhVienRotMon(lophoc);
    // XuatLopHoc(*lophoc);



    // // cap nhat lai sinh vien
    // char maso[30];
    // fflush(stdin);
    // printf("\nNhap ma so sinh vien: ");
    // gets(maso);
    // CapNhatSinhVienTheoMaSo(lophoc, maso);
    // printf("\nDANH SACH CAC SINH VIEN SAU KHI CAP NHAT");
    // XuatLopHoc(*lophoc);



    printf("\nDANH SACH CAC SINH VIEN SAU KHI SAP XEP");
    SapXepSinhVienTheoTen(lophoc);
    XuatLopHoc(*lophoc);




    // // tim sinh vien theo ma so
    // SINHVIEN *sv;
    // char maso[30];
    // fflush(stdin);
    // printf("\nNhap ma so sinh vien: ");
    // gets(maso);



    // sv = TimKiemMaSo(*lophoc, maso);
    // if (sv == NULL)
    // {
    //     printf("\nSinh vien khong ton tai");
    // }
    // else
    // {
    //     XuatSinhVien(sv);
    // }

    // giai phong bo nho
    free(lophoc->sinhvien->DanhSachMon->arr);
    free(lophoc->sinhvien->DanhSachMon);
    free(lophoc->sinhvien);
    free(lophoc);

    return 0;
}
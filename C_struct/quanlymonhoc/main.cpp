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

    LOPHOC *lophoc;
    lophoc = (LOPHOC *)malloc(sizeof(LOPHOC));
    NhapLopHoc(lophoc);
    XuatLopHoc(*lophoc);

    free(lophoc->sinhvien->DanhSachMon->arr);
    free(lophoc->sinhvien->DanhSachMon);
    free(lophoc->sinhvien);
    free(lophoc);

    return 0;
}
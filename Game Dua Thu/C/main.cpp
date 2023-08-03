#include "DanhSachConThu.h"

int main()
{

    DANHSACHCONTHU ds;
    NhapDanhSachConThu(&ds);
    LoaiBoConThuBoCuoc(&ds);
    SapXepDanhSach(&ds);
    XuatKetQua(ds);

    return 0;
}
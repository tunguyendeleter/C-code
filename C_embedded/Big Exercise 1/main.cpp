/*
Viết một chương trình quản lý dãy số nguyên với các yêu cầu như sau:
Khi chạy, chương trình sẽ hiện lời giới thiệu “CT Quản lý dãy số” và hiển thị hướng dẫn sử
dụng với các tính năng của chương trình như sau:
-> Dãy số có là 100 phần tử.
-> Giá trị hợp lệ là trong khoảng 1 .. 200.
-> Các phím chức năng:
- Nhập „c‟ hoặc „C‟ để clear data của dãy cũ và cho người dùng nhập dãy mới.
- Nhập „p‟ hoặc „P‟ để in tất cả phần tử của dãy (Nếu dãy chưa có giá trị thì báo dãy
trống).
- Nhập „i‟ hoặc „I‟ để chèn 1 phần tử vào dãy tại vị trí k (nếu có rồi thì không cần chèn vào
nữa).
- Nhập „d‟ hoặc „D‟ để xóa 1 phần tử tại vị trí thứ k (Nếu vị trí k không chứa giá trị thì báo
ko có phần tử ở vị trí k).
- Nhập „f‟ hoặc „F‟ để tìm kiếm 1 giá trị x có trong dãy hay không (x nhập từ bàn phím).
Nếu có thì hiển thị vị trí.
- Nhập „g‟ hoặc „G‟ để in ra màn hình số lớn nhất.
- Nhập „s‟ hoặc „S‟ để in ra màn hình số nhỏ nhất.
- Nhập „q‟ hoặc „Q‟ để thoát chương trình.
Ngoại trừ thao tác q/Q, thì sau khi mỗi thao tác được thực hiện xong, chương trình sẽ xóa
màn hình hoặc xuống dòng (xuống khoảng 4-10 dòng) và chờ người dùng nhập thao tác
tiếp theo để thực hiện.
*/

#include <stdio.h>  /* printf(), scanf() */
#include <conio.h>  /* getch() */
#include <stdlib.h> /* system("cls") */
#define MAX 100
#define true 1
#define false 0

/* hàm kiểm tra lựa chọn: hợp lệ trả về true, không hợp lệ trả về false */
int CheckLuaChon(char luachon)
{
    if (luachon != 'c' && luachon != 'C' && luachon != 'p' && luachon != 'P' && luachon != 'i' && luachon != 'I' && luachon != 'd' && luachon != 'D' && luachon != 'f' && luachon != 'F' && luachon != 'g' && luachon != 'G' && luachon != 's' && luachon != 'S' && luachon != 'q' && luachon != 'Q')
    {
        return false;
    }
    return true;
}

/* hàm kiểm tra trùng lặp, nếu trùng thì true, không trùng thì false */
int CheckTrungLap(int *DanhSachDaySo, int len, int phantu)
{
    for (int i = 0; i < len; i++)
    {
        if (DanhSachDaySo[i] == phantu)
        {
            return true;
        } 
    }
    return false;
}

/* hàm kiểm tra phần tử không hợp lệ từ 1 - 200, nếu không thoả thì true, thoả thì false */
int CheckPhanTuKhongHopLe(int phantu)
{
    if (phantu < 1 || phantu > 200)
    {
        return true;
    }
    return false;
}

/* hàm clear thông tin */
void ClearDaySo(int *DanhSachDaySo)
{
    for (int i = 0; i < MAX; i++)
    {
        DanhSachDaySo[i] = 0;
    }
}

/* hàm tìm x */
void TimPhanTu(int *DanhSachDaySo, int len)
{
    /* nhập x: phần tử cần tim */
    int x;
    do
    {
        printf("\nNhap x: ");
        scanf("%d", &x);
        if (x < 0 || x > 200)
        {
            printf("\nPhan tu khong hop le, vui long nhap lai!");
        }
    } while (x < 0 || x > 200);

    /* tìm x */
    int idx = -1;
    for (int i = 0; i < len; i++)
    {
        if (x == DanhSachDaySo[i])
        {
            idx = i;
            break;
        }
    }

    /* kiểm tra x có tồn tại*/
    if (idx >= 0)
    {
        printf("\nx ton tai: index = %d", idx);
    }
    else
    {
        printf("\nx khong ton tai");
    }
}

/* hàm tìm max */
void TimMax(int *DanhSachDaySo, int len)
{
    int max = DanhSachDaySo[0];
    for (int i = 1; i < len; i++)
    {
        if (max < DanhSachDaySo[i])
        {
            max = DanhSachDaySo[i];
        }
    }
    printf("\nMax = %d", max);
}

/* hàm tìm min */
void TimMin(int *DanhSachDaySo, int len)
{
    int min = DanhSachDaySo[0];
    for (int i = 1; i < len; i++)
    {
        if (min > DanhSachDaySo[i])
        {
            min = DanhSachDaySo[i];
        }
    }
    printf("\nMin = %d", min);
}

/* hàm xoá 1 phần tử trong dãy số có độ dài n: data, kích thước len */
void XoaPhanTu(int *DanhSachDaySo, int *len)
{
    /* kiểm tra dãy số đã empty thi không xoá */
    if (*len == 0)
    {
        printf("\nDanh sach dang empty!");
        return;
    }

    /* nhập vị trí cần xoá k: giới hạn từ [0, len - 1] */
    int k;
    do
    {
        printf("\nNhap vi tri can xoa: ");
        scanf("%d", &k);
        if (k < 0 || k > *len)
        {
            printf("\nVi tri khong hop le, vui long nhap lai!");
        }
    } while (k < 0 || k > *len);

    /* xoá phần tử tại vị trí k */
    for (int i = k; i < *len - 1; i++)
    {
        DanhSachDaySo[i] = DanhSachDaySo[i + 1];
    }
    DanhSachDaySo[*len - 1] = 0;
    (*len)--;
}

/* hàm chèn thêm 1 phần tử vào dãy số có đồ dài n: data, kích thước len*/
void ChenPhanTu(int *DanhSachDaySo, int *len)
{
    /* kiểm tra dãy số đã full thi không chèn */
    if (*len == MAX)
    {
        printf("\nDanh sach dang full!");
        return;
    }

    /* nhập vị trí cần chèn k: giới hạn từ [0, len - 1] */
    int k;
    do
    {
        printf("\nNhap vi tri can chen: ");
        scanf("%d", &k);
        if (k < 0 || k > *len)
        {
            printf("\nVi tri khong hop le, vui long nhap lai!");
        }
    } while (k < 0 || k > *len);

    /* nhập phần tử cần chèn */
    int phantu;
    int checkkhonghople;
    int checktrunglap;
    do
    {
        printf("\nNhap phan tu: ");
        scanf("%d", &phantu);
        checkkhonghople = CheckPhanTuKhongHopLe(phantu);
        checktrunglap = CheckTrungLap(DanhSachDaySo, *len, phantu);
        if (checkkhonghople == true || checktrunglap == true)
        {
            printf("\nPhan tu khong hop le, vui long nhap lai!");
        }
    } while (checkkhonghople == true || checktrunglap == true);

    /* dịch các phần tử sang phải */
    for (int i = *len - 1; i >= k; i--)
    {
        DanhSachDaySo[i + 1] = DanhSachDaySo[i];
    }
    DanhSachDaySo[k] = phantu;
    (*len)++;
}

/* hàm nhập dãy số: data, len */
void NhapDaySo(int *DanhSachDaySo, int *len)
{
    /* clear dãy số*/
    ClearDaySo(DanhSachDaySo);

    /* nhập kích thước dãy số */
    int n;
    do
    {
        printf("\nNhap so luong phan tu: ");
        scanf("%d", &n);
        if (n < 0 || n > MAX)
        {
            printf("\nSo luong phan tu khong hop le vui long nhap lai!");
        }
    } while (n < 0 || n > MAX);

    /* nhập dãy số, phần tử >= 1 và <= 200, các phần tử là duy nhất */
    int i;
    for (i = 0; i < n; i++)
    {
        int checktrunglap;
        int checkkhonghople;
        do
        {
            /* nhập phần tử*/
            printf("\nNhap phan tu thu %d: ", i + 1);
            scanf("%d", &DanhSachDaySo[i]);

            /* nếu phần tử không nằm trong [1, 200] hoặc trùng lặp thì nhập lại */
            checktrunglap = false;
            checkkhonghople = false;
            checktrunglap = CheckTrungLap(DanhSachDaySo, i, DanhSachDaySo[i]);
            checkkhonghople = CheckPhanTuKhongHopLe(DanhSachDaySo[i]);
            if (checkkhonghople == true || checktrunglap == true)
            {
                printf("\nPhan tu khong hop le, yeu cau nhap lai!");
            }
        } while (checkkhonghople == true || checktrunglap == true);
    }
    *len = n;
}

/* hàm xuất thông tin: data, len */
void XuatDaySo(int *DanhSachDay, int len)
{
    int i;
    printf("\nLiet ke phan tu: \n");
    for (i = 0; i < len; i++)
    {
        printf("%d ", DanhSachDay[i]);
    }
}


/* hàm giới thiệu chương trình */
void ChuongTrinh(int *DanhSachDaySo, int len)
{
    /* clear dãy số về 0: không có giá trị */
    ClearDaySo(DanhSachDaySo);
    char luachon;
    while (1)
    {
        luachon = 'q';
        do
        {
            system("cls"); // clear screen
            printf("\n=====================CHUONG TRINH QUAN LY DAY SO=====================");
            printf("\n- Day so se co toi da 100 phan tu");
            printf("\n- Gia tri hop le trong khoang 1 - 200");
            printf("\n- Nhan phim bat ky de tiep tuc");
            printf("\n(1) Nhap (c/C) de clear data va nhap day so moi");
            printf("\n(2) Nhap (p/P) de in ra tat ca cac phan tu");
            printf("\n(3) Nhap (i/I) de chen 1 phan tu vao vi tri thu k(neu co roi khong chen nua)");
            printf("\n(4) Nhap (d/D) de xoa 1 phan tu vao vi tri thu k(neu vi tri k khong co gia tri thi bao khong co)");
            printf("\n(5) Nhap (f/F) de tim 1 phan tu x co trong day hay khong(nhap x tu ban phim)");
            printf("\n(6) Nhap (g/G) de in ra man hinh so lon nhat");
            printf("\n(7) Nhap (s/S) de in ra man hinh so nho nhat");
            printf("\n(8) Nhap (q/Q) de thoat chuong trinh\n");
            if (!CheckLuaChon(luachon))
            {
                printf("\nLua chon khong hop le, moi nhap lai!");
            }
            fflush(stdin); // clear bộ đêm
            printf("\nNhap lua chon: ");
            scanf("%c", &luachon);
        } while (!CheckLuaChon(luachon));

        if (luachon == 'q' || luachon == 'Q')
        {
            break;
        }
        system("cls");
        printf("\n=====================CHUONG TRINH QUAN LY DAY SO=====================");
        if (luachon == 'c' || luachon == 'C')
        {
            printf("\n(1) Nhap (c/C) de clear data va nhap day so moi");
            NhapDaySo(DanhSachDaySo, &len);
        }
        else if (luachon == 'p' || luachon == 'P')
        {
            printf("\n(2) Nhap (p/P) de in ra tat ca cac phan tu");
            XuatDaySo(DanhSachDaySo, len);
        }
        else if (luachon == 'i' || luachon == 'I')
        {
            printf("\n(3) Nhap (i/I) de chen 1 phan tu vao vi tri thu k(neu co roi khong chen nua)");
            ChenPhanTu(DanhSachDaySo, &len);
        }
        else if (luachon == 'd' || luachon == 'D')
        {
            printf("\n(4) Nhap (d/D) de xoa 1 phan tu vao vi tri thu k(neu vi tri k khong co gia tri thi bao khong co)");
            XoaPhanTu(DanhSachDaySo, &len);
        }
        else if (luachon == 'f' || luachon == 'F')
        {
            printf("\n(5) Nhap (f/F) de tim 1 phan tu x co trong day hay khong(nhap x tu ban phim)");
            TimPhanTu(DanhSachDaySo, len);
        }
        else if (luachon == 'g' || luachon == 'G')
        {
            printf("\n(6) Nhap (g/G) de in ra man hinh so lon nhat");
            TimMax(DanhSachDaySo, len);
        }
        else if (luachon == 's' || luachon == 'S')
        {
            printf("\n(7) Nhap (s/S) de in ra man hinh so nho nhat");
            TimMin(DanhSachDaySo, len);
        }
        printf("\n\n\nNhap phim bat ky de thoat!");
        getch(); // pause màn hình
    }
}

int main()
{
    /* khởi tạo dữ liệu chương trình, độ dài tối đa MAX = 100 */
    int DanhSachDaySo[MAX];
    int len = 0;
    ChuongTrinh(DanhSachDaySo, len);

    return 0;
}
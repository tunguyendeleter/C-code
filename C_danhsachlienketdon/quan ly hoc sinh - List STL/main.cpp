/*
nhap xuat danh sach cac hoc sinh trong lop
va tim ra hoc sinh co diém trung binh 1on nhat lép

biet thong tin moi hoc sinh gom:
- ma so     // nhap xuat
- ho tén
- diém toan, ly, hoa    // tinh trung binh  // tim kiem max - th: co nhieu hs diem nhat lon
*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

struct HocSinh
{
    string Hoten;
    string Maso;
    float Toan;
    float Ly;
    float Hoa;
};
typedef struct HocSinh HOCSINH;

void NhapHocSinh(HOCSINH &hs)
{
    fflush(stdin);
    cout << "\nNhap ho ten: ";
    getline(cin, hs.Hoten);
    cout << "\nNhap diem toan: ";
    cin >> hs.Toan;
    cout << "\nNhap diem ly: ";
    cin >> hs.Ly;
    cout << "\nNhap diem hoa: ";
    cin >> hs.Hoa;
}

void XuatHocSinh(HOCSINH hs)
{
    cout << "\nHo ten: " << hs.Hoten;
    cout << "\nMa so: " << hs.Maso;
    cout << "\nDiem toan: " << hs.Toan;
    cout << "\nDiem ly: " << hs.Ly;
    cout << "\nDiem hoa: " << hs.Hoa;
}

float TinhTrungBinh(HOCSINH hs)
{
    return (hs.Ly + hs.Hoa + hs.Toan) / 3;
}

void TimTrungBinhLonNhat(list<HOCSINH> l)
{
    float max = -1;
    for (list<HOCSINH>::iterator it = l.begin(); it != l.end(); it++)
    {
        float diemtrungbinh = TinhTrungBinh(*it);
        if (max < diemtrungbinh)
        {
            max = diemtrungbinh;
        }
    }
    for (list<HOCSINH>::iterator it = l.begin(); it != l.end(); it++)
    {
        float diemtrungbinh = TinhTrungBinh(*it);
        if (max == diemtrungbinh)
        {
            cout << "\n------ Hoc sinh thu " << dem++ << "------";
            XuatHocSinh(*it);
        }
    }
}

bool KiemTraTrung(list<HOCSINH> l, string maso)
{
    for (list<HOCSINH>::iterator it = l.begin(); it != l.end(); it++)
    {
        if (it->Maso == maso)
        {
            return true;
        }
    }
    return false;
}

void NhapDanhSach(list<HOCSINH> &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n------ Nhap hoc sinh thu " << i + 1 << "------";
        HOCSINH hs;
        string maso;
        fflush(stdin);
        do
        {
            cout << "\nNhap ma so: ";
            getline(cin, hs.Maso);
        } while (KiemTraTrung(l, maso));
        NhapHocSinh(hs);
        l.push_back(hs);
    }
}
void XuatDanhSach(list<HOCSINH> l)
{
    int dem = 1;
    for (list<HOCSINH>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "\n------ Hoc sinh thu " << dem++ << "------";
        XuatHocSinh(*it);
    }
}

int main()
{
    list<HOCSINH> l;
    int n;
    do
    {
        cout << "\nNhap so luong hoc sinh: ";
        cin >> n;
        if (n < 0)
        {
            cout << "\nSo luong khong hop le";
        }
    } while (n < 0);
    NhapDanhSach(l, n);
    XuatDanhSach(l);
    cout << "\n=======Hoc sinh co diem trung binh lon nhat=======\n";
    TimTrungBinhLonNhat(l);
    return 0;
}
/*
link đề bài: http://upcoder.xyz/'index.php/867a0909ce3273b7e60efe4873efeef01816c73e32eec3c7132cba87aa8c8021/kuxRI''xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'97'Nh6LAj9OK26A9aPiK-e8dF98i-~4Ph4.'LoyMqlwx7/7c6cf78ed3ad8dcbde3c42d84ef2e994cfc532c3f2d9edb78fbe6a712cf47241
*/
/*
1 2 3 4 5 6 7 8 9  LEN = 9-7 = 2
            M
8 9 1 2 3 4 5 6    LEN = 8-7 = 1
            M
6 8 9 1 2 3 4      LEN = 6-7 = -1
            M
6 8 9 1 2 3     LEN = 6-7 = -1
M
8 9 1 2 3       LEN = 5-7 = -2
  M
1 2 3 8         LEN = 4-7 = -2
    M
8 1 2
M
1 2
M
7 5 4 6 9 3 8 1 2
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void NhapDuLieu(vector<int> &a, int N)
{
    for (int i = 0; i < N; i++)
    {
        a.push_back(i + 1);
    }
}

int main()
{
    ifstream FileIn;
    FileIn.open("INPUT.TXT", ios::in);
    int N, M;
    FileIn.seekg(4, ios_base::cur);
    FileIn >> N;
    FileIn.seekg(6, ios_base::cur);
    FileIn >> M;
    FileIn.close();

    vector<int> DanhSachNguoiChoi;
    vector<int> DanhSachNguoiDuocChon;
    NhapDuLieu(DanhSachNguoiChoi, N);
    int i = 0;
    int dem = 0;
    while (!DanhSachNguoiChoi.empty())
    {
        int len = DanhSachNguoiChoi.size();
        if (i == M - 1 || dem == M - 1)
        {
            DanhSachNguoiDuocChon.push_back(DanhSachNguoiChoi[i]);
            for (int j = 0; j < len - i - 1; j++)
            {
                int temp = DanhSachNguoiChoi.back();
                DanhSachNguoiChoi.pop_back();
                DanhSachNguoiChoi.insert(DanhSachNguoiChoi.begin(), temp);
            }
            DanhSachNguoiChoi.erase(DanhSachNguoiChoi.begin() + len - 1);
            i = 0;
            dem = 0;
        }
        i++;
        dem++;
        if (i == DanhSachNguoiChoi.size())
        {
            i = 0;
        }
    }
    for (int k = 0; k < DanhSachNguoiDuocChon.size(); k++)
    {
        cout << DanhSachNguoiDuocChon[k];
    }

    return 0;
}
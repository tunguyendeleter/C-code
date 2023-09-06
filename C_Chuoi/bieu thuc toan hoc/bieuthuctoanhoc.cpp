#include <iostream>
#include <string>
#include <vector>
using namespace std;

int SUPER_STRCMP(string str1, string str2)
{
    string temp_str1 = str1;
    string temp_str2 = str2;
    int len1 = str1.size();
    int len2 = str2.size();
    int min = len1 < len2 ? len1 : len2;
    int max = len1 > len2 ? len1 : len2;
    if (min == len1)
    {
        for (int i = 0; i < max - min; i++)
        {
            temp_str1 = "0" + temp_str1;
        }
    }
    else
    {
        for (int i = 0; i < max - min; i++)
        {
            temp_str2 = "0" + temp_str2;
        }
    }
    for (int i = 0; i < max; i++)
    {
        if (temp_str1[i] > temp_str2[i])
        {
            return 1;
        }
        else if (temp_str1[i] < temp_str2[i])
        {
            return -1;
        }
    }
    return 0;
}

bool CheckZero(string str)
{
    int len = str.size();
    if (len == 0)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i] != '0')
        {
            return false;
        }
    }
    return true;
}

bool ChuanHoaInput(string &str1, string &str2)
{
    int str1_len = str1.size();
    int str2_len = str2.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;
    for (int i = 0; i < str1_len; i++)
    {
        cnt3 = i;
        if (str1[i] == '.')
        {
            cnt1 = str1_len - i - 1;
            cnt3--;
            break;
        }
    }
    for (int i = 0; i < str2_len; i++)
    {
        cnt4 = i;
        if (str2[i] == '.')
        {
            cnt2 = str2_len - i - 1;
            cnt4--;
            break;
        }
    }
    if (cnt1 == 0 && cnt2 == 0)
    {
        return false;
    }
    int min_cnt = cnt1 < cnt2 ? cnt1 : cnt2;
    int max_cnt = cnt1 > cnt2 ? cnt1 : cnt2;
    if (cnt1 == 0)
    {
        str1 += ".";
    }
    if (cnt2 == 0)
    {
        str2 += ".";
    }

    if (min_cnt == cnt1)
    {
        for (int i = min_cnt; i < max_cnt; i++)
        {
            str1 += "0";
            cnt1++;
        }
    }
    else
    {
        for (int i = min_cnt; i < max_cnt; i++)
        {
            str2 += "0";
            cnt2++;
        }
    }

    int min = cnt3 < cnt4 ? cnt3 : cnt4;
    int max = cnt3 > cnt4 ? cnt3 : cnt4;

    // cout << cnt3 << endl;
    // cout << cnt4 << endl;
    // cout << str1_len << endl;
    // cout << str2_len << endl;
    // cout << min << endl;
    // cout << max << endl;
    if (min == cnt3)
    {
        for (int i = min; i < max; i++)
        {
            str1 = "0" + str1;
        }
    }
    else if (min == cnt4)
    {
        for (int i = min; i < max; i++)
        {
            str2 = "0" + str2;
        }
    }
    return true;
}

void CanBangHaiVe(string &str1, string &str2)
{
    int str1_len = str1.size();
    int str2_len = str2.size();
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < str1_len; i++)
    {
        if (str1[i] == '.')
        {
            for (int j = 0; j < str1_len - i - 1; j++)
            {
                str1[i + j] = str1[i + j + 1];
            }
            str1.erase(str1_len - 1);
            cnt1 = str1_len - i - 1;
            break;
        }
    }
    for (int i = 0; i < str2_len; i++)
    {
        if (str2[i] == '.')
        {
            for (int j = 0; j < str2_len - i - 1; j++)
            {
                str2[i + j] = str2[i + j + 1];
            }
            str2.erase(str2_len - 1);
            cnt2 = str2_len - i - 1;
            break;
        }
    }
    str1_len = str1.size();
    str2_len = str2.size();
    int min = cnt1 < cnt2 ? cnt1 : cnt2;
    int max = cnt1 > cnt2 ? cnt1 : cnt2;
    if (min == cnt1)
    {
        for (int i = min; i < max; i++)
        {
            str1 += "0";
        }
    }
    else
    {
        for (int i = min; i < max; i++)
        {
            str2 += "0";
        }
    }
}

void ReverseString(string &str)
{
    int len = str.size();
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// copy các toán tử và toán hạng vào vector để xử lý
void AddVector(string str, vector<string> &a)
{
    int len = str.size();
    string substr = "";
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            substr += str[i];
        }
        else if (str[i] == ' ')
        {
            a.push_back(substr);
            substr.clear();
        }
        if (i == len - 1)
        {
            a.push_back(substr);
        }
    }
}

/*
  123
-  96
------
   27
3 - 6 = -3
if (-3 < 0)
=> 10+(-3) = 7
=> nho = 1
*/
string PhepTru(string str1, string str2)
{
    int str1_len = str1.size();
    int str2_len = str2.size();
    int min = str1_len < str2_len ? str1_len : str2_len;
    int max = str1_len > str2_len ? str1_len : str2_len;
    if (min == str1_len)
    {
        for (int i = 0; i < max - min; i++)
        {
            str1 = "0" + str1;
        }
    }
    else
    {
        for (int i = 0; i < max - min; i++)
        {
            str2 = "0" + str2;
        }
    }
    bool check = false;
    string temp_str1 = str1;
    string temp_str2 = str2;
    if (str1.compare(str2) < 0)
    {
        temp_str1 = str2;
        temp_str2 = str1;
        check = true;
    }
    int remember = 0;
    string ketqua = "";
    for (int i = max - 1; i >= 0; i--)
    {
        int temp = (temp_str1[i] - 48) - (temp_str2[i] - 48) - remember;
        if (temp < 0)
        {
            ketqua += (10 + temp + 48);
            remember = 1;
        }
        else
        {
            ketqua += (temp + 48);
            remember = 0;
        }
    }
    ReverseString(ketqua);
    if (check == true)
    {
        ketqua = "-" + ketqua;
    }
    return ketqua;
}

string PhepTruThapPhan(string str1, string str2)
{
    string temp_str1 = str1;
    string temp_str2 = str2;
    bool check_input = ChuanHoaInput(temp_str1, temp_str2);
    int str1_len = temp_str1.size();
    int str2_len = temp_str2.size();
    int min = str1_len < str2_len ? str1_len : str2_len;
    int max = str1_len > str2_len ? str1_len : str2_len;
    if (check_input == false)
    {
        if (min == str1_len)
        {
            for (int i = 0; i < max - min; i++)
            {
                temp_str1 = "0" + temp_str1;
            }
        }
        else
        {
            for (int i = 0; i < max - min; i++)
            {
                temp_str2 = "0" + temp_str2;
            }
        }
    }
    bool check = false;
    if (temp_str1.compare(temp_str2) < 0)
    {
        string temp = temp_str1;
        temp_str1 = temp_str2;
        temp_str2 = temp;
        check = true;
    }

    int remember = 0;
    string ketqua = "";
    for (int i = max - 1; i >= 0; i--)
    {
        if (temp_str1[i] == '.')
        {
            ketqua += ".";
            continue;
        }
        int temp = (temp_str1[i] - 48) - (temp_str2[i] - 48) - remember;
        if (temp < 0)
        {
            ketqua += (10 + temp + 48);
            remember = 1;
        }
        else
        {
            ketqua += (temp + 48);
            remember = 0;
        }
    }
    ReverseString(ketqua);
    if (check == true)
    {
        ketqua = "-" + ketqua;
    }
    return ketqua;
}

/*
  123
+ 129
------
  252
3 + 9 = 12
12%10 = 2
12/10 = 1 = nho
*/
string PhepCong(string str1, string str2)
{
    int str1_len = str1.size();
    int str2_len = str2.size();
    int min = str1_len < str2_len ? str1_len : str2_len;
    int max = str1_len > str2_len ? str1_len : str2_len;
    if (min == str1_len)
    {
        for (int i = 0; i < max - min; i++)
        {
            str1 = "0" + str1;
        }
    }
    else
    {
        for (int i = 0; i < max - min; i++)
        {
            str2 = "0" + str2;
        }
    }
    int remember = 0;
    string ketqua = "";
    for (int i = max - 1; i >= 0; i--)
    {
        int temp = (str1[i] - 48) + (str2[i] - 48) + remember;
        ketqua += (temp % 10 + 48);
        remember = temp / 10;
    }
    ReverseString(ketqua);
    return ketqua;
}

string PhepCongThapPhan(string str1, string str2)
{
    string str1_temp = str1;
    string str2_temp = str2;
    bool check_input = ChuanHoaInput(str1_temp, str2_temp);
    int str1_len = str1_temp.size();
    int str2_len = str2_temp.size();
    int min = str1_len < str2_len ? str1_len : str2_len;
    int max = str1_len > str2_len ? str1_len : str2_len;
    if (check_input == false)
    {
        if (min == str1_len)
        {
            for (int i = 0; i < max - min; i++)
            {
                str1_temp = "0" + str1_temp;
            }
        }
        else
        {
            for (int i = 0; i < max - min; i++)
            {
                str2_temp = "0" + str2_temp;
            }
        }
    }
    int remember = 0;
    string ketqua = "";
    for (int i = max - 1; i >= 0; i--)
    {
        if (str1_temp[i] == '.')
        {
            ketqua += ".";
            continue;
        }
        int temp = (str1_temp[i] - 48) + (str2_temp[i] - 48) + remember;
        ketqua += (temp % 10 + 48);
        remember = temp / 10;
    }
    ReverseString(ketqua);
    return ketqua;
}

/*
17*3 => 7*3 = 21
21%10 = 1
21/10 = 2 => nho
     => 1*3 = 3 + nho = 5
*/
string PhepNhan(string str1, string str2)
{
    int len_str1 = str1.size();
    int len_str2 = str2.size();
    int remember = 0;
    string ketqua[len_str2] = "";
    for (int j = 0; j < len_str2; j++)
    {
        for (int i = len_str1 - 1; i >= 0; i--)
        {
            int temp = (str1[i] - 48) * (str2[j] - 48) + remember;
            remember = temp / 10;
            ketqua[j] += ((temp % 10) + 48);
        }
        if (remember > 0)
        {
            ketqua[j] += (remember + 48);
        }
    }
    for (int i = 0; i < len_str2; i++)
    {
        ReverseString(ketqua[i]);
        for (int j = 0; j < len_str2 - i - 1; j++)
        {
            ketqua[i] += "0";
        }
    }
    string ketquacuoi = "0";
    for (int i = 0; i < len_str2; i++)
    {
        ketquacuoi = PhepCong(ketquacuoi, ketqua[i]);
    }
    return ketquacuoi;
}

string PhepNhanThapPhan(string str1, string str2)
{
    string str1_temp = str1;
    string str2_temp = str2;
    int len_str1 = str1_temp.size();
    int len_str2 = str2_temp.size();
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < len_str1; i++)
    {
        if (str1_temp[i] == '.')
        {
            str1_temp.erase(str1_temp.begin() + i);
            cnt1 = len_str1 - i - 1;
            len_str1--;
            break;
        }
    }
    for (int i = 0; i < len_str2; i++)
    {
        if (str2_temp[i] == '.')
        {
            str2_temp.erase(str2_temp.begin() + i);
            cnt2 = len_str2 - i - 1;
            len_str2--;
            break;
        }
    }

    int remember = 0;
    string ketqua[len_str2] = "";
    for (int j = 0; j < len_str2; j++)
    {
        for (int i = len_str1 - 1; i >= 0; i--)
        {
            int temp = (str1_temp[i] - 48) * (str2_temp[j] - 48) + remember;
            remember = temp / 10;
            ketqua[j] += ((temp % 10) + 48);
        }
        if (remember > 0)
        {
            ketqua[j] += (remember + 48);
        }
    }
    for (int i = 0; i < len_str2; i++)
    {
        ReverseString(ketqua[i]);
        for (int j = 0; j < len_str2 - i - 1; j++)
        {
            ketqua[i] += "0";
        }
    }
    string ketquacuoi = "0";
    for (int i = 0; i < len_str2; i++)
    {
        ketquacuoi = PhepCong(ketquacuoi, ketqua[i]);
    }
    if (cnt1 != 0 || cnt2 != 0)
    {
        ketquacuoi.insert(ketquacuoi.size() - cnt1 - cnt2, ".");
    }
    return ketquacuoi;
}

/*
9/4 = 2 du 1
du 1 = 10/4 = 2 du 2
du 2 = 20/4 = 5 du 0
=> 2.25
*/
string PhepChia(string str1, string str2)
{
    int str1_len = str1.size();
    int str2_len = str2.size();
    string sobichia = "";
    string sochia = "";
    string ketqua = "";
    bool first = false;
    for (int i = 0; i < str1_len; i++)
    {
        string heso = "1";
        sobichia += str1[i];
        sochia = PhepNhan(str2, heso);
        bool check = false;
        while (SUPER_STRCMP(sochia, sobichia) <= 0)
        {
            heso[0] += 1;
            sochia = PhepNhan(str2, heso);
            if (SUPER_STRCMP(sochia, sobichia) > 0)
            {
                first = true;
                check = true;
                heso[0] -= 1;
                sochia = PhepTru(sochia, str2);
                sobichia = PhepTru(sobichia, sochia);
                ketqua += heso;
                break;
            }
        }
        if (first == true && check == false)
        {
            ketqua += "0";
        }
    }
    return ketqua;
}

string PhepChiaThapPhan(string str1, string str2, int num)
{
    string str1_temp = str1;
    string str2_temp = str2;
    CanBangHaiVe(str1_temp, str2_temp);
    int str1_len = str1_temp.size();
    int str2_len = str2_temp.size();
    string sobichia = "";
    string sochia = "";
    string ketqua = "";
    bool first = false;
    int i = 0;
    int float_num = 0;
    while (CheckZero(sobichia) == false)
    {
        string heso = "1";
        if (i < str1_len)
        {
            sobichia += str1_temp[i];
        }
        else
        {
            float_num++;
            if (float_num == 1)
            {
                ketqua += ".";
            }
            sobichia += "0";
        }

        sochia = PhepNhan(str2_temp, heso);
        bool check = false;
        while (SUPER_STRCMP(sochia, sobichia) <= 0)
        {
            heso[0] += 1;
            sochia = PhepNhan(str2_temp, heso);
            if (SUPER_STRCMP(sochia, sobichia) > 0)
            {
                first = true;
                check = true;
                heso[0] -= 1;
                sochia = PhepTru(sochia, str2_temp);
                sobichia = PhepTru(sobichia, sochia);
                ketqua += heso;
                break;
            }
        }
        if (first == true && check == false)
        {
            ketqua += "0";
        }
        i++;
        if (float_num == num)
        {
            break;
        }
    }
    return ketqua;
}

void XuLyNhanChia(vector<string> &a)
{
    int len = a.size();
    for (int i = 0; i < len; i++)
    {
        if (a[i] == "*")
        {
            string ketqua = PhepNhan(a[i - 1], a[i + 1]);
            a[i + 1] = ketqua;
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            i--;
        }
        else if (a[i] == "/")
        {
            string ketqua = PhepChia(a[i - 1], a[i + 1]);
            a[i + 1] = ketqua;
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            i--;
        }
        len = a.size();
    }
}

void XuLyCongTru(vector<string> &a)
{
    int len = a.size();
    for (int i = 0; i < len; i++)
    {
        if (a[i] == "+")
        {
            string ketqua = PhepCong(a[i - 1], a[i + 1]);
            a[i + 1] = ketqua;
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            i--;
        }
        else if (a[i] == "-")
        {
            string ketqua = PhepTru(a[i - 1], a[i + 1]);
            a[i + 1] = ketqua;
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            i--;
        }
        len = a.size();
    }
}

void XuLyNhanChiaThapPhan(vector<string> &a)
{
    int len = a.size();
    for (int i = 0; i < len; i++)
    {
        if (a[i] == "*")
        {
            string ketqua = PhepNhanThapPhan(a[i - 1], a[i + 1]);
            a[i + 1] = ketqua;
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            i--;
        }
        else if (a[i] == "/")
        {
            string ketqua = PhepChiaThapPhan(a[i - 1], a[i + 1], 2);
            a[i + 1] = ketqua;
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            i--;
        }
        len = a.size();
    }
}

void XuLyCongTruThapPhan(vector<string> &a)
{
    int len = a.size();
    for (int i = 0; i < len; i++)
    {
        if (a[i] == "+")
        {
            string ketqua = PhepCongThapPhan(a[i - 1], a[i + 1]);
            a[i + 1] = ketqua;
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            i--;
        }
        else if (a[i] == "-")
        {
            string ketqua = PhepTruThapPhan(a[i - 1], a[i + 1]);
            a[i + 1] = ketqua;
            a.erase(a.begin() + i - 1);
            a.erase(a.begin() + i - 1);
            i--;
        }
        len = a.size();
    }
}

int main()
{
    string str = "0.1 + 2.223 * 313.1 - 422 / 0.5";
    vector<string> a;
    AddVector(str, a);
    XuLyNhanChiaThapPhan(a);
    XuLyCongTruThapPhan(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
    // cout << endl;
    // string str1 = "2.2";
    // string str2 = "313";
    // cout << PhepNhanThapPhan(str1, str2);
    // cout << endl;
    // string str3 = "1";
    // string str4 = "688.6";
    // ChuanHoaInput(str3, str4);
    // cout << str3 << endl;
    // cout << str4 << endl;
    // cout << PhepTruThapPhan(str3, str4);
    return 0;
}
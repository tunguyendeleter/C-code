#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
/*
phep cong
8 + 9 + nho = 17 //nho = 0
17%10 = 7
17/10 = 1 = nho
*/

/*
phep tru
5 - 7 => -2
if -2<0
{
    kq = 10 - 2;
    nho = 1;
}
*/

/*
phep nhan
8 * 9 = 72
72%10 = 2
72/10 = 7 = nho

  1234
   123
-------
  3702
 2468
1234
*/

/*
phep chia, lấy phần nguyên
8/3 = 2 du 2
8 - 3*2 = 2
*/

void remove_zero(char *str)
{
    int i = 0;
    while (str[i] == '0')
    {
        bool check = true;
        int len = strlen(str);
        int j;
        for (j = 0; j < len - 1; j++)
        {
            str[j] = str[j + 1];
            check = false;
        }
        str[j] = '\0';
        if (check == true)
        {
            i++;
        }
    }
}

void padding_array(char *str, char key, int position = 0)
{
    int len = strlen(str);
    for (int i = len; i > position; i--)
    {
        str[i] = str[i - 1];
    }
    str[position] = key;
    str[len + 1] = '\0';
}

char *PhepCong(char *str1, char *str2)
{
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int min = len_str1 < len_str2 ? len_str1 : len_str2;
    int max = len_str1 < len_str2 ? len_str2 : len_str1;
    // padding thêm 0 vào trước chữ số nhỏ hơn để 2 só str1 và str2 bằng nhau
    if (min == len_str1)
    {
        for (int i = 0; i < max - min; i++)
        {
            padding_array(str1, '0', 0);
        }
    }
    else
    {
        for (int i = 0; i < max - min; i++)
        {
            padding_array(str2, '0', 0);
        }
    }
    // bao báo array max 100 phần tử chứa kết quả phép toán
    int nho = 0;
    int idx = 0;
    char *ketqua = (char *)malloc(MAX);
    // lưu kết quả theo thứ tự tăng dần
    for (int i = max - 1; i >= 0; i--)
    {
        int temp = (str1[i] - 48) + (str2[i] - 48) + nho;
        ketqua[idx++] = (temp % 10) + 48;
        nho = temp / 10;
    }
    // check nhớ nếu còn thì thêm vào kết quả
    if (nho != 0)
    {
        ketqua[idx++] = nho + 48;
    }
    // add null terminator và đảo lại chuỗi để có kết quả
    ketqua[idx] = '\0';
    strrev(ketqua);
    remove_zero(ketqua);
    return ketqua;
}

char *PhepTru(char *str1, char *str2)
{
    // adding thêm '0' để cân bằng data
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int min = str1_len < str2_len ? str1_len : str2_len;
    int max = str1_len > str2_len ? str1_len : str2_len;
    if (min == str1_len)
    {
        for (int i = min; i < max; i++)
        {
            padding_array(str1, '0', 0);
        }
    }
    else
    {
        for (int i = min; i < max; i++)
        {
            padding_array(str2, '0', 0);
        }
    }
    // thực hiện phép trừ theo từng digit lưu tăng dần
    int idx = 0;
    int nho = 0;
    char *str1_temp = str1;
    char *str2_temp = str2;
    bool check = true;
    if (strcmp(str1, str2) < 0)
    {
        check = false;
        str1_temp = str2;
        str2_temp = str1;
    }
    char *ketqua = (char *)malloc(MAX);
    for (int i = max - 1; i >= 0; i--)
    {
        int temp = (str1_temp[i] - 48) - (str2_temp[i] - 48) - nho;
        if (temp < 0)
        {
            temp = 10 + temp;
            nho = 1;
        }
        else
        {
            nho = 0;
        }
        ketqua[idx++] = temp + 48;
    }
    // add null terminator và đảo lại kết quả
    if (check == false)
    {
        ketqua[idx++] = '-';
    }
    ketqua[idx] = '\0';
    strrev(ketqua);
    remove_zero(ketqua);
    return ketqua;
}

// char *PhepNhan(char *str1, char *str2)
// {
//     // nhân các phần tử của str2 vào str1
//     int str1_len = strlen(str1);
//     int str2_len = strlen(str2);
//     char *ketqua_temp = (char *)malloc(MAX);
//     char *ketqua = (char *)malloc(MAX);
//     ketqua_temp[0] = '0';
//     ketqua_temp[1] = '\0';
//     int idx_str2 = str2_len - 1;
//     int chan = 0;
//     while (idx_str2 >= 0)
//     {
//         int idx = 0;
//         for (int i = str2_len - 1; i >= 0; i--)
//         {
//             int temp = (str1[i] - 48) * (str2[idx_str2] - 48);
//             int le = temp % 10;
//             ketqua[idx++] = le + chan + 48;
//             chan = temp / 10;
//         }
//         ketqua[idx] = '\0';
//         // dịch các digit của kết quả về bên phải
//         for (int i = 0; i < str2_len - idx_str2 - 1; i++)
//         {
//             padding_array(ketqua, '0', 0);
//         }
//         // reverse các digit và add kết quả trước đó và hiện tại
//         strrev(ketqua);
//         ketqua = PhepCong(ketqua, ketqua_temp);
//         memcpy(ketqua_temp, ketqua, sizeof(ketqua));
//         idx_str2--;
//     }
//     return ketqua;
// }

char *PhepNhan(char *str1, char *str2)
{
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    char ketqua[len_str2][MAX];
    for (int k = 0; k < len_str2; k++)
    {
        int idx2 = 0;
        int nho = 0;
        for (int i = len_str1 - 1; i >= 0; i--)
        {
            int temp = (str1[i] - 48) * (str2[k] - 48) + nho;
            ketqua[k][idx2++] = (temp % 10) + 48;
            nho = temp / 10;
        }
        if (nho != 0)
        {
            ketqua[k][idx2++] = nho + 48;
        }
        ketqua[k][idx2] = '\0';
        strrev(ketqua[k]);
    }
    for (int j = len_str2 - 1; j >= 0; j--)
    {
        for (int i = 1; i <= len_str2 - j - 1; i++)
        {
            padding_array(ketqua[j], '0', strlen(ketqua[j]));
        }
    }
    char *ketquacuoi = (char *)malloc(MAX);
    ketquacuoi = ketqua[len_str2 - 1];
    for (int i = len_str2 - 2; i >= 0; i--)
    {
        char *temp = ketquacuoi;
        ketquacuoi = PhepCong(ketquacuoi, ketqua[i]);
        free(temp);
    }
    remove_zero(ketquacuoi);
    return ketquacuoi;
}

char *PhepChia(char *str1, char *str2)
{
    remove_zero(str1);
    remove_zero(str2);
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    char sochia[MAX];
    char *sobichia;
    char *ketqua = (char *)malloc(MAX);
    int idx = 0;
    int idx_ketqua = 0;
    // tìm nhóm chữ số chia lớn hơn số bị chia
    for (int i = 0; i < str1_len; i++)
    {
        // lặp lại đến khi chạm null terminator thì kết thúc
        bool check = false;
        char heso[] = "1";
        sochia[idx++] = str1[i];
        sochia[idx] = '\0';
        if (atoi(sochia) > atoi(str2))
        {
            // tìm hệ số có thể nhân với số bị chia và nhỏ hơn số chia
            while (true)
            {
                check = true;
                char *temp = sobichia;
                sobichia = PhepNhan(heso, str2);
                free(temp);
                if (atoi(sobichia) > atoi(sochia))
                {
                    char *temp = sobichia;
                    sobichia = PhepTru(sobichia, str2);
                    free(temp);
                    heso[0] -= 1;
                    break;
                }
                else if (atoi(sobichia) == atoi(sochia))
                {
                    break;
                }
                heso[0] += 1;
            }
            // tìm số bị dư, trừ số chia với số bị chia
            if (check == true)
            {
                char *temp = PhepTru(sochia, sobichia);
                strcpy(sochia, temp);
                free(temp);
                ketqua[idx_ketqua++] = heso[0];
                ketqua[idx_ketqua] = '\0';
                idx = strlen(sochia);
            }
        }
    }
    return ketqua;
}

int main()
{
    char str1[MAX] = "123456789123123";
    char str2[MAX] = "25533";
    char *ketqua = PhepCong(str1, str2);
    printf("\n%s + %s =  %s", str1, str2, ketqua);
    free(ketqua);
    ketqua = PhepTru(str1, str2);
    printf("\n%s - %s =  %s", str1, str2, ketqua);
    free(ketqua);
    ketqua = PhepNhan(str1, str2);
    printf("\n%s * %s =  %s", str1, str2, ketqua);
    free(ketqua);
    ketqua = PhepChia(str1, str2);
    printf("\n%s / %s =  %s", str1, str2, ketqua);
    free(ketqua);
    return 0;
}

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
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
phep chia
8/3 = 2 du 2
8 - 3*2 = 2
*/

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

char *phepcong(char *str1, char *str2)
{
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int min = len_str1 < len_str2 ? len_str1 : len_str2;
    int max = len_str1 < len_str2 ? len_str2 : len_str1;
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
    int nho = 0;
    int idx = 0;
    char *ketqua = (char *)malloc(MAX);
    for (int i = max - 1; i >= 0; i--)
    {
        int temp = (str1[i] - 48) + (str2[i] - 48) + nho;
        ketqua[idx++] = (temp % 10) + 48;
        nho = temp / 10;
    }
    if (nho != 0)
    {
        ketqua[idx++] = nho + 48;
    }

    ketqua[idx] = '\0';
    strrev(ketqua);
    return ketqua;
}

char *pheptru(char *str1, char *str2)
{
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int min = len_str1 < len_str2 ? len_str1 : len_str2;
    int max = len_str1 < len_str2 ? len_str2 : len_str1;
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
    int nho = 0;
    char *ketqua = (char *)malloc(MAX);
    int idx = 0;
    int check = 0;
    char *str1_temp = str1;
    char *str2_temp = str2;
    if (atoi(str1_temp) < atoi(str2_temp))
    {
        str1_temp = str2;
        str2_temp = str1;
        check = 1;
    }
    for (int i = max - 1; i >= 0; i--)
    {
        int temp = (str1_temp[i] - 48) - (str2_temp[i] - 48) - nho;
        if (temp < 0)
        {
            ketqua[idx++] = (10 + temp) + 48;
            nho = 1;
        }
        else
        {
            ketqua[idx++] = temp + 48;
            nho = 0;
        }
    }
    ketqua[idx] = '\0';
    strrev(ketqua);
    if (check == 1)
    {
        padding_array(ketqua, '-', 0);
        idx++;
    }
    return ketqua;
}

char *phepnhan(char *str1, char *str2)
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
        ketquacuoi = phepcong(ketquacuoi, ketqua[i]);
    }
    printf("\nKet qua phep nhan: %s", ketquacuoi);
    return ketquacuoi;
}
void catchuoi(char *str, char *buffer, int start, int end)
{
    int idx = 0;
    for (int i = start; i < end; i++)
    {
        buffer[idx++] = str[i];
    }
    buffer[idx] = '\0';
    printf("\nSo duoc thay doi: %s", buffer);
}
void timthuong(char *str1, char *str2)
{
    int len = strlen(str2);
    char sochia[MAX];
    char bichia[MAX];
    catchuoi(str1, sochia, 0, len);
    strcpy(bichia, str2);
    char dem[MAX] = "0";
    while (atoi(sochia) > atoi(bichia))
    {
        strcpy(dem, phepcong(dem, (char *)"1"));
        strcpy(bichia, phepnhan(str2, dem));
    }
    if (atoi(sochia) < atoi(bichia))
    {
        strcpy(dem, pheptru(dem, (char *)"1"));
        strcpy(bichia, phepnhan(str2, dem));
    }
    
    printf("\nDEM %s", dem);
    printf("\nsochia %s", sochia);
    printf("\nbichia %s", bichia);
    printf("\ntru %s", strcpy(sochia, pheptru(sochia, bichia)));
}
void phepchia(char *str1, char *str2)
{
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    char str1_temp[MAX];
    char str2_temp[MAX];
    int i;
    int start = 0;
    int end = len_str2;
    catchuoi(str1, str1_temp, start, end);
    strcpy(str2_temp, str2);
    char ketqua[MAX];
    int idx = 0;
    while (str1[end] != '\0')
    {
        int check = 0;
        int dem = 0;
        char *temp = (char *)malloc(MAX);
        temp = str2_temp;
        while (str1_temp < temp)
        {
            dem++;
            check = 1;
            temp = phepcong(temp, str2);
            printf("\nSo duoc thay doi: %d", temp);
        }
        if (check == 1)
        {
            ketqua[idx] = dem + 48;
            start++;
            idx++;
        }
        free(temp);
        end++;
        catchuoi(str1, str1_temp, start, end);
    }
}

int main()
{
    char str1[MAX] = "99";
    char str2[MAX] = "2";
    // padding_array(str, '0', 0);
    // printf("\nSo duoc thay doi: %s", phepcong(str1, str2));
    // phepchia(str1, str2);
    timthuong(str1, str2);
    // printf("\nSo duoc thay doi: %s", str1);
    // catchuoi(str1, str2, 0, 5);
    // printf("\nSo duoc thay doi: %p", str2);

    // phepnhan(str1, str2);
    return 0;
}

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <Windows.h>
#include <math.h>

int STRLEN(char *str)
{
    int dem = 0;
    while (str[dem++] != '\0')
    {
    }
    return dem - 1;
}

char *STRCPY(char *str1, char *str2)
{
    int len = STRLEN(str2);
    for (int i = 0; i < len; i++)
    {
        str1[i] = str2[i];
    }
    str1[len] = '\0';
    return str1;
}

char *STRDUP(char *str)
{
    int len = STRLEN(str);
    char *s = (char *)malloc(len + 1); // cap phat bo nho con tro
    return STRCPY(s, str);
}

char *STRUPR(char *str)
{
    int len = STRLEN(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    return str;
}
char *STRLWR(char *str)
{
    int len = STRLEN(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    return str;
}

void hoanvi(char &s1, char &s2)
{
    s1 = s1 + s2;
    s2 = s1 - s2;
    s1 = s1 - s2;
}

char *STRREV(char *str)
{
    int len = STRLEN(str);
    for (int i = 0; i < len / 2; i++)
    {
        hoanvi(str[i], str[len - i - 1]);
    }
    return str;
}

int STRCMP(char *str1, char *str2)
{
    int len = STRLEN(str1) < STRLEN(str2) ? STRLEN(str1) : STRLEN(str1);
    for (int i = 0; i < len; i++)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    if (str1[len] == '\0')
    {
        if (str2[len] != '\0')
        {
            return -1;
        }
    }
    if (str2[len] == '\0')
    {
        if (str1[len] != '\0')
        {
            return 1;
        }
    }
    return 0;
}

int STRICMP(char *str1, char *str2)
{
    char *s1 = STRLWR(str1);
    char *s2 = STRLWR(str2);
    return STRCMP(s1, s2);
}

char *STRCAT(char *str1, char *str2)
{
    int len_str1 = STRLEN(str1);
    int len_str2 = STRLEN(str2);
    int idx = 0;
    for (int i = len_str1; i < len_str1 + len_str2; i++)
    {
        str1[i] = str2[idx++];
    }
    str1[len_str1 + len_str2] = '\0';
    return str1;
}

void SET_COLOR(int color)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
void STRSTR(char *str1, char *str2)
{
    int len1 = STRLEN(str1);
    int len2 = STRLEN(str2);
    int arr[100];
    int idx = 0;
    for (int i = 0; i < len1; i++)
    {
        int check = 0;
        if (str1[i] == str2[0])
        {
            int j;
            check = 1;
            for (j = 1; j < len2; j++)
            {
                if (str1[j + i] == str2[j])
                {
                    check = 1;
                }
                else
                {
                    check = 0;
                    break;
                }
            }
            if (check == 1)
            {
                arr[idx++] = i;
            }
        }
    }
    idx = 0;
    for (int i = 0; i < len1; i++)
    {
        if (i == arr[idx])
        {
            SET_COLOR(14);
        }
        if (i == arr[idx] + len2)
        {
            SET_COLOR(7);
            idx++;
        }
        printf("%c", str1[i]);
    }
}

int ATOI(char *str)
{
    int len = STRLEN(str);
    int dem = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            dem++;
        }
        else
        {
            break;
        }
    }
    int ketqua = 0;
    int idx = 0;
    for (int i = dem - 1; i >= 0; i--)
    {
        ketqua += (str[idx++] - 48) * powf(10.0, i);
    }
    return ketqua;
}

double ATOF(char *str)
{
    int len = STRLEN(str);
    int phanle = 0;
    int phanchan = 0;
    int check = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (check == 0)
            {
                phanchan++;
            }
            else
            {
                phanle++;
            }
        }
        else if (str[i] == '.')
        {
            check = 1;
        }
    }
    double ketqua = 0;
    double ketquale = 0;
    int idx = 0;
    for (int i = phanchan - 1; i >= 0; i--)
    {
        ketqua += (str[idx++] - 48) * powf(10.0, i);
        printf("\nPhan le : %lf", ketqua);
    }
    idx++;
    for (int i = phanle - 1; i >= 0; i--)
    {
        ketquale += (str[idx++] - 48) * powf(10.0, i);
        printf("\nPhan le : %lf", ketquale);
    }
    return ketqua + (ketquale / powf(10.0, phanle));
}

int main()
{
    char str[100] = "nguyen ngoc tu ngoc hello world";
    char str1[] = "ngoc";
    // printf("\nChuoi co do dai la: %d", STRLEN(str));
    // char *s1 = STRDUP(str);
    // printf("\nChuoi dup la: %s", s1);
    // printf("\nChuoi sau upter: %s", STRUPR(str));
    // printf("\nChuoi sau lower: %s", STRLWR(str));
    // printf("\nChuoi sau khi revert: %s", STRREV(str));
    // printf("\n%d", STRICMP(str, str1));
    // printf("\nChuoi duoc tim thay tai: %d", STRSTR(str, str1));
    // STRSTR(str, str1);
    char str_dem[100] = "123456789.123456189";
    // ATOI(str_dem);
    printf("\nSo vua nhap: %lf", ATOF(str_dem));
    return 0;
}
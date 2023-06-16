#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50
void doithanhchuthuong(char str[MAX])
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] > 64 && str[i] < 91)
        {
            str[i] += 32;
        }
    }
    return;
}

void doithanhchuhoa(char str[MAX])
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] > 96 && str[i] < 123)
        {
            str[i] -= 32;
        }
    }
    return;
}

void cacchucaidauhoa(char str[MAX])
{
    if (str[0] > 96 && str[0] < 123)
    {
        str[0] -= 32;
    }

    for (int i = 1; i < strlen(str); i++)
    {
        if ((str[i] > 96 && str[i] < 123) && str[i - 1] == ' ')
        {
            str[i] -= 32;
        }
    }
}

void xoakhoangtrang(char str[MAX])
{
    int i, j;
    for (i = 0, j = 0; i < strlen(str); i++)
    {
        if ((str[i] != ' ') || (str[i - 1] != ' ' && i > 0))
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

int demtu(char str[MAX])
{
    int dem = 0;
    for (int i = 1; i <= strlen(str); i++)
    {
        if ((str[i] == ' ' || str[i] == '\0') && str[i - 1] != ' ')
        {
            dem++;
        }
    }
    return dem;
}

void inturacacdong(char str[MAX])
{
    int dem = demtu(str);
    char *s = strtok(str, " ");
    printf("\n%s", s);
    for (int i = 0; i < dem - 1; i++)
    {
        char *s2 = strtok(NULL, " ");

        printf("\n%s", s2);
    }
}
int inturacacdong2(char str[MAX])
{
    int check = 0;
    int dem = 0;
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (str[i] != ' ')
        {
            printf("%c", str[i]);
        }

        if (str[i] != ' ' && str[i + 1] == ' ')
        {
            printf("\n");
        }
    }
    if (str[strlen(str)] != ' ')
    {
        printf("%c", str[strlen(str) - 1]);
    }

    return dem;
}
void timtudainhat(char str[MAX])
{
    int dem = demtu(str);
    char *s = strtok(str, " ");
    int max = strlen(s);
    char *strmax = s;
    for (int i = 0; i < dem - 1; i++)
    {
        char *s2 = strtok(NULL, " ");
        if (max < strlen(s2))
        {
            max = strlen(s2);
            strmax = s2;
        }
    }
    printf("\n%s", strmax);
}

void trichnkytutaivitrichotruoc(char str[MAX], int n, char dau = 'd')
{
    char *s = strtok(str, "");
    printf("\n%s", s);
    char *str2;
    char *str3;
    if (dau == 'd')
    {
        for (int i = 0; i < n; i++)
        {
            str2 = strtok(NULL, " ");
        }
        char *str3 = strstr(str, str2);
    }
    if (str3 != NULL)
    {
        printf("\n%s", str3);
    }

    // else if (dau == 'c')
    // {

    //     for (int i = 0; i < n; i++)
    //     {
    //         char *str2 = strtok(NULL, " ");
    //     }
    // }
}

int main()
{
    char str[MAX];
    printf("\nNhap chuoi: ");
    gets(str);
    // printf("\nChuoi sau khi thay doi");
    // cacchucaidauhoa(str);
    // xoakhoangtrang(str);
    // printf("\n%s", str);
    // printf("\nChuoi co so luong tu: %d", demtu(str));
    // inturacacdong(str);
    // timtudainhat(str);
    // trichnkytutaivitrichotruoc(str, 5, 'd');
    printf("\ndem tu: %d", inturacacdong2(str));

    return 0;
}
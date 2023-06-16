#include <stdio.h>
#include <string.h>
#define MAX 100

void nhapchuoi(char str[MAX])
{
    fflush(stdin);
    printf("\nNhap chuoi: ");
    gets(str);
}
void cackytudautienthanhhoa(char str[MAX])
{
    int i = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            if (str[i] > 96 && str[i] < 123)
            {
                str[i] -= 32;
                break;
            }
        }
    }

    while (i < strlen(str) - 1)
    {
        if (str[i] == ' ' && (str[i + 1] > 96 && str[i + 1] < 123))
        {
            str[i + 1] -= 32;
        }
        i++;
    }
}

void hoanvi(char &kytu1, char &kytu2)
{
    kytu1 = kytu1 + kytu2;
    kytu2 = kytu1 - kytu2;
    kytu1 = kytu1 - kytu2;
}
void chuanhoachuoi(char str[MAX])
{
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' || (i > 0 && str[i-1] != ' ')) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
int main()
{
    char str[MAX];
    nhapchuoi(str);
    printf("\nChuoi truoc khi duoc xu ly:\n");
    puts(str);
    printf("\nChuoi sau khi duoc xu ly:");
    cackytudautienthanhhoa(str);
    chuanhoachuoi(str);
    printf("\n%s", str);
    return 0;
}
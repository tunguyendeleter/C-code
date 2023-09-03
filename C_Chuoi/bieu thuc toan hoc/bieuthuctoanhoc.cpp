#include <stdio.h>
#include <conio.h>
// #include <string.h>

int STRLEN(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

float PhepNhan(char *a, char *b)
{
    if ()
    {
        /* code */
    }
    
}

void TimToanTu(char *str, int i)
{
    int start = i;
    int stop = i;
    while (str[start] >= '0' && str[start] <= '9')
    {
        start--;
    }
    while (str[stop] >= '0' && str[stop] <= '9')
    {
        stop++;
    }
    
}

void XuLyNhanChiaTruoc(char *str)
{
    int len = STRLEN(str);
    for (int i = 1; i < len - 2; i++)
    {
    }
}

int main()
{
    char str[] = " ";
    printf("\nDo dai cua string: %d", STRLEN(str));
    return 0;
}
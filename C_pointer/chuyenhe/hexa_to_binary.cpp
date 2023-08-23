#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/*
hexa -> decimal -> binary
hex to decimal:
0xFA = 16^1*F + 16^0*A
0xFA = 16*15 + 1*10
0xFA = 250
hex to decimal:
250 / 2 = 125 du 0
125 / 2 = 62 du 1
62  / 2 = 31 du 0
31  / 2 = 15 du 1
15  / 2 = 7 du 1
7   / 2 = 3 du 1
3   / 2 = 1 du 1
1   / 2 = 0 du 1
=> binary = 11111010 doc nguoc lai => stack
*/

int POW(int heso, int coso)
{
    if (coso == 0)
    {
        return 1;
    }
    else if (coso == 1)
    {
        return heso;
    }
    int sonhan = heso;
    for (int i = 1; i < coso; i++)
    {
        heso *= sonhan;
    }
    return heso;
}

int HexSangDecimal(char *hex)
{
    int idx = 0;
    int len = strlen(hex);
    int tong = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        char so = hex[i];
        if (so >= 'A')
        {
            so = so - 'A' + 10;
        }
        else
        {
            so -= '0';
        }
        tong += POW(16, idx) * so;
        idx++;
    }
    return tong;
}

char *DecimalSangBinary(int decimal)
{
    int stack[100];
    int stack_idx = 0;
    while (decimal != 0)
    {
        stack[stack_idx] = decimal % 2;
        decimal /= 2;
        stack_idx++;
    }
    char *str = (char *)malloc(100 * sizeof(char));
    int idx = 0;
    for (int i = stack_idx - 1; i >= 0; i--)
    {
        str[idx] = stack[i] + 48;
        idx++;
    }
    str[idx] = '\0';
    return str;
}

int DemSoMot(int decimal)
{
    int stack[100];
    int stack_idx = 0;
    while (decimal != 0)
    {
        stack[stack_idx] = decimal % 2;
        decimal /= 2;
        stack_idx++;
    }
    int count = 0;
    for (int i = stack_idx - 1; i >= 0; i--)
    {
        if (stack[i] == 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char str[10] = "AF";
    int decimal = HexSangDecimal(str);
    char *binary = DecimalSangBinary(decimal);
    printf("\ndecimal = %d", decimal);
    printf("\nbinary = %s", binary);
    printf("\nSo 1 trong binary = %d", DemSoMot(decimal));
    return 0;
}
#include <stdio.h>
#include <conio.h>

int main()
{
    for (int i = 10; i <= 99; i++)
    {
        int hangchuc = i / 10;
        int hangdonvi = i % 10;
        if (hangchuc * hangdonvi == 2 * (hangchuc + hangdonvi))
        {
            printf("\n%d", i);
        }
    }

    getch();
    return 0;
}
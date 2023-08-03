/*
S(n) = 1 + 1/3 + 1/5 +...+ 1/(2n + 1)
S(n) = S(n-1) + 1/(2n + 1)
S(3) = S(2) + 1/(2*3 + 1)
S(2) = S(1) + 1/(2*2 + 1)
S(1) = S(0) + 1/(2*1 + 1)
S(1) = 1
*/

#include <stdio.h>
#include <conio.h>

double TinhDeQuy(int n)
{
    // dieu kien dung
    if (n == 0)
    {
        return 1;
    }
    // de quy
    return (double)1 / (2 * n + 1) + TinhDeQuy(n - 1);
}

int main()
{
    printf("\nS(n) = %lf", TinhDeQuy(5));
    return 0;
}
/*
S(n) = 1/(1*2) + 1/(2*3) +...+ 1/n*(n + 1)
S(n) = S(n-1) + 1/n*(n + 1)
S(3) = S(2) + 1/(3*4)
S(2) = S(1) + 1/(2*3)
S(1) = S(0) + 1/(1*2)
S(0) = 0
*/

#include <stdio.h>
#include <conio.h>

double TinhDeQuy(int n)
{
    // dieu kien dung
    if (n == 0)
    {
        return 0;
    }
    // de quy
    return (double)1/(n*(n + 1)) + TinhDeQuy(n - 1);
}

int main()
{
    printf("\nS(n) = %lf", TinhDeQuy(3));
    return 0;
}
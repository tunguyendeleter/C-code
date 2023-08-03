#include <stdio.h>
#include <conio.h>

int Fibonacci_n(int n)
{
    // dieu kien dung
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // hanh dong de quy
    return Fibonacci_n(n - 2) + Fibonacci_n(n - 1);
}

int main()
{
    printf("\nFibonacci cua so 7 la: %d", Fibonacci_n(7));
    return 0;
}
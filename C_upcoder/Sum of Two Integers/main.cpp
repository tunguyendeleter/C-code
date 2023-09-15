#include <iostream>
using namespace std;
#include <bitset>

/*
link đề bài: https://leetcode.com/problems/sum-of-two-integers/
*/

int getSum(int a, int b)
{
    while (b != 0)
    {
        int carry = a & b;
        a = a ^ b;
        b = (unsigned)carry << 1;
    }
    return a;
}

int main()
{


    cout << getSum(-2, 10);
    return 0;
}
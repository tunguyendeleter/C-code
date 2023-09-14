#include <iostream>
using namespace std;

/*
link đề bài: https://leetcode.com/problems/reverse-bits/
*/

uint32_t reverseBits(uint32_t n)
{
    uint32_t num = 0;
    int i = 32;
    while (i--)
    {
        int temp = n & 1;
        num |= (temp << i);
        n >>= 1;
    }
    return num;
}

int main()
{
    cout << reverseBits(0b00000010100101000001111010011100);
    return 0;
}
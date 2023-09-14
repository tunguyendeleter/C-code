#include <iostream>
using namespace std;

// int hammingWeight(uint32_t n)
// {
//     uint32_t num = n;
//     int dem = 0;
//     while (num > 0)
//     {
//         int x = num & 1;
//         dem += x;
//         num >>= 1;
//     }
//     return dem;
// }

int hammingWeight(uint32_t n)
{
    uint32_t num = n;
    int dem = 0;
    while (num > 0)
    {
        dem += 1;
        num &= (num - 1);
    }
    return dem;
}

int main()
{
    cout << hammingWeight(0b10101);
    return 0;
}
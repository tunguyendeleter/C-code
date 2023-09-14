#include <iostream>
#include <vector>
using namespace std;

/*
link đề bài: https://leetcode.com/problems/counting-bits/

N = 7
0: 000 = a[0] = 0
1: 001 = a[1] = 1
2: 010 = a[2] = 0 + a[1] 
3: 011 = a[3] = 1 + a[1]
4: 100 = a[4] = 0 + a[2]
5: 101 = a[5] = 1 + a[2]
6: 110 = a[6] = 0 + a[3]
7: 111 = a[7] = 1 + a[3]
*/

vector<int> countBits(int n)
{
    vector<int> a(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        a[i] = a[i >> 1] + i % 2;
    }
    return a;
}

int main()
{
    vector<int> a = countBits(5);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }

    return 0;
}
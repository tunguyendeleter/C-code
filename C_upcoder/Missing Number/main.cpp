#include <iostream>
using namespace std;
#include <vector>

/*
link đề bài: https://leetcode.com/problems/missing-number/
*/

int missingNumber(vector<int> &nums)
{
    int len = nums.size();
    vector<int> a(len + 1, 1);
    for (int i = 0; i < len; i++)
    {
        a[nums[i]]--;
    }
    for (int i = 0; i <= len; i++)
    {
        if (a[i] == 1)
        {
            return i;
        }
    }
    return -1;
}

int missingNumber(vector<int> &nums)
{
    int len = nums.size();
    long tong = len;
    for (int i = 0; i < len; i++)
    {
        tong += i;
        tong -= nums[i];
    }
    return tong;
}

int missingNumber(vector<int> &nums)
{
    int len = nums.size();
    vector<int> a(len + 1);
    for (int i = 0; i <= len; i++)
    {
        a[i] = i;
    }
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        num ^= a[i] ^ nums[i];
    }
    return num ^ a[len];
}

int main()
{
    // cout << missingNumber();
    return 0;
}
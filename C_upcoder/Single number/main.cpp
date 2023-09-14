/*
link đề bài: https://leetcode.com/problems/single-number/
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int len = nums.size();
    int num = nums[0];
    for (int i = 1; i < len; i++)
    {
        num ^= nums[i];
    }
    return num;
}

int main()
{
    vector<int> nums;
    ifstream FileIn;
    FileIn.open("INPUT.TXT", ios::in);
    if (!FileIn.is_open())
    {
        cout << "\nCannot open the input.txt";
    }
    FileIn.seekg(1, ios::cur);
    while (!FileIn.eof())
    {
        char x;
        int n;
        FileIn >> n;
        FileIn >> x;
        nums.push_back(n);
        if (x == ']')
        {
            break;
        }
    }
    FileIn.close();
    cout << singleNumber(nums);
    return 0;
}
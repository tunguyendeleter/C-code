#include <iostream>
using namespace std;

/*
link đề bài: https://leetcode.com/problems/reverse-integer/
*/

/*
-321 % 10 = -1
-32 % 10 = -2
-3 % 10 = -3
-100 - 20 - 3 = -123
kiểm tra số hạng cuối cùng nếu lớn hoặc bé hơn giới hạn INT32 thì return 0, ngược lại thêm phần tử vào
*/
int reverse(int x)
{
    int a = 0;
    while (x)
    {
        int digit = x % 10;
        x /= 10;
        if (a == INT32_MAX / 10 && digit > 7 || a > INT32_MAX / 10)
        {
            return 0;
        }
        else if (a == INT32_MIN / 10 && digit < -8 || a < INT32_MIN / 10)
        {
            return 0;
        }
        a = a * 10 + digit;
    }

    return a;
}

int main()
{
    cout << reverse(-2147483641);
    return 0;
}
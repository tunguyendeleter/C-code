#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
xài 2 bộ đệm: stack (toán tử), queue (số hạng)
đọc toán tử khác "()", có 2 trường hợp: + - * /
    + toán tử chuẩn bị thêm vào sẽ có độ ưu tiên cao hơn toán tử đầu stack: push toán tử đó vào stack
    + toán tử chuẩn bị thêm vào sẽ có độ ưu tiên thấp hơn toán tử đầu stack:
        lấy lần lượt toán tử từ đầu stack ra
        (cho đến khi hết stack hoặc gặp “(” ) rồi thêm chúng vào queue,
        sau đó nhớ push trả lại “(” và push toán tử mới vào.
Không còn kí tự nào nữa ta sẽ lấy hết những toán tử còn lại trong stack ra và cho vào queue
*/

void XuatStack(stack<char> s)
{
    cout << "\nStack: \n";
    while (!s.empty())
    {
        char x = s.top();
        s.pop();
        cout << x;
    }
}
void XuatQueue(queue<char> q)
{
    cout << "\nQueue: \n";
    while (!q.empty())
    {
        char x = q.front();
        q.pop();
        cout << x;
    }
}

bool CheckUuTien(stack<char> s, char x)
{

    if (!s.empty())
    {
        if (x == '+' || x == '-')
        {
            if (s.top() == '*' || s.top() == '/')
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        return true; // không có phần tử nào => ưu tiên cao
    }
}

void XuLyUuTienThap(stack<char> &s, queue<char> &q, char x)
{
    while (!s.empty())
    {
        if (s.top() == '(')
        {
            break;
        }
        char temp = s.top();
        q.push(temp);
        s.pop();
    }
    s.push(x);
}

void XuLyUuTienCao(stack<char> &s, char x)
{
    s.push(x);
}

void XuLyNgoacDong(stack<char> &s, queue<char> &q)
{
    while (!s.empty())
    {
        if (s.top() == '(')
        {
            s.pop();
            return;
        }
        char temp = s.top();
        s.pop();
        q.push(temp);
    }
}

void KyPhapBaLan(stack<char> &s, queue<char> &q, string str)
{
    int len = str.size();
    // duyệt các phần tử trong string
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        if ((str[i] >= '0' && str[i] <= '9')) // queue: 0 - 9
        {
            q.push(str[i]);
        }
        else if (str[i] == ')')
        {
            XuLyNgoacDong(s, q);
        }
        else // stack: + - * /
        {
            if (str[i] != '(')
            {
                if (CheckUuTien(s, str[i]))
                {
                    XuLyUuTienCao(s, str[i]);
                }
                else
                {
                    XuLyUuTienThap(s, q, str[i]);
                }
            }
            else
            {
                XuLyUuTienCao(s, str[i]);
            }
        }
    }
    while (!s.empty())
    {
        char x = s.top();
        q.push(x);
        s.pop();
    }
}

int main()
{
    stack<char> s;
    queue<char> q;
    string str = "5+((1+2)*4)+3";
    string str2 = "(3 * 4 / (2 + 5)) * (3 + 7)";
    KyPhapBaLan(s, q, str2);
    XuatQueue(q);
    return 0;
}
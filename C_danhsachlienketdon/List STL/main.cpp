#include <iostream>
#include <list>
using namespace std;

void InPut(list<int> &l)
{
    // thêm phần tử vào sau danh sách liên kết
    // push_front() <=> addHead()
    // push_back() <=> addTail()
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);
}
void OutPut(list<int> l)
{
    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << "  ";
    }
}

int main()
{
    list<int> l; // khai báo danh sách liên kết
    InPut(l);
    OutPut(l);
    system("pause");
    return 0;
}
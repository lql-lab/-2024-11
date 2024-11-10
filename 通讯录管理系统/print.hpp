#include <iostream>
using namespace std;

void print(List *list)
{
    if (list -> len == 0)
    {
        cout << "空" << endl;
    }
    else
    {
        for (int i = 0; i < list -> len; i++)
        {
            cout << "姓名" << list -> user[i].name << endl;
            cout << "性别" << list -> user[i].sex << endl;
            cout << endl;
        }
    }
}
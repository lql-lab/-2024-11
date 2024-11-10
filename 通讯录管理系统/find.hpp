# include <iostream>
using namespace std;

void find(List *list, int ret)
{
    if (ret == -1)
    {
        cout << "查无此人" << endl;
        cout << endl;
    }
    else
    {
        cout << "姓名：" << list -> user[ret].name << endl;
        cout << "性别：" << list -> user[ret].sex << endl;
        cout << endl;
    }
}
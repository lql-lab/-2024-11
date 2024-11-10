# include<iostream>
using namespace std;

void add(List *list_p)
{
    if (list_p -> len > MAX)
    {
        cout << "无法添加" << endl;
    }
    else
    {
        cout << "输入姓名：" << endl;
        cin >> list_p -> user[list_p -> len].name;
        cout << endl;
        int raw = 0;
        while (true)
        {
            cout << "输入性别：" << endl;
            cin >> raw;
            if (raw == 1 || raw == 0)
            {
                list_p -> user[list_p -> len].sex;
                list_p -> len ++;
                break;
            }
        }
    } 
}
# include<iostream>
using namespace std;

void redefine(List *list, int ret)
{
    if (ret == -1)
    {
        cout << "查无此人" << endl;
        cout << "1.添加" << endl;
        cout << "0.退出" << endl;
        bool out;
        do
        {
            out = false;
            int select = -1;
            cin >> select;
            switch (select)
            {
                case 1:
                    add(list);
                    break;
                case 0:
                    break;
                default:
                    out = true;
                    cout << "重新输入：" << endl;
                    break;
            }
        }while (out);
    }
    else
    {
        cout << "输入姓名：" << endl;
        cin >> list -> user[ret].name;
        int sex = 0;
        while (true)
        {
            cout << "输入性别：" << endl;
            cin >> sex;
            if (sex == 0 || sex == 1)
            {
                list -> user[ret].sex = sex;
                break;
            }
        }
    }
}
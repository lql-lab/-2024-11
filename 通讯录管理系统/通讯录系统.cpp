# include<iostream>
using namespace std;
# include"menu.hpp"
# define MAX 10000

struct User
{
    string name;
    int sex;
};
struct List
{
    User user[MAX];
    int len;
};
# include"add.hpp"
# include"print.hpp"
# include"is_in.hpp"
# include"del.hpp"
# include"find.hpp"
# include"redefine.hpp"
# include"del_all.hpp"

int main()
{
    List list;
    list.len = 0;
    while (true)
    {
        int select = -1;
        showmenu();
        cout << "请输入：" << endl;
        cin >> select;
        cout << "输入为：" << select << endl;
        cout << endl;
        string use_name;
        int ret = 0;
        bool out;
        switch (select)
        {
            case 0:
                cout << "退出" << endl;
                return 0;
            case 1:
                add(&list);
                break;
            case 2:
                print(&list);
                break;            
            case 3:
                cout << "输入姓名：" << endl;
                cin >> use_name;
                ret = is_in(&list, use_name);
                del(&list, ret);
                break;
            case 4:
                cout << "输入姓名：" << endl;
                cin >> use_name;
                ret = is_in(&list, use_name);
                find(&list, ret);
                break;
            case 5:
                cout << "输入姓名：" << endl;
                cin >> use_name;
                ret = is_in(&list, use_name);
                redefine(&list, ret);
                break;
            case 6:
                cout << "请确认：" << endl;
                cout << "1.继续" << endl;
                cout << "0.退出" << endl;
                do
                {
                    out = false;
                    cout << "请输入：" << endl;
                    cin >> select;
                    switch (select)
                    {
                        case 1:
                            del_all(&list);
                            break;
                        case 0:
                            break;
                        default:
                            out = true;
                            break;
                    }
                }while (out);
                break;
            default:
                cout << "重新输入" << endl;
                break;                                                
        }
    }
}
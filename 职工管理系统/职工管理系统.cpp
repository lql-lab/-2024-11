# include <iostream>
using namespace std;
#include <string>

# include "WM.hpp"
# include "woker.hpp"

int main()
{
    WM wm;
    int choice = 0;
    int name_or_num = 0;
    int num = 0;
    string name;
    while(true)
    {
        wm.show_mune();
        cout << "输入选择：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            wm.quit();
            break;
        case 1:
            wm.add_mans();
            break;
        case 2:
            wm.show_mans();
            break;                    
        case 3:
            cout << "请输入名称或编号" << endl;
            cout << "1.编号\n2.名称" << endl;
            cin >> name_or_num;
            switch (name_or_num)
            {
            case 1:
                cin >> num;
                wm.del_mans(num);
                break;
            case 2:
                cin >> name;
                wm.del_mans(name);
                break;
            default:
                break;
            } 
            break;                
        case 4:
            cout << "请输入名称或编号" << endl;
            cout << "1.编号\n2.名称" << endl;
            cin >> name_or_num;
            switch (name_or_num)
            {
            case 1:
                cin >> num;
                wm.catch_find(num);
                break;
            case 2:
                cin >> name;
                wm.catch_find(name);
                break;
            default:
                break;
            }
            break;
        case 5:
            cout << "请输入名称或编号" << endl;
            cout << "1.编号\n2.名称" << endl;
            cin >> name_or_num;
            switch (name_or_num)
            {
            case 1:
                cin >> num;
                wm.redefine(num);
                break;
            case 2:
                cin >> name;
                wm.redefine(name);
                break;
            default:
                break;
            }
            break;
        case 6:
            wm.sort();
            break;
        case 7:
            cout << "输入1：" << endl;
            cin >> choice;
            if (choice == 1)
            {
                wm.clear();
            }
            break;
        default:
            break;
        }
    }
    return 0;
}
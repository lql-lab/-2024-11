# include <iostream>
using namespace std;

void del_all(List *list)
{
    list -> len = 0;
    cout << "已清空" << endl;
}
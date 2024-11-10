# include <iostream>
using namespace std;

void del(List *list, int ret)
{
    if (ret == -1)
    {
        cout << "查无此人" << endl;
        cout << endl;
    }
    else
    {
        for (int i = ret; i < list -> len; i++)
        {
            list -> user[i] = list -> user[i + 1];
        }
        list -> len --;
    }
}
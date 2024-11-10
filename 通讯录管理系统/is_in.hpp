# include<iostream>
using namespace std;

int is_in(List *list, string name)
{
    int ret = -1;
    for (int i = 0; i < list -> len; i++)
    {
        if (list -> user[i].name == name)
        {
            ret = i;
            break;
        }
    }
    return ret;
}
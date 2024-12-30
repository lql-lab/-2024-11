# include <iostream>

# include <list>

using namespace std;

void print_list(list<int>);

bool reverse_compera(int a, int b)
{
    return a > b;
}

int main()
{
    list<int> int_list(10,0);
    for (int i = 1; ++i < 5;)
    {
        int_list.push_back(i);
    }
    list<int> int_list_copy(int_list.begin(), int_list.end());
    list<int>(10, 1).swap(int_list);
    int_list_copy.assign(5, 0);
    if (int_list.empty())
    {
        int_list.resize(10, 5);
    }
    else
    {
        int_list.resize(5);
    }
    cout << int_list.size() << endl;
    // list删除的操作和vector类似，但可以使用remove按值来删除所有相关元素。
    int_list.remove(0);
    print_list(int_list);
    // list元素访问。
    cout << int_list.front() << "\t" << int_list.back() << endl;
    // list不支持跳跃迭代器，内部会包含一些常用算法。
    int_list.sort(reverse_compera);
    int_list.reverse();
    print_list(int_list);
    return 0;
}

void print_list(list<int> lis)
{
    // list为链表不支持跳跃式访问内部元素，但可以使用it++--进行双向的访问。
    for (list<int>::iterator it = lis.begin(); it != lis.end() ; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

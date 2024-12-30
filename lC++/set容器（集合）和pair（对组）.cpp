# include <iostream>

# include <set>

using namespace std;

class DownCompera
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

void print_set(set<int, DownCompera>&);

int main()
{
    // set内部实现排序，只能使用insert插入元素。
    // 不允许存在同样的元素，insert会返回插入的值和一个bool数表示这个值是否插入成功。
    set<int, DownCompera> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    print_set(s1);
    // 无法改变set的大小。
    if (! s1.empty())
    {
        cout << s1.size() << endl;
    }
    else
    {
        set<int, DownCompera> s2;
        s2.insert(10);
        s2.insert(20);
        s2.insert(30);
        s2.insert(40);
        s2.insert(50);
        s2.swap(s1);
    }
    s1.erase(10);
    s1.erase(s1.begin());
    // 可以使用find查找set的元素，返回指向迭代器。
    if (s1.find(1) == s1.end())
    {
        s1.insert(1);
    }
    // pair可以储存一对数据，可以使用makepair调用默认构造。
    pair<set<int, DownCompera>:: iterator, bool> p(s1.insert(1));
    if (! p.second)
    {
        cout << "fail" << endl;
    }
    cout << s1.count(2) << endl;
    return 0;
}

void print_set(set<int, DownCompera>& s)
{
    // set的迭代器不是可跳跃的。
    for (set<int, DownCompera>:: iterator it = s.begin(); it != s.end() ;++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return;
}


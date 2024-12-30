# include <iostream>

# include <algorithm>
// 双端数组，deque。
# include <deque>

using namespace std;

template < typename T >
void printdeque(const deque < T >&);

int main()
{
    // deque的构造函数，类似于vector。
    deque<int> d(10, 100);
    printdeque(d);
    // deque的赋值，类似于vector。
    d.assign(d.begin(), d.end() - 5);
    // deque的大小方法，类似于vector，由于没有容量上限，故没有cap函数。
    printdeque(d);
    if (! d.empty())
    {
        cout << d.size() << endl;
    }
    else
    {
        d.resize(10,0);
        printdeque(d);
    }
    // deque的插入删除，类似于vector，但具有头插。
    d.push_front(100);
    d.insert(d.end(), 1, 10);
    d.insert(d.end(), d.end() - 1, d.end());
    printdeque(d);
    d.erase(d.end() - 2, d.end());
    // deque元素的访问，类似于vector。
    // 利用sort排序。
    sort(d.begin(), d.end());
    return 0;
}

template < typename T >
void printdeque(const deque < T > &d1)
{
    for (auto it = d1.begin(); it < d1.end() ; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return;
}
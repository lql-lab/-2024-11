# include <iostream>

# include<map>

using namespace std;

int main()
{
    map<int, int> m1;
    m1.insert(make_pair(1,1));
    m1.insert(make_pair(2,2));
    m1.insert(make_pair(3,3));
    m1.insert(make_pair(4,4));
    m1.insert(make_pair(5,5));
    // map功能类似于set但是可以通过迭代器删除元素。
    m1.erase(m1.begin()++, m1.end()--);
    return 0;
}
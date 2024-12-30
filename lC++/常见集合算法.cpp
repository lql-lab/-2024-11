# include <iostream>

# include <algorithm>
# include <vector>
# include <set>

using namespace std;

void print(int i)
{
    cout << i << " ";
    return;
}

int main()
{
    vector<int> v(10, 1);
    set<int> s;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    for (vector<int>::iterator it = v.begin(); it!= v.end(); ++it) {
        s.insert(*it);
    }
    for_each(s.begin(), s.end(), print);
    cout << endl;
    vector<int> v1(10, 1);
    set<int> s1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);   
    for (vector<int>::iterator it1 = v1.begin(); it1!= v1.end(); ++it1) {
        s1.insert(*it1);
    }
    for_each(s1.begin(), s1.end(), print);
    cout << endl;
    vector<int> s2;
    s2.resize(min(s1.size(), s.size()));
    // 交集。
    vector<int>::iterator it_end = set_intersection(s.begin(), s.end(), s1.begin(), s1.end(), s2.begin());
    for_each(s2.begin(), it_end, print);
    cout << endl;
    s2.assign(s2.size(), 0);
    // 差集。
    it_end = set_difference(s.begin(), s.end(), s1.begin(), s1.end(), s2.begin());
    for_each(s2.begin(), it_end, print);
    cout << endl;
    // 并集。
    // it_end = set_union(s.begin(), s.end(), s1.begin(), s1.end(), s2.begin());
    // for_each(s2.begin(), it_end, print);
    // cout << endl;
    return 0;
}
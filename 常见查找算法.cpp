# include <iostream>

# include <vector>
# include <algorithm>

using namespace std;

bool Less_primer(int i)
{
    return i > 1;
}

void print_res(vector<int>:: iterator it, vector<int>& v)
{
    if (it == v.end())
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "find" << *it << endl;
    }
    return;
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 10 ;)
    {
        v.push_back(++i);
    }
    vector<int>::iterator it = find(v.begin(), v.end(), 2);
    print_res(it, v);
    it = find_if(v.begin(), v.end(), Less_primer);
    print_res(it, v);
    it = adjacent_find(v.begin(), v.end());
    print_res(it, v);
    bool ret = binary_search(v.begin(), v.end(), 2);
    cout << ret << endl;
    int num = count(v.begin(), v.end(), 1);
    cout << num << endl;
    num = count_if(v.begin(), v.end(), Less_primer);
    cout << num << endl;
    return 0;
}
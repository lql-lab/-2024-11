# include <iostream>

# include <algorithm>
# include <vector>

using namespace std;

class Myfunc_print
{
public:
    void operator()(int &i)
    {
        cout << i << " ";
    }
};

class Myfunc_for
{
public:
    int i = 0;
    int operator()(int &i)
    {
        this->i++;
        return this->i + i;
    }
};

int main()
{
    vector<int> v(10,0);
    vector<int> v1;
    v1.resize(10, 0);
    // for_each遍历每一个元素。
    for_each(v.begin(), v.end(), Myfunc_print());   
    cout << endl; 
    // transform遍历，储存到另一块空间。
    transform(v.begin(), v.end(), v1.begin(), Myfunc_for());
    for_each(v1.begin(), v1.end(), Myfunc_print());
    cout << endl;
    transform(v.begin(), v.end(), v1.begin(), Myfunc_for());
    for_each(v1.begin(), v1.end(), Myfunc_print());
    return 0;
}
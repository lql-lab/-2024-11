# include <iostream>

// 内建的仿函数库。
# include <functional>
// 含有算数仿函数，关系仿函数（比较），逻辑仿函数（布尔）。
// 例如：puls,mulitiplis,divides,navege,
// equal_to,greater,less,
// logical_and,logical_or...;
# include <algorithm>
# include <vector>

using namespace std;

class MyAdd
{
public:
    int a, b;
    int operator()(int a, int b)
    {
        return a + b;
        this->a = a;
        this->b = b;
    }    
};

class MyCompera
{
public:
// 返回值为布尔类型的仿函数称为谓词。
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

// bool Mycompera(int a, int b)
// {
//     return a < b;
// }

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    sort(v.begin(), v.end(), MyCompera());
    for (vector<int>:: iterator it = v.begin(); it < v.end() ; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
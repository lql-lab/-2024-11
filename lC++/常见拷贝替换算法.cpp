# include <iostream>

# include <algorithm>
# include <vector>
# include <functional>

using namespace std;

class primer
{
public:
    int i = 0;
    void operator()(int &i)
    {
        i += ++this->i;
        return;
    }
};

void print(int i)
{
    cout << i << " ";
}

bool less_equal_5(int i)
{
    return i <= 5;
}

int main()
{
    vector<int> v(10, 0);
    vector<int> v1;
    v1.resize(10, 0);
    for_each(v.begin(), v.end(), primer());
    copy(v.begin(), v.end(), v1.begin());
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    replace(v.begin(), v.end(), 2, 0);
    for_each(v.begin(), v.end(), print);
    cout << endl;
    replace_if(v.begin(), v.end(), less_equal_5, 6);
    for_each(v.begin(), v.end(), print);
    cout << endl;
    swap(v, v1);
}
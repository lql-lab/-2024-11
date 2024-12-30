# include <iostream>

# include <vector>
# include <algorithm>
# include <functional>
# include <ctime>

using namespace std;

class primer
{
public:
    int i = 0;
    void operator()(int& j)
    {
        j += ++this->i + j;
        return;
    }
};

void print(int i)
{
    cout << i << " ";
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<int> v(10, 0);
    for_each(v.begin(), v.end(), primer());
    for_each(v.begin(), v.end(), print);
    cout << endl;
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), print);
    cout << endl;
    sort(v.begin(), v.end(), less_equal<int>());
    for_each(v.begin(), v.end(), print);
    cout << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), print);
    cout << endl;
    return 0;
}
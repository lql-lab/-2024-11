# include <iostream>

# include <numeric>
# include <algorithm>
# include <vector>

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

int main()
{
    vector<int> v(10, 0);
    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), primer());
    cout << accumulate(v.begin(), v.end(), 0) << endl;
    return 0;
}
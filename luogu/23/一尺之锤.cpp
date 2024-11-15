# include <iostream>

using namespace std;

int main()
{
    int len = 0, days = 0;
    cin >> len;
    while (len != 0)
    {
        len /= 2;
        ++days;
    }
    cout << days << endl;
    return 0;
}
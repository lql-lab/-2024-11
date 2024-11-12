# include <iostream>

using namespace std;

int main()
{
    int turns = 1, limit_days = 0, count = 0, sum_value = 0;
    cin >> limit_days;
    for (int i = 0; i < limit_days ; ++i)
    {
        if (count < turns)
        {
            sum_value += turns;
            ++count;
        }
        else
        {
            sum_value += ++turns;
            count = 1;
        }
    }
    cout << sum_value << endl;
    return 0;
}
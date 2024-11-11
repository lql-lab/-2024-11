# include <iostream>

using namespace std;

int main()
{
    int day_num = 0;
    cin >> day_num;
    int result[day_num + 1] = {};
    result[day_num] = 1;
    for (int i = day_num; i > 1 ; --i)
    {
        result[i - 1] = (result[i] + 1) * 2;
    }
    cout << result[1] << endl;
    return 0;
}
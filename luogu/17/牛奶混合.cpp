# include <iostream>
# include <algorithm>

using namespace std;

// 结构体记录每一个任务的价值和资源消耗。
struct  Milk
{
    int pri;
    int num;
};

bool compera(Milk a, Milk b)
{
    return a.pri < b.pri;
}

int main()
{
    int need = 0;
    int p_num = 0;
    cin >> need;
    cin >> p_num;
    Milk milk_p[p_num];
    for (int i = 0 ; i < p_num ; i++)
    {
        cin >> milk_p[i].pri;
        cin >> milk_p[i].num;
    }
    // 快排按照价值密度递减排序。
    sort(milk_p, milk_p + p_num, compera);
    int temp = 0;
    long long sum = 0;
    // 这是一个贪心，重量可以无限细分。
    for(int i = 0 ; i < p_num ; i++)
    {
        if (temp + milk_p[i].num <= need)
        {
            temp += milk_p[i].num;
            sum += milk_p[i].pri * milk_p[i].num;
        }
        else
        {
            sum += (need - temp) * milk_p[i].pri;
            break;
        }
    }
    // 输出最大的总价值。
    cout << sum << endl;
    return 0;
}

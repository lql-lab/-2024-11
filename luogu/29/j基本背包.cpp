# include <iostream>
# include <algorithm>

using namespace std;

struct Bags
{
    double value;
    double weight;
};

bool compera(Bags a, Bags b)
{
    return (a.value / a.weight) > (b.value / b.weight);
}

// 如题，一个最简单的背包。
int main()
{
    int num = 0;
    int use = 0;
    cin >> num;
    cin >> use;
    Bags bag[num];
    for (int i = 0; i < num ; i++)
    {
        cin >> bag[i].weight;
        cin >> bag[i].value;
    }
    sort(bag, bag + num, compera);
    int sum_m = 0;
    double sum_v = 0;
    for (int i = 0; i < num ; i++)
    {
        if (sum_m + bag[i].weight <= use)
        {
            sum_m += bag[i].weight;
            sum_v += bag[i].value;
        }
        else
        {
            sum_v += (use - sum_m) * (bag[i].value / bag[i].weight);
            break;
        }
    }
    printf("%.2f\n",sum_v);
    return 0;
}
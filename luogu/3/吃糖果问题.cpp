# include <iostream>
using namespace std;

int main()
{
    // 初始化。
    int num = 0;
    int use = 0;
    cin >> num;
    cin >> use;
    int candys[num] = {};
    for (int i = 0; i < num ; i++)
    {
        cin >> candys[i];
    }
    long long sum = 0;
    // 贪心求解。
    for (int i = 0; i < num - 1 ; i++)
    {
        // 如果需要吃糖果。
        while (candys[i] + candys[i + 1] > use)
        {
            // 尽可能吃后一颗糖。
            if (candys[i + 1] > 0)
            {
                // 如果后一堆不会消耗完。
                if (candys[i + 1] - ((candys[i + 1] + candys[i]) - use) >= 0)
                {
                    sum += (candys[i + 1] + candys[i]) - use;
                    candys[i + 1] = candys[i + 1] - ((candys[i + 1] + candys[i]) - use);
                }
                else
                {
                    sum += candys[i + 1];
                    candys[i + 1] = 0;
                }
            }
            // 不满足，则吃前一堆。
            else
            {
                sum += candys[i] - use;
                candys[i] = use;
            }
        }
    }
    // 输出总共吃了几颗糖果。
    cout << sum << endl;
    return 0;
}
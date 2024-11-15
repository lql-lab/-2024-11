# include <iostream>
#include <cstdio>

using namespace std;

// 结构体描述了每一个任务的两种收益和资源消耗。
struct Player
{
    int lose;
    int win;
    int wat;
};

int main()
{
    // 任务初始化。
    int num = 0;
    int wat_num = 0;
    cin >> num;
    cin >> wat_num;
    // 输入。
    Player player[num];
    for (int i = 0; i < num ; i++)
    {
        cin >> player[i].lose;
        cin >> player[i].win;
        cin >> player[i].wat;
    }
    // 构建状态方程。
    // 普通的01背包，从前往后递推。
    long long res[wat_num + 1] = {};
    for (int i = 0 ; i < num ; i++)
    {
        for (int j = wat_num ; j >= 0 ; j--)
        {
            if (j >= player[i].wat)
            {
                res[j] = max(res[j] + player[i].lose, res[j - player[i].wat] + player[i].win);
            }
            else
            {
                res[j] = res[j] + player[i].lose;
            }
        }
    }
    // 结果展示。
    cout << (long long)(5 * res[wat_num]) << endl;
    return 0;
}
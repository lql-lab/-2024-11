# include <iostream>

using namespace std;

int main()
{
    // 初始化。
    int num = 0;
    cin >> num;
    int arr[num];
    // 输入。
    for (int i = 0; i < num ;i++)
    {
        cin >> arr[i];
    }
    // 考虑边缘的情况。
    int res = arr[0];
    // 实际是一个动态规划，但是由于一维，状态方程可以简写为这种形式。
    // 原来的转移方程为：
    // if (arr[i] <= arr[i - 1])
    // {
    //     res[i] = res[i - 1];
    // }
    // else
    // {
    //     res[i] = (arr[i] - arr[i - 1]) + res[i - 1];
    // }
    for (int i = 1; i < num ;i++)
    {
        if (arr[i] > arr[i - 1])
        {
            res += (arr[i] - arr[i - 1]);
        }
        // cout << i << '\t' << res << endl;
    }
    // 输出。
    cout << res << endl;
    return 0;
}
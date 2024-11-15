# include <iostream>

using namespace std;

int main()
{
    // 初始化。
    int len;
    cin >> len;
    int arr[len + 1] = {};
    arr[1] = 1;
    // 递推求解。
    for (int i = 1; i <= len; i++)
    {
        int sum = 0;
        // 求解该状态的最优。
        for (int j = 1; j <= i / 2; j++)
        {
            sum += arr[j];
        }
        // 记录。
        arr[i] = sum + 1;
    }
    // 输出目标状态的解。
    cout << arr[len] << endl;
    return 0;
}
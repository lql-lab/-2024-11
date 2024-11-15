# include <iostream>
using namespace std;

int main()
{
    // 初始化。
    int num = 0;
    cin >> num;
    int arr[num + 1][2];
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[i][j] = 0;
        }
    }
    // 状态描述，填好了前几个，是否有凸出的部分。
    // 边界初始化。
    arr[0][0] = 1; arr[0][1] = 0; arr[1][0] = 1; arr[1][1] = 2;
    for (int i = 2; i <= num; i++)
    {
        // 状态转移方程。
        // 由于数字太大，取出后4位。
        arr[i][0] = (arr[i - 1][0] % 10000 + arr[i - 2][1] % 10000 + arr[i - 2][0] % 10000) % 10000;
        arr[i][1] = (2 * arr[i - 1][0] % 10000 + arr[i - 1][1] % 10000) % 10000; 
    }
    // 输出。
    cout << arr[num][0] % 10000 << endl;
    return 0;
}

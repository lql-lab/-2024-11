# include <iostream>

using namespace std;

int main()
{
    // 初始化。
    int len = 0;
    cin >> len;
    int arr[len] = {0,};
    int temp = 0, max = 0;
    // 输入。
    for (int i = 0 ; i < len ; i++)
    {
        cin >> arr[i];
    }
    max = temp = arr[0];
    // 贪心求解。
    for (int i = 1; i < len ; i++)
    {
        // 如果是正数且有机会变大，则不放弃。
        if (temp + arr[i] > 0 && temp > 0)
        {
            temp += arr[i];
        }
        // 否则，放弃当前子列。
        else
        {
            temp = arr[i];
        }
        // 记录最大值。
        if (temp > max)
        {
            max = temp;
        }
    }
    // 输出。
    cout << max << endl;
    return 0;
}
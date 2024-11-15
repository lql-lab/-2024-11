# include <iostream>

using namespace std;

int min(int *, int);

int main()
{
    // 初始化。
    int len = 0;
    int consume = 0;
    int temp = 0;
    cin >> len;
    int arr[len] = {};
    // 输入。
    for (int i = 0; i < len ; i++)
    {
        cin >> arr[i];
    }
    // for (int i = 0; i < len ; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    // 贪心求解。
    for (int j = 0; j < len - 1; j++)
    {
        // 找到当前最小的两个数。
        int num_a = min(arr, len);
        int num_b = min(arr, len);
        temp = (num_a + num_b);
        // 更新状态，把一个空位设置为新的数字。
        // 这个数字的值是上一次贪心的结果。
        for (int k = 0; k < len ; k++)
        {
            if (arr[k] == 0)
            {
                arr[k] = temp;
                break;
            }
        }
        // 记录所有贪心的结果总和。
        consume += temp;
    }
    // 输出。
    cout << consume << endl;
    return 0;
}

int min (int *arr, int len)
{
    int min = 1000000000;
    // 寻找最小数。
    for (int i = 0; i < len ; i++)
    {
        if (arr[i] < min && arr[i] != 0)
        {
            min = arr[i];
        }
    }
    // 贪心之后，把取出的位置设置为空。
    for (int j = 0; j < len ; j++)
    {
        if (arr[j] == min)
        {
            arr[j] = 0;
            break;
        }
    }
    // for (int k = 0 ; k < len ; k++)
    // {
    //     cout << arr[k] << '\t';
    // }
    // cout << endl;
    // cout << min << endl;
    return min;
}

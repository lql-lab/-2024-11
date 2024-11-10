# include <iostream>

using namespace std;

void count_sort(int* , int);
int read();

int main()
{
    // 初始化。
    int num = 0;
    cin >> num;
    int arr[num] = {};
    // 输入。
    for (int i = 0 ; i < num ; i++)
    {
        arr[i] = read();
    }
    // 进行计数排序（数据范围1～1000）。
    count_sort(arr, num);
    return 0;
}
// 计数排序。
void count_sort(int* arr, int len)
{
    int count_er[1001] = {};
    int sum = 0;
    for (int i = 0 ; i < len ; i++)
    {
        if (count_er[arr[i]] == 0)
        {
            // 每有一个新类型的数字，计数，并记录。
            sum += 1;
            count_er[arr[i]] = 1;
        }
    }
    // 输出总共有多少不同的数字。
    cout << sum << endl;
    // 循环从小到大输出。
    for (int i = 0 ; i < 1001 ; i++)
    {
        if (count_er[i])
        {
            cout << i << " ";
        }
    }
    return;
}
// 快读。
int read()
{
    int num = 0, sign = 1;
    char p = getchar();
    while (p < '0' || p > '9')
    {
        if (p == '-')
        {
            sign = -1;
        }
        p = getchar();
    }
    while (p >= '0' && p <= '9')
    {
        num = num * 10 + (p - '0');
        p = getchar();
    }
    return num * sign;
}
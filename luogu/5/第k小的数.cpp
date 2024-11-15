# include <iostream>
# include <algorithm>

using namespace std;

int read();

int main()
{
    // 初始化。
    int num = 0;
    int k = 0;
    cin >> num >> k;
    int arr[num] = {};
    // 输入。
    for (int i = 0; i < num ; i++)
    {
        arr[i] = read();
    }
    // 排好前k个数字。
    nth_element(arr, arr + k, arr + num);
    // 输出第k个数。
    cout << arr[k] << endl;
    return 0;
}

// 快读int。
int read() 
{
    int num = 0;
    int sign = 1;
    char part = getchar();
    while (part < '0' || part > '9')
    {
        if (part == '-')
        {
            sign = -1;
        }
        part = getchar();
    }
    while (part >= '0' && part <= '9')
    {
        num = num * 10 + (part - '0');
        part = getchar();
    }
    return sign * num;
}
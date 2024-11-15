# include <iostream>
# include <algorithm>

using namespace std;

// 结构体记录消耗资源量和输入时的序号。
struct Arr
{
    int value;
    int num;
};

bool compera(Arr a, Arr b)
{
    return a.value < b.value;
}

int main()
{
    // 初始化。
    int num = 0;
    cin >> num;
    Arr arr[num];
    // 输入。
    for (int i = 0; i < num ; i++)
    {
        cin >> arr[i].value;
        arr[i].num = i + 1;
    }
    // 由于状态是一维的，可以通过贪心解决。
    // 按照资源消耗递增排序。
    sort(arr, arr + num, compera);
    double arge = 0;
    double sum = 0;
    // 计算所有人的等待时间总和。
    for (int i = 0; i < num ; i++)
    {
        cout << arr[i].num << " ";
        sum += arr[i].value * (num - i - 1);
    }
    cout << endl;
    // 计算，输出平均时间。
    arge = sum / num;
    printf("%.2f", arge);
    return 0;
}
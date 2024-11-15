# include <iostream>

using namespace std;

// 插入排序函数。
int inser_sort(int*, int);

int main()
{
    // 初始化。
    int num = 0;
    cin >> num;
    int arr[num] = {};
    // 输入。
    for (int i = 0; i < num ; ++i)
    {
        cin >> arr[i];
    }
    // 排序+计数。
    int sum = inser_sort(arr, num);
    // 输出。
    cout << sum << endl;
    return 0;
}

int inser_sort(int* arr, int len)
{
    int sum = 0;
    for (int i = 1; i < len ; ++i)
    {
        int j = i, temp = arr[i];
        while (arr[j - 1] > temp && j > 0)
        {
            arr[j] = arr[j - 1];
            --j;
            ++sum; // 在每一次交换后进行计数。
        }
        arr[j] = temp;
    }
    // 返回总交换次数。
    return sum;
}

# include <iostream>
# include <algorithm>

using namespace std;

bool compera(int a, int b)
{
    return a < b;
}
// 这是一个使用算法库模板函数进行排序的程序。
int main()
{
    int num = 0;
    cin >> num;
    int arr[num] = {};
    for (int i = 0; i < num ; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + num, compera);
    for (int i = 0 ; i < num ; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
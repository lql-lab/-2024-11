# include <iostream>
#include<algorithm>

using namespace std;

struct Arr
{
    int start;
    int end;
};

bool compera(Arr a,Arr b)
{
    return a.end < b.end;
}

int main()
{
    // 初始化。
    int num = 0;
    cin >> num;
    Arr arr[num];
    // for (int i = 0; i < num ; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         arr[i][j] = 0;
    //     }
    // }
    // 输入每个任务的开始与结束。
    for (int i = 0; i < num ; i++)
    {
        cin >> arr[i].start;
        cin >> arr[i].end;
    }
    // 哪个先结束，哪个排前面。
    sort(arr, arr + num, compera);
    // 由于数据量较大，所以放弃了下面的插入排序。
    // for (int i = 1; i < num ; i++)
    // {
    //     int j = i;
    //     int temp = arr[i][1];
    //     int temp_j = arr[i][0];
    //     while(temp < arr[j - 1][1] && j > 0)
    //     {
    //         arr[j][0] = arr[j - 1][0];
    //         arr[j][1] = arr[j - 1][1];
    //         j--;
    //     }
    //     arr[j][1] = temp;
    //     arr[j][0] = temp_j;
    // }
    // for (int i = 0; i < num ; i++)
    // {
    //     for (int j = 0; j < 2 ;j++)
    //     {
    //         cout << arr[i][j] << '\t';
    //     }
    //     cout << endl;
    // }
    // 考虑边界，必然要进行一个任务，初始化为1。
    int sum = 1;
    // 进行贪心求解。
    for (int i = 0; i < num; )
    {
        int j;
        for (j = i + 1; j < num ; j++)
        {
            if (arr[j].start >= arr[i].end)
            {
                sum++;
                break;
            }
        }
        i = j;
    }
    // 输出。
    cout << sum << endl;
    return 0;
}




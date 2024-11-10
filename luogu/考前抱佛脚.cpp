# include <iostream>
# include <algorithm>

using namespace std;

// 为进行深度优先搜索的函数构建全局变量。
int sum = 0;
int all_times = 0;
int arr[4] = {};
int times[4][30] = {};

void dfs(int x, int y, int sum1, int sum2);

int main()
{
    // 输入。
    for (int i = 0; i < 4 ; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0; j < arr[i] ; j++)
        {
            cin >> times[i][j];
        }
    }
    // 对于每一个任务进行dfs，并累加结果。
    for (int i = 0 ; i < 4 ; i++)
    {
        dfs(i, 0, 0, 0);
        all_times += sum;
        sum = 0;
    }
    // 输出。
    cout << all_times << endl;
    return 0;
}

void dfs(int x, int y, int sum1, int sum2)
{
    // 最深层的情况。
    if (y == arr[x])
    {
        int temp_min = max(sum1 + times[x][y], sum2 + times[x][y]);
        if (temp_min < sum || sum == 0)
        {
            sum = temp_min;
        }
    }
    else
    {
        // 每一个节点都有两个子节点，继续搜索。
        dfs(x, y + 1, sum1 + times[x][y], sum2);
        dfs(x, y + 1, sum1, sum2 + times[x][y]);            
    }
}
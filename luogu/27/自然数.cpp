# include <iostream>

using namespace std;

// dfs使用的全局变量。
int arr[10] = {};

void print(int k);
void dfs(int num, int local, int last);

int main()
{
    int num = 0;
    cin >> num;
    dfs(num, 0, 1);
    return 0;
}

void print(int k)
{
  cout << arr[0];
  for (int i = 1 ; i <= k ; i++)
    cout << "+" << arr[i];
  cout << endl;
}

// 每一层记录深度作为结束搜索条件。
void dfs(int num, int local, int last)
{   if (num == 0 && local != 1)
    {
        print(local - 1);
        return;
    }
    // 保证下一层结果不小于上一层，在相邻层间传递信息。
    for (int i = last ; i <= num; i++)
    {
        arr[local] = i;
        dfs(num - i, local + 1, i);
    }
}

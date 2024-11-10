# include <iostream>
using namespace std;

// 辗转相除求最大公因数。由于数据很大，于是放弃使用这种方法。
bool is_p(int a, int b);
// 判断质数。
bool is_p(int num);

int main()
{
    // 初始化。
    int num = 0;
    cin >> num;
    int arr[num] = {};
    // 判断质数，立即输出。
    for (int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
        if (is_p(arr[i]))
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}

bool is_p(int a, int b)
{
    bool ret;
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    if (a == 1)
    {
        ret = true;
    }
    else
    {
        ret = false;
    }
    return ret;
}

bool is_p(int num)
{
    bool ret = true;
    if (num <= 3)
    {
        if (num == 1)
        {
            ret = false;
        }
        else
        {
            ret = true;
        }
    }
    else
    {
        if (num % 2 == 0 || num % 3 == 0)
        {
            ret = false;
        }
        else
        {
            for (int i = 5; i * i <= num ; i += 1)
            {
                if(num % i == 0)
                {
                    ret = false;
                    break;
                }
            }
        }
    }
    return ret;
}
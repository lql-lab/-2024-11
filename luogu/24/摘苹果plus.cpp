# include <iostream>
#include<algorithm>

using namespace std;

// 苹果结构体，储存所需资源和高度。
struct Apple
{
    int height;
    int force;
};

bool compare(Apple a, Apple b)
{
    return a.force < b.force;
}

int main()
{
    // 初始化。
    int len = 0;
    int force = 0;
    int height = 0;
    int height_b = 0;
    // 输入。
    cin >> len >> force >> height >> height_b;
    Apple apple[len];
    for (int i = 0; i < len ; i++)
    {
        cin >> apple[i].height;
        cin >> apple[i].force;
    }
    // 根据所需资源递增排序。
    sort(apple, apple + len, compare);
    int sum = 0;
    // 贪心求解。
    for (int i = 0; i < len ; i++)
    {
        if (apple[i].height <= height + height_b)
        {
            if (force >= apple[i].force)
            {
                force -= apple[i].force;
                sum++;
            }
            else
            {
                break;
            }
        }
    }
    // 输出。
    cout << sum << endl;
    return 0;
}
# include <iostream>
# include <time.h>
using namespace std;

int main ()
{
    srand((unsigned int)time(NULL));
    int target = rand() % 100 + 1;
    int user_input = 0;
    int try_times = 0;
    int out_flag = 0;
    int score = 0;
    int i = 1;
    do
    {
        try_times ++;
        cout << "输入一个1~100之间的数:" << endl;
        cin >> user_input;
        if (user_input == target)
        {
            cout << "猜中了," << "你尝试了" << try_times << "次" << endl;
            out_flag = 1;
        }
        else if (user_input < target)
        {
            cout << "猜小了" << endl;
            score += target - user_input;
        }
        else
        {
            cout << "猜大了" << endl;
            score += user_input - target;
        }
        if (out_flag)
        {
            score = int(5 - score*0.05/try_times);
            break;
        }
        if (try_times >= 5*i)
        {
            int arge = score/try_times;
            int lef = 0,rig = 0;
            lef = (target - arge)>0?(target - arge):0;
            rig = (target + arge < 100)?(target + arge):100;
            target = lef + rand() % (rig - lef) + 1;
            i ++;
        }
        user_input = -1;
    } while (user_input != target);
    switch (score)
    {
    case 5:
        cout << "分数:5" << endl;
        break;
    case 4:
        cout << "分数:4,及格。" << endl;
        break;
    default:
        cout << "分数低,小垃圾。" << endl;
        break;
    }
    system("read");
    return 0;
}
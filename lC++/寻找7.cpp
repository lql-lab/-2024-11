# include <iostream>
using namespace std;

int search(int);
int main()
{
    for (int i = 0; i < 101; i++)
    {
        if (search(i) == 1)
        {
            cout << "拍桌子 --> " << i << endl; 
        }
        else
        {
            cout << i << endl;
        }
    }
    system("read");
    return 0;
}
int search(int num)
{
    int flag = 0;
    if (num % 7 == 0 && num != 0)
    {
        flag = 1;
    }
    else
    {
        while(num > 0)
        {
            int part = num % 10;
            if (part == 7)
            {
                flag = 1;
                break;
            }
            else
            {
                num /= 10;
            }
        }
    }
    return flag;
}
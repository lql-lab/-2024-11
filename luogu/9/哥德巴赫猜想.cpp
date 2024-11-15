# include <iostream>

using namespace std;

bool is_prime(int);
void print_one_num(int);

int main()
{
    int up_limit = 0;
    cin >> up_limit;
    for (int i = 2; i <= up_limit ; i += 2)
    {
        print_one_num(i);
    }
    return 0;
}

bool is_prime(int num)
{
    bool ret = true;
    if (num == 2 || num == 3)
    {
        ret = true;
    }
    else if (num % 2 == 0 || num % 3 == 0)
    {
        ret = false;
    }
    else
    {
        for (int i = 5 ; i < num ; ++i)
        {
            if (num % i == 0)
            {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

void print_one_num(int num)
{
    if (num == 4)
    {
        cout << "4=2+2" << endl;
    }
    else if (num > 2)
    {
        for (int i = 3; i < num - 2 ; ++i)
        {
            if (is_prime(i))
            {
                if (i + 2 == num)
                {
                    cout << num << "=2+" << i << endl;
                    break;
                }
                else if (is_prime(num - i))
                {
                    cout << num << "=" << i << "+" << num - i << endl;
                    break;
                }
            }   
        }
    }
    return;
}
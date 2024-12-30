# include<iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            cout << "* ";
            if (j == 14)
            {
                cout << '*' << endl;
            }
        }
    }
    system("read");
    return 0;
}
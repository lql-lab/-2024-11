# include <iostream>
using namespace std;

void print_all(int *arr,int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
# include<iostream>
using namespace std;

void sort(int *arr, int len)
{
    int i = 1;
    while (i < len)
    {
        int temp = arr[i];
        int j = i;
        while (arr[j - 1] > temp && j > 0)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
        i++;
    }
}
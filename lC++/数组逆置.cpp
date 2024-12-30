# include<iostream>
using namespace std;
# include "sort.hpp"

void change(int *lef, int *rig);
void quicksort(int *, int *);
void print_all(int *, int);
int main()
{
    int arr[] = {1,3,4,4,2,5,7};
    int len = sizeof(arr) / sizeof(int);
    sort(arr, len);
    change(&arr[0], &arr[len - 1]);
    print_all(arr,len);
    system("read");
    return 0;
}
void change(int *lef, int *rig)
{
    while (lef < rig)
    {
        int temp = 0;
        temp = *lef;
        *lef = *rig;
        *rig = temp;
        lef++;
        rig--;
    }
    return;
}
void print_all(int *arr,int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void quicksort(int *lef, int *rig)
{
    if (lef >= rig)
    {
        return;
    }
    else
    {
        int flag = *rig;
        int *deep_lef = lef; int *deep_rig = rig;
        while (lef < rig)
        {
            while (*lef <= flag && lef < rig)
            {
                lef++;
            }
            while (*rig >= flag && lef < rig)
            {
                rig--;
            }
            int temp = *lef;
            *lef = *rig;
            *rig = temp;
        }
        int *new_p = lef;
        if (*new_p > flag)
        {
            *deep_rig = *new_p;
            *new_p = flag;
        }
        else 
        {
            new_p = deep_rig;
        }
        quicksort(deep_lef, new_p - 1);
        quicksort(new_p + 1, deep_rig);
    }
}
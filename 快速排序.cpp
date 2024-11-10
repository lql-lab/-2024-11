# include<iostream>
using namespace std;
# include"quicksort.hpp"
# include"print_all.hpp"

int main()
{
    int arr[] = {3,1,4,6,3,5,2,7,1,3,5,4,1,2,7,3,5,2,3,7,0,1,2,5,3,4,1};
    int len = sizeof(arr) / sizeof(int);
    quicksort(&arr[0], &arr[len - 1]);
    print_all(arr, len);
    system("read");
    return 0;
}

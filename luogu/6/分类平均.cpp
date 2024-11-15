# include <iostream>

using namespace std;

struct A_B
{
    int value;
    int num;
}A,B;

int main()
{
    int num = 0, k = 0;
    cin >> num >> k;
    int sum_a = 0, sum_b = 0;
    for (int i = 1; i <= num ; ++i)
    {
        if (i % k == 0)
        {
            A.value += i;
            ++A.num;
        }
        else
        {
            B.value += i;
            ++B.num;
        }
    }
    double arge_a = 0.0, arge_b = 0.0;
    arge_a = double(A.value) / double(A.num);
    arge_b = double(B.value) / double(B.num);
    printf("%.1f %.1f", arge_a, arge_b);
    cout << endl;
    return 0;
}
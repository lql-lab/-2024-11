# include <iostream>
# include <random>

using namespace std;

struct Part
{
    int value;
    int num;
};

void swap(Part* a, Part* b);
void quicksort(Part* left, Part* right);

// 这是一个对结构体快排的程序。
int main()
{
    int len = 0, k = 0;
    cin >> k;
    cin >> len;
    Part parts[len];
    for (int i = 0; i < len ; i++)
    {
        cin >> parts[i].value;
        parts[i].num = i;
    }
    quicksort(&parts[0], &parts[len - 1]);
    for (int i = 0; i < len ; i++)
    {
        cout << parts[i].value << " ";
    }
    return 0;
}

void swap(Part* a, Part* b)
{
    Part temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void quicksort(Part* left, Part* right)
{
    if (left >= right)
    {
        return;
    }
    else
    {
        Part* ran_part = left + rand() % (right - left + 1);
        swap(ran_part, left);
        int flag = left->value;
        Part* r_left = left;
        Part* r_right = right;
        while (left < right)
        {
            while (right->value >= flag && right > left)
            {
                right--;
            }
            while (left->value <= flag && left < right)
            {
                left++;
            }
            swap(left, right);
        }
        swap(r_left, left);
        quicksort(r_left, left - 1);
        quicksort(left + 1, r_right);            
    }
}

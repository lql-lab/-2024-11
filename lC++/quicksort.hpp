# include <iostream>
# include <random>

using namespace std;

void swap(int*, int*);
void quicksort(int *lef, int *rig)
{
    if (lef >= rig)
    {
        return;
    }
    else
    {
        int* ran_pos = lef + rand() % (rig - lef) + 1;
        swap(lef, ran_pos);

        int flag = *lef;
        int *deep_lef = lef; int *deep_rig = rig;
        while (lef < rig)
        {
            while (*rig >= flag && lef < rig)
            {
                rig--;
            }
            while (*lef <= flag && lef < rig)
            {
                lef++;
            }
            swap(lef, rig);
        }
        swap(lef, deep_lef);

        quicksort(deep_lef, lef - 1);
        quicksort(lef + 1, deep_rig);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
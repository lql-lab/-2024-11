# pragma once
# include <iostream>
using namespace std;

class Circle
{
private:
    int mid_r;
    int x_y[2];
public:
    void set_point(int x, int y)
    {
        x_y[0] = x;
        x_y[1] = y;
    }
    int set_midr(int r)
    {
        mid_r = r;
        return r;
    }
    int* get_xy(void)
    {
        int *p = x_y;
        return p;
    }
    int get_r(void)
    {
        return mid_r;
    }
};

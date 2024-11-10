# pragma once
# include <iostream>
using namespace std;

# include "circle.hpp"
class Point
{
private:
    int point[2];
public:
    void set_point(int x, int y)
    {
        point[0] = x;
        point[1] = y;
    }
    int* get_point(void)
    {
        int *p = point;
        return p;
    }
    int p_circle(Circle circle)
    {
        int ret = 0;
        int twice_r = circle.get_r() * circle.get_r();
        int length = (point[0] - *(circle.get_xy())) * (point[0] - *(circle.get_xy())) +
                     (point[1] - *(circle.get_xy() + 1)) * (point[1] - *(circle.get_xy() + 1));
        if (length < twice_r)
        {
            ret = -1;
        }
        else if (length > twice_r)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
        return ret;
    }
};
#include <iostream>

class Point
{
private:
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    void setPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX(void)
    {
        return x;
    }
    int setX(int x)
    {
        this->x = x;
    }
    int getY(void)
    {
        return y;
    }
    int setY(int y)
    {
        this->y = y;
    }
};
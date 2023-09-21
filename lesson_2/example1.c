#include <iostream>

class Point {
public:
    int x;
    int y;
};

int main()
{
    Point P1, *P2;
    P2 = new Point;
    P1.x = 10;
    (*P2).x = 10;   //Скобки нужны, т.к. у точки более высокий приоритет, чем у *

    std::cout << P1.x << std::endl;
    std::cout << (*P2).x << std::endl;
    std::cout << P2->x << std::endl;    //правильный способ!
    delete P2;
}

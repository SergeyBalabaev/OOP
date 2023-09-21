#include <iostream>

class Point {
public:
    Point();
    Point(int, int);
    Point(const Point&);
    int x;
    int y;
};

Point::Point(int _x, int _y) {
    x = _x;
    y = _y;
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(const Point& T) {
    x = T.x + 1;
    y = T.y + 1;
}

int main()
{
    Point P1(1, 1);
    Point P2 = P1;
    std::cout << "(" << P1.x << ":" << P1.y << ")" << std::endl;
    std::cout << "(" << P2.x << ":" << P2.y << ")" << std::endl;
}

#include <iostream>

class A {
    friend class B;
public:
    void print_x() {
        std::cout << "X = " << x << "\n";
    }
private:
    int x;
};

class B {
    
public:
    void print_x(A& a) {
        std::cout << "X = " << a.x << "\n";
    }
    void print_y() {
        std::cout << "Y = " << y << "\n";
    }
private:
    int y;
};

int main()
{
    A a;
    B b;
    a.print_x();
}

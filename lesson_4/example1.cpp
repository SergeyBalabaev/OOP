#include <iostream>

class A {
public:
    friend void f(A&);
    void print_x() {
        std::cout << "X = " << x << "\n";
    }
private:
    int x, y;
};

void f(A& a) {
    a.x = 10;
}

int main()
{
    A a;
    f(a);
    a.print_x();
}
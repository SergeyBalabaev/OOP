#include <iostream>

class A {
public:
    int x;
    A(int _x) {
        x = _x;
        std::cout << "A constructor" << std::endl;
    }
};

class B : public A{ 
public:
    int y = 15;
    B() : A(1) {};
    B(int x):A(x) {
        std::cout << "B constructor" << std::endl;
    }
    void printX() {
        std::cout << x << std::endl;
    }
};


int main()
{
    B b(10), c;
    b.printX();
    c.printX();
}

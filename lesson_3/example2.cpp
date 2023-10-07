#include <iostream>

class A {
public:
    int x = 15;
    A() {
        std::cout << "A constructor" << std::endl;
    }
};

class B : public A{  //можно поменять на private
public:
    int y;
    B() {
        std::cout << "B constructor" << std::endl;
    }
    void printX() {
        std::cout << x << std::endl;
    }
};

class C : public B {
public:
    int z;
    C() {
        std::cout << "C constructor" << std::endl;
    }
    void printX() {
        std::cout << x << std::endl;
    }
};


int main()
{
    A a;
    B b;
    C c;
    c.printX();
}
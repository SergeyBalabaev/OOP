#include <iostream>
#include <vector>


class Base {
private:
    int x = 0;
public:
    virtual void print_x(){};
};

class A : public Base{
public:
    void print_x() override {
        std::cout << "A.x = " << x << "\n";
    };
private:
    int x = 1;
};

class B : public Base {
public:
    void print_x() override {
        std::cout << "B.x = " << x << "\n";
    };
private:
    int x = 2;
};

class C : public Base {
public:
    void print_x() override {
        std::cout << "C.x = " << x << "\n";
    };
private:
    int x = 3;
};

int main()
{
    std::vector <Base*> base_vec;
    A a;
    B b;
    C c;
    base_vec.push_back(&a);
    base_vec.push_back(&b);
    base_vec.push_back(&c);
    base_vec[0]->print_x();
    base_vec[1]->print_x();
    base_vec[2]->print_x();

    //    for (int i = 0; i < base_vec.size(); ++i)
    //    base_vec[i]->print_x();
    return 0;
}

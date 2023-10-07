#include <iostream>

class animal {
private:
    int age = 0;
    int weight = 0;
    std::string name;
public:
    animal();
    animal(int age, int weight, std::string name);
    static int number;
    void printnum();
   
};
animal::animal() {
    this->age = 0;
    this->weight = 0;
    this->name = "";
    number++;
}


void animal::printnum() {
    std::cout << animal::number << std::endl;
}

animal::animal(int age, int weight, std::string name) {
    this->age = age;
    this->weight = weight;
    this->name = name;
    number++;
}
int animal::number = 0;
int main()
{
    animal a, b, c(1,1,"panda"), d;
    a.printnum();
}
// Интерфейс Product объявляет операции, которые должны
// реализовать все конкретные продукты.
#include <iostream>

class Product
{
public:
    virtual ~Product() {}
    virtual std::string operation() const = 0;
};

// Конкретные продукты предоставляют различные реализации интерфейса Product.
class ConcreteProduct1 : public Product
{
public:
    std::string operation() const override
    {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product
{
public:
    std::string operation() const override
    {
        return "{Result of the ConcreteProduct2}";
    }
};

// Класс Creator (создатель) объявляет фабричный метод,
// который должен возвращать объект класса Product.
// Подклассы Creator'а обычно предоставляют реализацию этого метода.
class Creator
{
    // Обратите внимание, что Creator может также
    // обеспечить реализацию фабричного метода по умолчанию.
public:
    virtual ~Creator() {};
    virtual Product* factoryMethod() const = 0;
    // Также заметьте, что, несмотря на название, основная обязанность Creator'а
    // не заключается в создании продуктов. Обычно он содержит некоторую базовую
    // бизнес-логику, которая основана на объектах Product, возвращаемых
    // фабричным методом. Подклассы могут косвенно изменять эту бизнес-логику,
    // переопределяя фабричный метод и возвращая из него другой тип продукта.

    std::string someOperation() const
    {
        // Вызываем фабричный метод, чтобы получить объект Product.
        Product* product = this->factoryMethod();
        // Теперь используем этот продукт.
        std::string result = "Creator: The same creator's code has just worked with "
            + product->operation();
        delete product;
        return result;
    }
};

// Конкретные создатели переопределяют фабричный метод,
// чтобы изменить тип получаемого продукта.
class ConcreteCreator1 : public Creator
{
public:
    // Обратите внимание, что сигнатура метода по-прежнему использует тип
    // абстрактного продукта, хотя фактически из метода возвращается конкретный
    // тип продукта. Таким образом, Creator может оставаться независимым от
    // конкретных классов продуктов.
    Product* factoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{
public:
    Product* factoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};

// Клиентский код работает с экземпляром конкретного типа создателя,
// хотя и через его базовый интерфейс. Пока клиент продолжает работать
// с создателем через базовый интерфейс, вы можете передать ему любой
// подкласс создателя.
void clientCode(const Creator& creator)
{
    // ...
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
        << creator.someOperation() << std::endl;
    // ...
}

// Приложение выбирает тип создателя в зависимости от конфигурации или среды.
int main()
{
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator = new ConcreteCreator1();
    clientCode(*creator);

    std::cout << std::endl;

    std::cout << "App: Launched with the ConcreteCreator2.\n";
    Creator* creator2 = new ConcreteCreator2();
    clientCode(*creator2);

    delete creator;
    delete creator2;
    return 0;
}

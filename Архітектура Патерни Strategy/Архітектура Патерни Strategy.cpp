#include <iostream>
#include <windows.h>
using namespace std;

// Стратегія: інтерфейс для руху
class Strategy {
public:
    virtual void move() = 0;
    virtual ~Strategy() = default;
};

// Конкретна стратегія: рух пішки
class WalkStrategy : public Strategy {
public:
    void move() override {
        cout << "Я йду пішки." << endl;
    }
};

// Конкретна стратегія: рух на автомобілі
class CarStrategy : public Strategy {
public:
    void move() override {
        cout << "Я їду на автомобілі." << endl;
    }
};

// Конкретна стратегія: рух на велосипеді
class BikeStrategy : public Strategy {
public:
    void move() override {
        cout << "Я їду на велосипеді." << endl;
    }
};

// Контекст: Транспорт
class Transport {
private:
    Strategy* strategy;  // Поточна стратегія

public:
    Transport(Strategy* initialStrategy) : strategy(initialStrategy) {}

    // Зміна стратегії
    void setStrategy(Strategy* newStrategy) {
        strategy = newStrategy;
    }

    // Виконання стратегії
    void performMove() {
        strategy->move();
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створюємо стратегії
    WalkStrategy* walk = new WalkStrategy();
    CarStrategy* car = new CarStrategy();
    BikeStrategy* bike = new BikeStrategy();

    // Створюємо транспорт
    Transport* transport = new Transport(walk);

    // Використовуємо стратегію "Пішки"
    transport->performMove();

    // Змінюємо стратегію на "Автомобіль"
    transport->setStrategy(car);
    transport->performMove();

    // Змінюємо стратегію на "Велосипед"
    transport->setStrategy(bike);
    transport->performMove();


    delete walk;
    delete car;
    delete bike;
    delete transport;


}

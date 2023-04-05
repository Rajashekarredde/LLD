#include <iostream>
#include <string>

// Component interface
class Car {
public:
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Car() = default;
};

// Concrete component
class BasicCar : public Car {
public:
    std::string getDescription() const override {
        return "Basic Car";
    }

    double getCost() const override {
        return 10000.0;
    }
};

// Decorator base class
class CarDecorator : public Car {
protected:
    Car* car;

public:
    CarDecorator(Car* c) : car(c) {}

    virtual ~CarDecorator() {
        delete car;
    }
};

// Concrete decorator: adds navigation feature
class NavigationDecorator : public CarDecorator {
public:
    NavigationDecorator(Car* c) : CarDecorator(c) {}

    std::string getDescription() const override {
        return car->getDescription() + ", Navigation";
    }

    double getCost() const override {
        return car->getCost() + 2000.0;
    }
};

// Concrete decorator: adds leather seats feature
class LeatherSeatsDecorator : public CarDecorator {
public:
    LeatherSeatsDecorator(Car* c) : CarDecorator(c) {}

    std::string getDescription() const override {
        return car->getDescription() + ", Leather Seats";
    }

    double getCost() const override {
        return car->getCost() + 1500.0;
    }
};

int main() {
    Car* basicCar = new BasicCar();
    Car* withNavigation = new NavigationDecorator(basicCar);
    Car* withNavigationAndLeatherSeats = new LeatherSeatsDecorator(withNavigation);

    std::cout << "Car description: " << withNavigationAndLeatherSeats->getDescription() << std::endl;
    std::cout << "Car cost: $" << withNavigationAndLeatherSeats->getCost() << std::endl;

    delete withNavigationAndLeatherSeats;
    return 0;
}

#include "Hall.h"
#include <iostream>

Hall::Hall(int number, const std::string& name) : number(number), name(name) {}

int Hall::getNumber() const {
    return number;
}

const std::string& Hall::getName() const {
    return name;
}

void Hall::printInfo() const {
    std::cout << "Зал " << number << ": " << name << '\n';
}

#include "Hall.h"
#include <iostream>

Hall::Hall(int number, const std::string& name) : number(number), name(name) {}

void Hall::printInfo() const {
    std::cout << "Зал " << number << ": " << name << '\n';
}

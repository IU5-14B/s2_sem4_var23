#ifndef HALL_H
#define HALL_H

#include <string>

class Hall {
private:
    int number;
    std::string name;

public:
    Hall(int number, const std::string& name);

    int getNumber() const;
    const std::string& getName() const;
    void printInfo() const;
};

#endif

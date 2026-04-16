#ifndef HALL_H
#define HALL_H

#include <string>

class Hall {
private:
    int number;
    std::string name;

public:
    Hall(int number, const std::string& name);

    void printInfo() const;
};

#endif

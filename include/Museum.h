#ifndef MUSEUM_H
#define MUSEUM_H

#include "Catalog.h"
#include "Exhibit.h"
#include "Hall.h"
#include <memory>
#include <string>
#include <vector>

class Museum {
private:
    std::string name;
    std::vector<Hall> halls;
    std::vector<std::shared_ptr<MuseumItem>> items;
    Catalog catalog;

public:
    Museum(const std::string& name);

    void addHall(int number, const std::string& hallName);
    void addItem(const std::shared_ptr<MuseumItem>& item);
    void showHalls() const;
    void showCollection() const;
    void showVisitPlan() const;
    MuseumItem* findItem(const std::string& title) const;
};

#endif

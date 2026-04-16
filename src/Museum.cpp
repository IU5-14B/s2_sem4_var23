#include "Museum.h"
#include <iostream>

Museum::Museum(const std::string& name) : name(name) {}

void Museum::addHall(int number, const std::string& hallName) {
    halls.emplace_back(number, hallName);
}

void Museum::addItem(const std::shared_ptr<MuseumItem>& item) {
    items.push_back(item);
}

void Museum::showHalls() const {
    std::cout << "Залы музея \"" << name << "\":\n";

    for (const Hall& hall : halls) {
        hall.printInfo();
    }
}

void Museum::showCollection() const {
    std::cout << "Экспонаты музея \"" << name << "\":\n";

    for (const auto& item : items) {
        item->printInfo();
    }
}

void Museum::showVisitPlan() const {
    std::cout << "План осмотра музея \"" << name << "\":\n";

    for (const auto& item : items) {
        std::cout << "- " << item->getTitle()
                  << ": " << item->getRecommendedVisitMinutes() << " мин.\n";
    }
}

MuseumItem* Museum::findItem(const std::string& title) const {
    return catalog.findByTitle(items, title);
}

#include "Museum.h"
#include <iostream>

Museum::Museum(const std::string& name) : name(name) {}

const std::string& Museum::getName() const {
    return name;
}

std::size_t Museum::getHallCount() const {
    return halls.size();
}

std::size_t Museum::getItemCount() const {
    return items.size();
}

const std::vector<std::shared_ptr<MuseumItem>>& Museum::getItems() const {
    return items;
}

void Museum::addHall(int number, const std::string& hallName) {
    halls.emplace_back(number, hallName);
}

void Museum::addItem(const std::shared_ptr<MuseumItem>& item) {
    items.push_back(item);
}

void Museum::showInfo() const {
    std::cout << "Музей: " << name << '\n'
              << "Количество залов: " << halls.size() << '\n'
              << "Количество экспонатов: " << items.size() << '\n';
}

void Museum::showHalls() const {
    std::cout << "Залы музея \"" << name << "\":\n";

    if (halls.empty()) {
        std::cout << "Залы пока не добавлены.\n";
        return;
    }

    for (const Hall& hall : halls) {
        hall.printInfo();
    }
}

void Museum::showCollection() const {
    std::cout << "Экспонаты музея \"" << name << "\":\n";

    if (items.empty()) {
        std::cout << "Коллекция пока пуста.\n";
        return;
    }

    for (const auto& item : items) {
        item->printInfo();
    }
}

void Museum::showVisitPlan() const {
    std::cout << "План осмотра музея \"" << name << "\":\n";

    if (items.empty()) {
        std::cout << "План осмотра пока невозможно составить.\n";
        return;
    }

    for (const auto& item : items) {
        std::cout << "- " << item->getTitle()
                  << ": " << item->getRecommendedVisitMinutes() << " мин.\n";
    }
}

const MuseumItem* Museum::findItem(const std::string& title) const {
    return catalog.findByTitle(items, title);
}

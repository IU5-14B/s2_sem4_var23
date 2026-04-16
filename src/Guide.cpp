#include "Guide.h"
#include "MuseumItem.h"
#include <iostream>

Guide::Guide(const std::string& name) : name(name) {}

std::string Guide::getName() const {
    return name;
}

void Guide::addToRoute(MuseumItem* item) {
    route.push_back(item);
}

void Guide::showRoute() const {
    std::cout << "Маршрут гида " << name << ":\n";

    for (const MuseumItem* item : route) {
        item->printInfo();
        std::cout << "  Рекомендуемое время осмотра: "
                  << item->getRecommendedVisitMinutes() << " мин.\n";
    }
}

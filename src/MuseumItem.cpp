#include "MuseumItem.h"

MuseumItem::MuseumItem(const std::string& title, int year) : title(title), year(year) {}

std::string MuseumItem::getTitle() const {
    return title;
}

int MuseumItem::getYear() const {
    return year;
}

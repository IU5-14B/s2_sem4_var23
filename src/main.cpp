#include "Exhibit.h"
#include "Guide.h"
#include "Museum.h"
#include "MuseumItem.h"
#include "Visitor.h"
#include <clocale>
#include <iostream>
#include <memory>
#include <typeinfo>

namespace {

void showRuntimeType(const MuseumItem& item) {
    std::cout << "typeid: ";

    if (typeid(item) == typeid(Painting)) {
        std::cout << "Painting";
    } else if (typeid(item) == typeid(Sculpture)) {
        std::cout << "Sculpture";
    } else if (typeid(item) == typeid(Artifact)) {
        std::cout << "Artifact";
    } else {
        std::cout << "Unknown";
    }

    std::cout << '\n';
}

void showSpecialDetails(MuseumItem* item) {
    if (const Painting* painting = dynamic_cast<const Painting*>(item)) {
        std::cout << "dynamic_cast: техника картины \"" << painting->getTitle()
                  << "\" = " << painting->getTechnique() << '\n';
        return;
    }

    if (const Sculpture* sculpture = dynamic_cast<const Sculpture*>(item)) {
        std::cout << "dynamic_cast: материал скульптуры \"" << sculpture->getTitle()
                  << "\" = " << sculpture->getMaterial() << '\n';
        return;
    }

    if (const Artifact* artifact = dynamic_cast<const Artifact*>(item)) {
        std::cout << "dynamic_cast: эпоха артефакта \"" << artifact->getTitle()
                  << "\" = " << artifact->getEpoch() << '\n';
        return;
    }

    std::cout << "dynamic_cast: специальных данных для объекта нет\n";
}

}  // namespace

int main() {
    setlocale(LC_ALL, "");

    Museum museum("Городской музей");

    museum.addHall(1, "Русская живопись");
    museum.addHall(2, "Скульптура");
    museum.addHall(3, "Исторические реликвии");

    std::shared_ptr<MuseumItem> painting = std::make_shared<Painting>(
        "Девочка с персиками", 1887, "Валентин Серов", 1, "масло"
    );
    std::shared_ptr<MuseumItem> sculpture = std::make_shared<Sculpture>(
        "Мыслитель", 1904, "Огюст Роден", 2, "бронза"
    );
    std::shared_ptr<MuseumItem> artifact = std::make_shared<Artifact>(
        "Шлем княжеского дружинника", 1200, "Древняя Русь", 3, "XIII век"
    );

    museum.addItem(painting);
    museum.addItem(sculpture);
    museum.addItem(artifact);

    Guide guide("Анна");
    guide.addToRoute(painting.get());
    guide.addToRoute(sculpture.get());
    guide.addToRoute(artifact.get());

    Visitor visitor("Иван");
    visitor.setGuide(&guide);

    std::cout << "1. Композиция:\n";
    museum.showHalls();

    std::cout << "\n2. Полиморфный вывод информации:\n";
    museum.showCollection();

    std::cout << "\n3. Полиморфный план осмотра:\n";
    museum.showVisitPlan();

    std::cout << "\n4. Агрегация:\n";
    guide.showRoute();

    std::cout << "\n5. Ассоциация:\n";
    visitor.askGuideName();

    std::cout << "\n6. Делегирование + runtime type information:\n";
    MuseumItem* found = museum.findItem("Мыслитель");
    if (found != nullptr) {
        std::cout << "Найден экспонат через каталог:\n";
        found->printInfo();
        showRuntimeType(*found);
        showSpecialDetails(found);
    } else {
        std::cout << "Экспонат не найден\n";
    }

    return 0;
}

#include "menu.h"
#include <iostream>
#include <limits>

void Menu::run() {
    // Загрузка данных из файла или создание примеров
    if (!db.readFromFile(modemList)) {
        std::cout << "Создаем демонстрационные данные..." << std::endl;
        db.generateSampleData(modemList);
    }
    
    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: displayAllModems(); break;
            case 2: addModem(); break;
            case 3: deleteModem(); break;
            case 4: editModem(); break;
            case 5: findModem(); break;
            case 6: saveToFile(); break;
            case 7: loadFromFile(); break;
            case 8: displayAuthorInfo(); break;
            case 0: 
                std::cout << "Сохранение данных и выход..." << std::endl;
                db.writeToFile(modemList);
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);
}

void Menu::displayMainMenu() const {
    std::cout << "\n=== Меню управления базой данных модемов ===" << std::endl;
    std::cout << "1. Показать все модемы" << std::endl;
    std::cout << "2. Добавить модем" << std::endl;
    std::cout << "3. Удалить модем" << std::endl;
    std::cout << "4. Редактировать модем" << std::endl;
    std::cout << "5. Найти модем" << std::endl;
    std::cout << "6. Сохранить в файл" << std::endl;
    std::cout << "7. Загрузить из файла" << std::endl;
    std::cout << "8. Информация об авторе" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

void Menu::displayAllModems() const {
    modemList.displayAll();
}

void Menu::addModem() {
    std::string manufacturer, model, typeStr, standardStr;
    double price, maxSpeed;
    
    std::cout << "\n=== Добавление нового модема ===" << std::endl;
    std::cout << "Производитель: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Модель: ";
    std::getline(std::cin, model);
    
    std::cout << "Тип (Dial-Up, DSL, Cable, Fiber, Wireless): ";
    std::getline(std::cin, typeStr);
    ModemType type;
    if (typeStr == "Dial-Up") type = ModemType::DialUp;
    else if (typeStr == "DSL") type = ModemType::DSL;
    else if (typeStr == "Cable") type = ModemType::Cable;
    else if (typeStr == "Fiber") type = ModemType::Fiber;
    else type = ModemType::Wireless;
    
    std::cout << "Стандарт (V.32, V.34, V.90, ADSL, VDSL, DOCSIS, LTE, WiFi): ";
    std::getline(std::cin, standardStr);
    ConnectionStandard standard;
    if (standardStr == "V.32") standard = ConnectionStandard::V32;
    else if (standardStr == "V.34") standard = ConnectionStandard::V34;
    else if (standardStr == "V.90") standard = ConnectionStandard::V90;
    else if (standardStr == "ADSL") standard = ConnectionStandard::ADSL;
    else if (standardStr == "VDSL") standard = ConnectionStandard::VDSL;
    else if (standardStr == "DOCSIS") standard = ConnectionStandard::DOCSIS;
    else if (standardStr == "LTE") standard = ConnectionStandard::LTE;
    else standard = ConnectionStandard::WiFi;
    
    std::cout << "Максимальная скорость (Мбит/с): ";
    std::cin >> maxSpeed;
    std::cout << "Цена: ";
    std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    Modem newModem(manufacturer, model, type, standard, maxSpeed, price);
    modemList.addModem(newModem);
    std::cout << "Модем успешно добавлен!" << std::endl;
}

void Menu::deleteModem() {
    std::string manufacturer, model;
    
    std::cout << "\n=== Удаление модема ===" << std::endl;
    std::cout << "Производитель: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Модель: ";
    std::getline(std::cin, model);
    
    if (modemList.deleteModem(manufacturer, model)) {
        std::cout << "Модем успешно удален!" << std::endl;
    } else {
        std::cout << "Модем не найден!" << std::endl;
    }
}

void Menu::editModem() {
    std::string manufacturer, model;
    
    std::cout << "\n=== Редактирование модема ===" << std::endl;
    std::cout << "Введите данные модема для редактирования:" << std::endl;
    std::cout << "Производитель: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Модель: ";
    std::getline(std::cin, model);
    
    Modem* modem = modemList.findModem(manufacturer, model);
    if (!modem) {
        std::cout << "Модем не найден!" << std::endl;
        return;
    }
    
    std::cout << "Текущие данные модема:" << std::endl;
    modem->displayInfo();
    
    std::cout << "\nВведите новые данные:" << std::endl;
    addModem(); // Используем ту же логику, что и для добавления
    
    std::cout << "Модем успешно обновлен!" << std::endl;
}

void Menu::findModem() const {
    std::string manufacturer, model;
    
    std::cout << "\n=== Поиск модема ===" << std::endl;
    std::cout << "Производитель: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Модель: ";
    std::getline(std::cin, model);
    
    Modem* modem = modemList.findModem(manufacturer, model);
    if (modem) {
        std::cout << "Модем найден:" << std::endl;
        modem->displayInfo();
    } else {
        std::cout << "Модем не найден!" << std::endl;
    }
}

void Menu::saveToFile() {
    if (db.writeToFile(modemList)) {
        std::cout << "Данные успешно сохранены в файл!" << std::endl;
    } else {
        std::cout << "Ошибка при сохранении данных!" << std::endl;
    }
}

void Menu::loadFromFile() {
    if (db.readFromFile(modemList)) {
        std::cout << "Данные успешно загружены из файла!" << std::endl;
    } else {
        std::cout << "Ошибка при загрузке данных!" << std::endl;
    }
}
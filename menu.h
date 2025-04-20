#ifndef MENU_H
#define MENU_H

#include "doublylinkedlist.h"
#include "database.h"
#include <string>

class Menu {
private:
    DoublyLinkedList modemList;
    Database db;
    
    void displayMainMenu() const;
    void displayAllModems() const;
    void addModem();
    void deleteModem();
    void editModem();
    void findModem() const;
    void saveToFile();
    void loadFromFile();
    
public:
    Menu(const std::string& filename) : db(filename) {}
    void run();
    

    static void displayAuthorInfo() {
        std::cout << "\n=== Автор программы ===" << std::endl;
        std::cout << "Группа: ИЦТМС 2-2" << std::endl;
        std::cout << "ФИО: Аксенов Игорь Константинович" << std::endl;
        std::cout << "Дата разработки: 21.04.2025" << std::endl;
    }
};

#endif 
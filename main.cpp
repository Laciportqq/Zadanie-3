#include "menu.h"
#include <locale>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    std::cout << "=== Программа учета модемов ===" << std::endl;
    std::cout << "=== Версия 1.0 ===" << std::endl;
    
    Menu menu("modems_db.txt");
    menu.run();
    
    return 0;
}
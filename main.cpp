#include "menu.h"
#include <locale>

int main() {

    setlocale(LC_ALL, "Russian");
    
    std::cout << "=== Программа учета модемов ===" << std::endl;
    std::cout << "=== Версия 1.0 ===" << std::endl;
    
    Menu menu("modems_db.txt");
    menu.run();
    
    return 0;
}
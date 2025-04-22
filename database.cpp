#include "database.h"
#include <iostream>

bool Database::readFromFile(DoublyLinkedList& list) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения: " << filename << std::endl;
        return false;
    }
    
    std::string manufacturer, model, typeStr, standardStr;
    double price, maxSpeed;
    bool isConnected, isPoweredOn;
    
    while (file >> manufacturer >> model >> typeStr >> standardStr 
               >> price >> maxSpeed >> isConnected >> isPoweredOn) {
        
        ModemType type;
        if (typeStr == "Dial-Up") type = ModemType::DialUp;
        else if (typeStr == "DSL") type = ModemType::DSL;
        else if (typeStr == "Cable") type = ModemType::Cable;
        else if (typeStr == "Fiber") type = ModemType::Fiber;
        else type = ModemType::Wireless;
        
        ConnectionStandard standard;
        if (standardStr == "V.32") standard = ConnectionStandard::V32;
        else if (standardStr == "V.34") standard = ConnectionStandard::V34;
        else if (standardStr == "V.90") standard = ConnectionStandard::V90;
        else if (standardStr == "ADSL") standard = ConnectionStandard::ADSL;
        else if (standardStr == "VDSL") standard = ConnectionStandard::VDSL;
        else if (standardStr == "DOCSIS") standard = ConnectionStandard::DOCSIS;
        else if (standardStr == "LTE") standard = ConnectionStandard::LTE;
        else standard = ConnectionStandard::WiFi;
        
        Modem modem(manufacturer, model, type, standard, maxSpeed);
        modem.setPrice(price);
        if (isPoweredOn) modem.powerOn();
        if (isConnected) modem.connect();
        
        list.addModem(modem);
    }
    
    file.close();
    return true;
}

bool Database::writeToFile(const DoublyLinkedList& list) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи: " << filename << std::endl;
        return false;
    }
    
    Node* current = list.head;
    while (current != nullptr) {
        file << current->data.getManufacturer() << " "
             << current->data.getModel() << " "
             << current->data.getTypeString() << " "
             << current->data.getStandardString() << " "
             << current->data.getPrice() << " "
             << current->data.getMaxSpeed() << " "
             << current->data.getConnectionStatus() << " "
             << current->data.getPowerStatus() << "\n";
        current = current->next;
    }
    
    file.close();
    return true;
}

void Database::generateSampleData(DoublyLinkedList& list) {
    // Добавляем 15 образцовых модемов
    list.addModem(Modem("Cisco", "DPC3008", ModemType::Cable, ConnectionStandard::DOCSIS, 340.0, 120.0));
    list.addModem(Modem("TP-Link", "Archer VR600", ModemType::DSL, ConnectionStandard::VDSL, 100.0, 80.0));
    list.addModem(Modem("Huawei", "EchoLife HG8245H", ModemType::Fiber, ConnectionStandard::DOCSIS, 1000.0, 150.0));
    list.addModem(Modem("Zyxel", "VMG1312-B10B", ModemType::DSL, ConnectionStandard::ADSL, 24.0, 40.0));
    list.addModem(Modem("Netgear", "CM700", ModemType::Cable, ConnectionStandard::DOCSIS, 1400.0, 200.0));
    list.addModem(Modem("Asus", "DSL-AC68U", ModemType::DSL, ConnectionStandard::VDSL, 90.0, 70.0));
    list.addModem(Modem("D-Link", "DSL-2750U", ModemType::DSL, ConnectionStandard::ADSL, 15.0, 30.0));
    list.addModem(Modem("Motorola", "MB8600", ModemType::Cable, ConnectionStandard::DOCSIS, 1800.0, 250.0));
    list.addModem(Modem("Sagemcom", "Fast 5364", ModemType::DSL, ConnectionStandard::VDSL, 70.0, 60.0));
    list.addModem(Modem("Technicolor", "TG789vac", ModemType::DSL, ConnectionStandard::VDSL, 85.0, 65.0));
    list.addModem(Modem("Belkin", "F9K1106", ModemType::Cable, ConnectionStandard::DOCSIS, 110.0, 90.0));
    list.addModem(Modem("Linksys", "XAC1900", ModemType::Cable, ConnectionStandard::DOCSIS, 130.0, 100.0));
    list.addModem(Modem("Synology", "MR2200ac", ModemType::Wireless, ConnectionStandard::WiFi, 200.0, 120.0));
    list.addModem(Modem("Ubiquiti", "Amplifi HD", ModemType::Wireless, ConnectionStandard::WiFi, 180.0, 110.0));
    list.addModem(Modem("MikroTik", "hAP ac2", ModemType::Wireless, ConnectionStandard::WiFi, 150.0, 95.0));
}
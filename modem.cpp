#include "modem.h"
#include <iostream>

Modem::Modem() : NetworkDevice(), type(ModemType::DialUp), 
                standard(ConnectionStandard::V32), maxSpeed(0.056), isConnected(false) {}

Modem::Modem(const std::string& manuf, const std::string& mdl, ModemType tp,
    ConnectionStandard std, double speed, double prc) : 
    NetworkDevice(manuf, mdl), type(tp), standard(std), 
    maxSpeed(speed), isConnected(false) {}

Modem::~Modem() {
    std::cout << "Модем " << getManufacturer() << " " << getModel() << " уничтожен." << std::endl;
}

void Modem::setType(ModemType tp) {
    type = tp;
}

ModemType Modem::getType() const {
    return type;
}

std::string Modem::getTypeString() const {
    switch(type) {
        case ModemType::DialUp: return "Dial-Up";
        case ModemType::DSL: return "DSL";
        case ModemType::Cable: return "Cable";
        case ModemType::Fiber: return "Fiber";
        case ModemType::Wireless: return "Wireless";
        default: return "Unknown";
    }
}

void Modem::setStandard(ConnectionStandard std) {
    standard = std;
}

ConnectionStandard Modem::getStandard() const {
    return standard;
}

std::string Modem::getStandardString() const {
    switch(standard) {
        case ConnectionStandard::V32: return "V.32";
        case ConnectionStandard::V34: return "V.34";
        case ConnectionStandard::V90: return "V.90";
        case ConnectionStandard::ADSL: return "ADSL";
        case ConnectionStandard::VDSL: return "VDSL";
        case ConnectionStandard::DOCSIS: return "DOCSIS";
        case ConnectionStandard::LTE: return "LTE";
        case ConnectionStandard::WiFi: return "WiFi";
        default: return "Unknown";
    }
}

void Modem::setMaxSpeed(double speed) {
    maxSpeed = speed;
}

double Modem::getMaxSpeed() const {
    return maxSpeed;
}

bool Modem::getConnectionStatus() const {
    return isConnected;
}

void Modem::connect() {
    if (getPowerStatus()) {
        isConnected = true;
        std::cout << "Установлено соединение. Скорость: " << maxSpeed << " Мбит/с" << std::endl;
    } else {
        std::cout << "Ошибка: модем выключен!" << std::endl;
    }
}

void Modem::disconnect() {
    isConnected = false;
    std::cout << "Соединение разорвано." << std::endl;
}

void Modem::powerOn() {
    NetworkDevice::powerOn();
    std::cout << "Модем инициализирован и готов к работе." << std::endl;
}

void Modem::powerOff() {
    if (isConnected) {
        disconnect();
    }
    NetworkDevice::powerOff();
}

void Modem::displayInfo() const {
    NetworkDevice::displayInfo();
    std::cout << "Тип модема: " << getTypeString() << std::endl;
    std::cout << "Стандарт связи: " << getStandardString() << std::endl;
    std::cout << "Макс. скорость: " << maxSpeed << " Мбит/с" << std::endl;
    std::cout << "Состояние соединения: " << (isConnected ? "Установлено" : "Отсутствует") << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Modem& modem) {
    os << modem.getManufacturer() << " " << modem.getModel() << " (" << modem.getTypeString() 
       << "), " << modem.getStandardString() << ", " << modem.maxSpeed << " Мбит/с";
    return os;
}
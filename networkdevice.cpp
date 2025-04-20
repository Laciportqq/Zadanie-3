#include "networkdevice.h"
#include <iostream>

NetworkDevice::NetworkDevice() : manufacturer("Unknown"), model("Unknown"), isPoweredOn(false) {}

NetworkDevice::NetworkDevice(const std::string& manuf, const std::string& mdl) : 
    manufacturer(manuf), model(mdl), isPoweredOn(false) {}

NetworkDevice::~NetworkDevice() {
    std::cout << "Сетевое устройство " << manufacturer << " " << model << " уничтожено." << std::endl;
}

void NetworkDevice::setManufacturer(const std::string& manuf) {
    manufacturer = manuf;
}

std::string NetworkDevice::getManufacturer() const {
    return manufacturer;
}

void NetworkDevice::setModel(const std::string& mdl) {
    model = mdl;
}

std::string NetworkDevice::getModel() const {
    return model;
}

bool NetworkDevice::getPowerStatus() const {
    return isPoweredOn;
}

void NetworkDevice::powerOn() {
    isPoweredOn = true;
    std::cout << "Сетевое устройство включено." << std::endl;
}

void NetworkDevice::powerOff() {
    isPoweredOn = false;
    std::cout << "Сетевое устройство выключено." << std::endl;
}

void NetworkDevice::displayInfo() const {
    std::cout << "=== Информация о сетевом устройстве ===" << std::endl;
    std::cout << "Производитель: " << manufacturer << std::endl;
    std::cout << "Модель: " << model << std::endl;
    std::cout << "Состояние питания: " << (isPoweredOn ? "Включен" : "Выключен") << std::endl;
}
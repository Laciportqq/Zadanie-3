#ifndef NETWORKDEVICE_H
#define NETWORKDEVICE_H

#include <string>

class NetworkDevice {
protected:
    std::string manufacturer;
    std::string model;
    bool isPoweredOn;

public:
    NetworkDevice();
    NetworkDevice(const std::string& manuf, const std::string& mdl);
    virtual ~NetworkDevice();

    void setManufacturer(const std::string& manuf);
    std::string getManufacturer() const;
    
    void setModel(const std::string& mdl);
    std::string getModel() const;
    
    bool getPowerStatus() const;
    
    virtual void powerOn();
    virtual void powerOff();
    virtual void displayInfo() const;
};

#endif 
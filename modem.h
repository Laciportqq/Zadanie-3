#ifndef MODEM_H
#define MODEM_H

#include "networkdevice.h"
#include <iostream>
#include <string>

enum class ModemType {
    DialUp,
    DSL,
    Cable,
    Fiber,
    Wireless
};

enum class ConnectionStandard {
    V32,
    V34,
    V90,
    ADSL,
    VDSL,
    DOCSIS,
    LTE,
    WiFi,
    GPON
};

class Modem : public NetworkDevice {
    private:
    ModemType type;
    ConnectionStandard standard;
    double maxSpeed;
    double price;
    bool isConnected;

public:
    Modem();
    Modem(const std::string& manuf = "Unknown", const std::string& mdl = "Unknown",
        ModemType tp = ModemType::DialUp, ConnectionStandard std = ConnectionStandard::V32,
        double speed = 0.0, double prc = 0.0);
    ~Modem() override;

    void setType(ModemType tp);
    ModemType getType() const;
    std::string getTypeString() const;

    void setPrice(double prc) { price = prc; }
    double getPrice() const { return price; }
    
    void setStandard(ConnectionStandard std);
    ConnectionStandard getStandard() const;
    std::string getStandardString() const;
    
    void setMaxSpeed(double speed);
    double getMaxSpeed() const;
    
    bool getConnectionStatus() const;

    void connect();
    void disconnect();
    
    void powerOn() override;
    void powerOff() override;
    void displayInfo() const override;
    
    friend std::ostream& operator<<(std::ostream& os, const Modem& modem);
};

#endif // MODEM_H
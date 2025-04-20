#ifndef DATABASE_H
#define DATABASE_H

#include "doublylinkedlist.h"
#include <fstream>
#include <string>

class Database {
private:
    std::string filename;
    
public:
    Database(const std::string& fname) : filename(fname) {}
    
    bool readFromFile(DoublyLinkedList& list);
    bool writeToFile(const DoublyLinkedList& list);
    void generateSampleData(DoublyLinkedList& list);
};

#endif 
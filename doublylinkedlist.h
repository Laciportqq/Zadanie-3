#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "modem.h"

class Node {
public:
    Modem data;
    Node* prev;
    Node* next;
    
    Node(const Modem& modem) : data(modem), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList();
    
    void addModem(const Modem& modem);
    bool deleteModem(const std::string& manufacturer, const std::string& model);
    bool editModem(const std::string& manufacturer, const std::string& model, const Modem& newModem);
    Modem* findModem(const std::string& manufacturer, const std::string& model) const;
    void displayAll() const;
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return false; } 
    int getSize() const { return size; }
    

    friend class Database;
};

#endif 
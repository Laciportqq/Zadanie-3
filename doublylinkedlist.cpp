#include "doublylinkedlist.h"
#include <iostream>

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::addModem(const Modem& modem) {
    Node* newNode = new Node(modem);
    
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

bool DoublyLinkedList::deleteModem(const std::string& manufacturer, const std::string& model) {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data.getManufacturer() == manufacturer && 
            current->data.getModel() == model) {
            
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;
            
            delete current;
            size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool DoublyLinkedList::editModem(const std::string& manufacturer, const std::string& model, const Modem& newModem) {
    Modem* modem = findModem(manufacturer, model);
    if (modem) {
        *modem = newModem;
        return true;
    }
    return false;
}

Modem* DoublyLinkedList::findModem(const std::string& manufacturer, const std::string& model) const {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data.getManufacturer() == manufacturer && 
            current->data.getModel() == model) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

void DoublyLinkedList::displayAll() const {
    if (isEmpty()) {
        std::cout << "Список модемов пуст." << std::endl;
        return;
    }
    
    Node* current = head;
    int index = 1;
    
    std::cout << "=== Список всех модемов ===" << std::endl;
    while (current != nullptr) {
        std::cout << index++ << ". " << current->data << std::endl;
        current = current->next;
    }
}
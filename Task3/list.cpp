#include "list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::insertBeforeEverySecond(int M) {
    if (isEmpty() || head->next == nullptr) return;

    Node* current = head;
    int position = 1;

    while (current != nullptr && current->next != nullptr) {
        if (position % 2 == 1) {
            Node* newNode = new Node(M);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;

            if (current == nullptr) {
                tail = newNode;
            }
        } else {
            current = current->next;
        }
        position++;
    }
}

void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void* LinkedList::getLastNodeAddress() const {
    return static_cast<void*>(tail);
}

int LinkedList::getLastNodeValue() const {
    return tail ? tail->data : -1; // -1 или другое значение по умолчанию
}


void LinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}


bool LinkedList::isEmpty() const {
    return head == nullptr;
}

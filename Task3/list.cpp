#include "list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::append(int value) {
    ListNode* newNode = new ListNode(value);
    if (isEmpty()) {
        head_ = tail_ = newNode;
    } else {
        tail_->next = newNode;
        tail_ = newNode;
    }
}

void LinkedList::insertBeforeEverySecond(int M) {
    if (isEmpty() || head_->next == nullptr) return;

    ListNode* current = head_;
    int position = 1;

    while (current != nullptr && current->next != nullptr) {
        if (position % 2 == 1) {
            ListNode* newNode = new ListNode(M);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;

            if (current == nullptr) {
                tail_ = newNode;
            }
        } else {
            current = current->next;
        }
        position++;
    }
}

void LinkedList::clear() {
    while (head_ != nullptr) {
        ListNode* temp = head_;
        head_ = head_->next;
        delete temp;
    }
    tail_ = nullptr;
}

bool LinkedList::isEmpty() const {
    return head_ == nullptr;
}

void* LinkedList::getLastNodeAddress() const {
    return static_cast<void*>(tail_);
}

int LinkedList::getLastNodeValue() const {
    return tail_ ? tail_->data : -1;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    ListNode* current = list.head_;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

std::istream& operator>>(std::istream& is, LinkedList& list) {
    int value;
    is >> value;
    list.append(value);
    return is;
}

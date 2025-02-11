#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = next = nullptr;
    }
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void reverseDLL(Node*& head) {
    if (head == nullptr || head->next == nullptr)
        return; 

    Node* temp = nullptr;
    Node* current = head;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }

    if (temp != nullptr)
        head = temp->prev;
}


void display(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Original List:" << endl;
    display(head);

    reverseDLL(head);

    cout << "Reversed List:" << endl;
    display(head);

    return 0;
}
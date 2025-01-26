#include "MyList.hpp"

MyList::~MyList()
{
    clear();
}

void MyList::add(AMateria* m)
{
    Node* newNode = new Node(m);
    newNode->next = head;
    head = newNode;
}

void MyList::clear()
{
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->materia;
        delete current;
        current = next;
    }
    head = nullptr;
}
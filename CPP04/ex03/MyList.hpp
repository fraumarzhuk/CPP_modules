#ifndef MYLIST_HPP
#define MYLIST_HPP
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "colors.hpp"

class AMateria;

class MyList
{
private:
    struct Node {
        AMateria* materia;
        Node* next;
        Node(AMateria* m) : materia(m), next(nullptr) {}
    };

    Node* head;
public:
    MyList() : head(nullptr) {}
    ~MyList();
    void add(AMateria* m);
    void clear();
};

#endif

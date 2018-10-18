#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <assert.h>
#include "list_node.h"

template <class T> class List{
    public:
        List();
        ~List();
        void Insert(T item);
        void InsertFirst(T item);
        void InsertLast(T item);
        bool IsEmpty();
        void GoThrough();
    private:
        Node<T> *header;
        Node<T> *first;
        Node<T> *last;
        int num_items;
        bool Comparator(T item1, T item2);

};

template <class T>
List<T>::List(){
    this->header = new Node<T>();
    this->first = nullptr;
    this->last = nullptr;
    this->num_items = 0;
}

/* We could do this on 2 different ways:
 * -We delete the header only and let each node delete its sucessor.
 * -We delete everything on the list as we go through it.
 *  I'll start by doing it the iterative way since it might be better.
 */

template <class T>
List<T>::~List(){
    Node<T> *aux_node = this->header;
    Node<T> *delete_node = aux_node;

    while (aux_node != nullptr){
        aux_node = aux_node->getNext();
        delete delete_node;
        delete_node = aux_node;
    }
}

template <class T>
void List<T>::Insert(T item){
    Node<T> *aux_node = this->first;

    while (aux_node != nullptr && Comparator(item, aux_node->getItem())){   
        aux_node = aux_node->getNext();
    }

    if (aux_node == nullptr) InsertLast(item);
    else if (aux_node == this->first) InsertFirst(item);
    else {
        Node<T> *new_item = new Node<T>(item);
        Node<T> *previous_node = aux_node->getPrevious();

        previous_node->setNext(new_item);
        new_item->setPrevious(previous_node);
        new_item->setNext(aux_node);
        aux_node->setPrevious(new_item);
    }
}

template <class T>
bool List<T>::Comparator(T item1, T item2){
    if (item1 > item2) return true;
    else return false;
}

//We're not letting the first node know its precedessor is the header
template <class T>
void List<T>::InsertFirst(T item){
    Node<T> *new_item = new Node<T>(item);
    Node<T> *aux_node = this->first;
    
    this->header->setNext(new_item);
    new_item->setNext(aux_node);
    if (aux_node != nullptr) aux_node->setPrevious(new_item);

    if (this->num_items == 0){
        this->last = new_item;
    }
    this->first = new_item;
    this->num_items++;
}


template <class T>
void List<T>::InsertLast(T item){
    Node<T> *new_item = new Node<T>(item);
   
    if (this->last == nullptr){
        this->header->setNext(new_item);
        this->first = new_item;
        this->last = new_item;
    } else {
        this->last->setNext(new_item);
        new_item->setPrevious(this->last);
        this->last = new_item;
    }
}

template <class T>
bool List<T>::IsEmpty(){
    if (this->num_items == 0) return true;
    else return false;
}

template <class T>
void List<T>::GoThrough(){
    Node<T> *aux_node = this->first;
    int i = 0;

    while(aux_node != nullptr){
	std::cout << "Item " << i << ": ";
        std::cout << aux_node->getItem() << std::endl;
	if (aux_node != this->first) std::cout << "Anterior: " << aux_node->getPrevious()->getItem() << std::endl;
	if (aux_node != this->last) std::cout << "Siguiente: " << aux_node->getNext()->getItem() << std::endl;
        aux_node = aux_node->getNext();
	i++;
    }
}




#endif // LIST_H_

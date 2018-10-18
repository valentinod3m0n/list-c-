#ifndef NODE_H_
#define NODE_H_

#include <assert.h>

template<class T> class Node{
    public:
        Node();
        Node(T item);
        ~Node();
        T getItem();
        Node<T>* getNext();
        Node<T>* getPrevious();
        void setNext(Node* new_next);
        void setPrevious(Node* new_previous);
    private:
        Node<T>* previous;
        Node<T>* next;
        T item;
};

template <class T>
Node<T>::Node(){
    this->previous = nullptr;
    this->next = nullptr;
}
template <class T>
Node<T>::Node(T new_item){
    this->previous = nullptr;
    this->next = nullptr;
    this->item = new_item;
}

template <class T>
Node<T>::~Node(){}

template <class T>
T Node<T>::getItem(){
    return this->item;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

template <class T>
Node<T>* Node<T>::getPrevious(){
    return this->previous;
}

template <class T>
void Node<T>::setNext(Node<T>* new_next){
    this->next = new_next;
}

template <class T>
void Node<T>::setPrevious(Node<T>* new_previous){
    this->previous = new_previous;
}

#endif //NODE_H_

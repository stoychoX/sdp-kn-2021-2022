#ifndef __LINKED_QUEUE_CPP
#define __LINKED_QUEUE_CPP

#include <iostream>
#include "linked_queue.h"

// Методът е вътрешен и предполага, че за front && back няма заделена памет
template <typename T>
void LinkedQueue<T>::copyQueue(LinkedQueue<T> const& queue) {
    // проверка дали queue e празната опашка
    // front = back = nullptr
    QueueElement<T>* elemPtr = queue.front;
    while (elemPtr) {
        push(elemPtr->data);
        elemPtr = elemPtr->next;
    }
}

template <typename T>
void LinkedQueue<T>::eraseQueue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
LinkedQueue<T>::LinkedQueue() : front(nullptr), back(nullptr) {}

template <typename T>
LinkedQueue<T>::LinkedQueue(LinkedQueue<T> const& queue) {
    copyQueue(queue);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(LinkedQueue<T> const& queue) {
    if (this != &queue) {
        eraseQueue();
        copyQueue(queue);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    eraseQueue();
}

template <typename T>
bool LinkedQueue<T>::empty() const {
    return front == nullptr;
}

// Сложност O(1)
template <typename T>
void LinkedQueue<T>::push(T const& newElemData) {
    QueueElement<T>* newElemPtr = new QueueElement<T>;
    newElemPtr->data = newElemData;
    newElemPtr->next = nullptr;

    if (!empty()) {
        // Опашката не е празна и елементът се слага като последен
        back->next = newElemPtr;
    }
    else {
        // Опашката е празна и елементът трябва да бъде в началото
        front = newElemPtr;
    }

    back = newElemPtr;
}

// Сложност O(1)
// Алтернативно решение е методът да бъде от тип void
template <typename T>
T LinkedQueue<T>::pop() {
    if (empty()) {
        std::cerr << "The queue is empty!" << std::endl;
        return T();
    }

    QueueElement<T>* delElemPtr = front;
    T result = head();

    // Премества се указателя към следващия елемент в опашката
    front = front->next;

    // Няма друг елемент в опашката и back трябва да бъде nullptr
    if (front == nullptr) {
        back = nullptr;
    }
    // Изтрива се заделената памет за елемента
    delete delElemPtr;

    return result;
}

template <typename T>
T& LinkedQueue<T>::head() {
    if (empty()) {
        std::cerr << "The queue is empty!" << std::endl;
    }

    return front->data;
}

template <typename T>
T const& LinkedQueue<T>::head() const {
    if (empty()) {
        std::cerr << "The queue is empty!" << std::endl;
    }

    return front->data;
}

#endif

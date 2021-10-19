#ifndef __LINKED_STACK_CPP
#define __LINKED_STACK_CPP

#include <iostream>
#include "linked_stack.h"
#include <cassert>

// Създаване на празен стек
template <typename T>
LinkedStack<T>::LinkedStack() {
    topPtr = nullptr;
}

// Проверка за празен стек
template <typename T>
bool LinkedStack<T>::empty() const {
    return topPtr == nullptr;
}

// Копиране на стек 
// Вариант 3 - чрез използване на допълнителен стек
template <typename T>
void LinkedStack<T>::copy(LinkedStack<T> const& ls) {
    topPtr = nullptr;

    StackElement<T>* p = ls.topPtr;
    LinkedStack<T> tmp;
    while (p != nullptr) {
        tmp.push(p->data);
        p = p->next;
    }
    while (!tmp.empty())
        push(tmp.pop());
}

// Изтриване на паметта за стека
template <typename T>
void LinkedStack<T>::erase() {
    // !!! delete topPtr;
    while (!empty()) {
        pop();
    }
}

// Конструктор за копиране
template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack<T> const& ls) {
    copy(ls);
}

// Деструктор
template <typename T>
LinkedStack<T>::~LinkedStack() {
    erase();
}

// Оператор за присвояване между два стека
template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T> const& ls) {
    if (this != &ls) {
        erase();
        copy(ls);
    }
    return *this;
}

// Добавяне на нов елемент
template <typename T>
void LinkedStack<T>::push(T const& x) {
    // Заделяне на памет за нов елемент
    StackElement<T>* newElemPtr = new StackElement<T>;
    
    // Записване на стойност за този нов елемент
    newElemPtr->data = x;
    
    // Създаване на връзка между новия елемент и стария връх на стека (вкл. nullptr)
    newElemPtr->next = topPtr;

    // Пренасочване на върха на стека към новия елемент
    topPtr = newElemPtr;
}

// Изтриване на елемента на върха на стека
// Алтернативно решение е методът да бъде от тип void
template <typename T>
T LinkedStack<T>::pop() {
    // assert(!empty()); // допълнителна проверка при debug
    if (empty()) {
        std::cerr << "Stack is empty" << std::endl;
        return T();
    }
    
    T result = top();
    
    // Насочване на временен указател към текущия връх на стека, който следва да бъде изтрит
    StackElement<T>* tempElemPtr = topPtr;

    // Насочване на върха на стека към предходния елемент
    topPtr = topPtr->next;
    
    // Изтриване на върха на стека
    delete tempElemPtr;
    
    return result;
}

template <typename T>
T const& LinkedStack<T>::top() const {
    assert(!empty());

    return topPtr->data;
}

template <typename T>
T& LinkedStack<T>::top() {
    assert(!empty());

    return topPtr->data;
}
#endif

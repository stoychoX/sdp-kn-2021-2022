#pragma once

template <typename T>
struct StackElement {
    T data;
    StackElement<T>* next;
};

template <typename T>
class LinkedStack  {
    // представяне
    StackElement<T>* topPtr; // указател към връх на стека

    void copy(LinkedStack const& ls);

    void erase();

public:
    // създаване на празен стек
    LinkedStack();

    // конструктор за копиране
    LinkedStack(LinkedStack const& ls);

    // операция за присвояване
    LinkedStack& operator=(LinkedStack const& ls);

    // деструктор
    ~LinkedStack();

    // move?

    // проверка за празнота на стек
    bool empty() const;

    // включване на елемент 
    void push(T const& x);

    // изключване на елемент
    T pop();

    // извличане последно включения елемент
    T const& top() const;

    // извличане последно включения елемент + възможност за неговата промяната
    T& top();
};


#ifndef __LINKED_QUEUE_H
#define __LINKED_QUEUE_H

template <typename T>
struct QueueElement {
	T data;
	QueueElement<T>* next;
};

template <typename T>
class LinkedQueue {
private:
	QueueElement<T>* front, * back;

	void copyQueue(LinkedQueue<T> const&);
	void eraseQueue();

public:
	// Създаване на празна опашка. Конструктор по подразбиране
	LinkedQueue();

	// Конструктор за копиране
	LinkedQueue(LinkedQueue<T> const&);
	
	// Операторна функция за присвояване
	LinkedQueue& operator=(LinkedQueue<T> const&); 

    // Деструктор
	~LinkedQueue();

	bool empty() const;
	void push(T const& x);
	T pop();
	T& head();
	T const & head() const;
};

#endif

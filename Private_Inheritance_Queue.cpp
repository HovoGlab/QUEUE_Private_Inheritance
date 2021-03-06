#include <iostream>

template <typename T>
class DoubleList {
public:
	DoubleList();
	void insert_head(T value);
	void insert_tail(T value);
	int get_size();
	void remuve(int pos);
	int find(T value);
	void print();

public:
	struct Node {
		T value;
		Node* next;
		Node* prev;
		Node() : next(nullptr), prev(nullptr) {}
	};

private:
	Node * m_head;
};

template <typename T>
DoubleList<T>::DoubleList() {
	m_head = nullptr;
}


template <typename T>
class Queue : private DoubleList<T> {
public:
	//Queue();
	void push_queue(T elem) {
		DoubleList<T>::insert_tail(elem);
	}
	void remuve_queue() {
		DoubleList<T>::remuve(0);
	}

	void print_queue() {
		DoubleList<T>::print();
	}
};



int main() {
	Queue<int> lst;
	lst.push_queue(25);
	lst.push_queue(15);
	lst.push_queue(5);
	lst.remuve_queue();
	lst.print_queue();
}

template <typename T>
void DoubleList<T>::insert_head(T value) {
		Node* tmp = new Node();
		tmp->value = value;
		tmp->next = m_head;
		tmp->prev = nullptr;
		if (m_head != nullptr) {
			m_head->prev = tmp;
		}
		m_head = tmp;
}

template <typename T>
void DoubleList<T>::insert_tail(T value) {
	if (m_head != nullptr) {
		Node* cur = m_head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = new Node();
		cur->next->value = value;
		cur->next->prev = cur;
	}
	else {
		insert_head(value);
	}
}

template <typename T>
void DoubleList<T>::remuve(int pos) {
	if (0 == pos) {
		Node* tmp = m_head;
		m_head = m_head->next;
		m_head->prev = nullptr;
		delete tmp;
	}
	else {
		Node* cur = m_head;
		int count = 1;
		while (count < pos) {
			cur = cur->next;
			++count;
		}
		Node* tmp = cur->next;
		cur->next = tmp->next;
		cur->prev = tmp->prev;
		delete tmp;
	}
}

template <typename T>
int DoubleList<T>::find(T value) {
	int pos = 0;
	Node* cur = m_head;
	while (cur && cur->value != value) {
		cur = cur->next;
		++pos;
	}

	return (pos == get_size()) ? -1 : pos;
}

template <typename T>
void DoubleList<T>::print() {
	Node* ptr = m_head;
	while (ptr != nullptr) {
		std::cout << "[ " << ptr->value << " ]";
		ptr = ptr->next;
	}
}

int DoubleList<int>::get_size() {
	Node* print = m_head;
	int tmp = -1;
	while (print != nullptr) {
		print = print->next;
		++tmp;
	}
	return tmp;
}




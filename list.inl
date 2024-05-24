#include "list.hpp"
template<typename T>
List<T>::List(const List<T>& other) : List() {
	Node* temp = other.head;
	while (temp) {
		this->push_back(temp->data);
		temp = temp->next;
	}
}

template<typename T>
List<T>::List(List<T>&& other)
{
	head = other.head;
	tail = other.tail;

	other.head = nullptr;
	other.tail = nullptr;
}

template<typename T>
List<T>::~List() {
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void List<T>::push_back(const T& value) {
	Node* newNode = new Node(value);
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

template<typename T>
void List<T>::push_front(const T& value) {
	Node* newNode = new Node(value);
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

template<typename T>
void List<T>::erase_front() {
	if (!head) {
		return;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}
}

template<typename T>
void List<T>::erase_back() {
	if (!head) {
		return;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	}
}

template<typename T>
bool List<T>::isEmpty() const {
	return !head;
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other) {
	if (this == &other) {
		return *this;
	}
	else {
		Node* temp = other.head;
		while (temp) {
			this->push_back(temp->data);
			temp = temp->next;
		}
	}
	return *this;
};

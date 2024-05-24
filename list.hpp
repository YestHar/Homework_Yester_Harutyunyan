#pragma once

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node next = nullptr;
        Node prev = nullptr;
        Node(const T& _data) : data(_data), next(nullptr), prev(nullptr) {};
    };
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    List() = default;
    List(const List<T>&);
    List(List<T>&& other);
    ~List();

    void push_back(const T&);
	void push_front(const T&);
	void erase_back();
	void erase_front();

	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(nullptr, tail);
	}

	bool isEmpty() const;

	List<T>& operator=(const List<T>&);
};

#include "list.inl"
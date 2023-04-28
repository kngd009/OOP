#pragma once
#include "Nod.h"

template <typename T>
class DoubleLinkedList {
	Node<T>* head, * tail;
	int size;

public :
	DoubleLinkedList();
	void PushOnFront(const T&);
	void PushOnBack(const T&);
	T PopFromBack();

	void PrintAll(void callback(const T& value)=nullptr);
	int GetCount();
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	head = tail = nullptr;
	this->size = 0;
}

template <typename T>
void DoubleLinkedList<T> ::PushOnFront(const T& valoare)
{
	if (size == 0)
	{
		Node<T>* newNode = new Node<T>(valoare);
		tail = head = newNode;
		size++;
	}
	else {
		Node<T>* newNode = new Node<T>(valoare);
		newNode->next = head;
		newNode->left = nullptr;
		head->left = newNode;
		head = newNode;
		size++;
	}
}

template <typename T>
void DoubleLinkedList<T> ::PushOnBack(const T& valoare)
{
	if (size == 0)
	{
		Node<T>* newNode = new Node<T>(valoare);
		head = tail = newNode;
		size++;
	} 
	else {
		Node<T>* newNode = new Node<T>(valoare);
		newNode->left = tail;
		tail->next = newNode;
		tail = newNode;
		size++;
	}
}


template <typename T>
T DoubleLinkedList<T> ::PopFromBack()
{
	if (size == 0)
	{
		tail = head = nullptr;
		return 0;
	}
	else
	{
		Node <T>* p = tail->left;
		T valoare = tail->value;
		delete tail;
		tail = p;
		this->size--;
		//tail->next = nullptr;
		return valoare;
	
	}
}
template <typename T>
void DoubleLinkedList<T> ::PrintAll(void callback(const T& value))
{
	std::cout << "Elements: " << GetCount() << " ";
	auto p = head;
	while (p)
	{
		callback(p->value);
		p = p->next;
	}
	std::cout << "\n";
}

template <typename T>
int DoubleLinkedList<T> ::GetCount()
{
	return this->size;
}
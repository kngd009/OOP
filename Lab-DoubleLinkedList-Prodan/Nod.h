#pragma once
template <typename T>
struct Node {
public:
	T value;
	Node<T>* next;
	Node<T>* left;
	Node(const T& val) {
		value = val;
		this->left = nullptr;
		this->next = nullptr;
	}
};
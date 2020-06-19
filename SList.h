#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct Node {

	T data;
	Node * next;
};

template <typename T>
class SList
{

public:

	SList() = default;
	bool isEmpty()const;
	void addHead(const T & element);
	void print()const;
	void addTail(const T &elem);
	void delHead();
	void delTail();
	void clear();
	SList(const SList &rigth);
	void insert(const T& data, int index);
	void deleteIndex(int index);
	int find(const int v);
	void reverse();
 
	~SList();
private:
	Node<T>*head = nullptr;//вказівник на перший
	Node <T>*findPrevTail();
	Node<T>*tail = nullptr;//вказівник на останній
	size_t size = 0;//kilkist vyzliv y spisky



	
};

template<typename T>
inline bool SList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline void SList<T>::addHead(const T & element)//додати вузол на початок
{

	auto newNode = new Node<T>{ element,nullptr };
	if (isEmpty()) {
		head=tail=newNode;
	}
	else {

		newNode->next = head;
		head = newNode;

	}
	++size;
}

template<typename T>
inline void SList<T>::print() const
{
	auto tmp = head;
	cout << "list : \t";
	while (tmp != nullptr) {
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void SList<T>::addTail(const T & elem)
{
	auto newNode = new Node<T>{ elem,nullptr };
	if (isEmpty()) {
		head = tail = newNode;

	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	++size;
}

template<typename T>
inline void SList<T>::delHead()
{

	if (isEmpty()) 
		return;

	auto del = head;
	head = head->next;
	if (head == nullptr) {
		tail = nullptr;
	}
	delete del;
	--size;
}

template<typename T>
inline void SList<T>::delTail()
{
	if(isEmpty()){
		return;
	}
	if (head == tail) {
		delHead();
	}
	else {
		auto prevTail = findPrevTail();
		delete tail;
		prevTail->next= nullptr;
		tail = prevTail;

		--size;
	}
}

template<typename T>
inline void SList<T>::clear()
{
	while (size) {
		delHead();
	}
}

template<typename T>
inline SList<T> ::SList(const SList & rigth):head(0),tail(0),size(0)
{
	Node<T> *tmp = rigth.head;
	while (tmp!=0)
	{
		this->addTail(tmp->data);
		tmp = tmp->next;
	}
	//cout << "list" << this << endl;
}

template<typename T>
inline void SList<T>::insert(const T & data, int index)
{
	int value = 0;
	if (index == 0) {
		addHead(data);
	}
	else {
		Node<T>* tmp = this->head;
		for (int i = 0; i < index -1; i++)
		{
			tmp = tmp->next;
		}
		             
		
		tmp->next = new Node<T>{ data, tmp->next };

		size++;        
		 
	}
}

template<typename T>
inline void SList<T>::deleteIndex(int index)
{
	if (index == 0) {
		delTail();
	}
	else {
		Node<T>*tmp = this->head;
		for (int i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		Node<T>*dell = tmp->next;
		tmp->next = dell->next;
		delete dell;
		size--;
	}
}

template<typename T>
inline int SList<T>::find(const int v)
{
   auto n = head;
	while (n)
	{
		if (n->data == v) {
			return n;
			n = n->next;
        }
	}
	return NULL;
}



template<typename T>
inline void SList<T>::reverse()
{
	 Node<T>*curr, *next, *prev = NULL;
	curr = head;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}



template<typename T>
inline SList<T>::~SList()
{
	cout << "destructor" << endl;
	clear();
}

template<typename T>
inline Node<T>* SList<T>::findPrevTail()
{
	if (isEmpty())
		return nullptr;
	auto tmp = head;
	while (tmp->next!=tail)
	
		tmp = tmp->next;
	
	return tmp;
}

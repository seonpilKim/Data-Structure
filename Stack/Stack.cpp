#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node* next;

	template <typename T>
	friend class Stack;
public:
	Node(const T& data) {
		this->data = data;
		this->next = nullptr;
	}
};

template <typename T>
class Stack {
private:
	Node<T>* head;
	Node<T>* delNode;
	int _size;

public:
	Stack() {
		this->head = this->delNode = nullptr;
		this->_size = 0;
	}

	template <typename T>
	void push(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		if (this->_size == 0) 
			this->head = newNode;
		else {
			newNode->next = this->head;
			this->head = newNode;
		}
		this->_size++;
	}
	
	void pop() {
		this->delNode = this->head;
		this->head = this->head->next;
		this->_size--;
		delete this->delNode;	
	}
	
	T top() const {
		return this->head->data;
	}
	
	int size() const {
		return this->_size;
	}
	
	bool empty() const {
		return (this->_size == 0 ? true : false);
	}
};


int main() {
	Stack<char> s;

	s.push('a');
	cout << s.top() << endl;
	cout << s.size() << endl;
	s.pop();
	cout << s.empty();

	return 0;
}

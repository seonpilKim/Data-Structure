#include <iostream>

using namespace std;

template <typename T> class Stack;

template <typename T>
class Node {
private:
	T data;
	Node* next;

	friend class Stack<T>;
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
	int _size;

public:
	Stack() {
		this->head = nullptr;
		this->_size = 0;
	}

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
		Node<T>* delNode = this->head;
		this->head = this->head->next;
		this->_size--;
		delete delNode;
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
	cout << s.empty() << endl;

	return 0;
}

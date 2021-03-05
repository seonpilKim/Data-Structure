#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node* next;

	template <typename T>
	friend class Queue;
public:
	Node(const T& data) {
		this->data = data;
		this->next = nullptr;
	}
};

template <typename T>
class Queue {
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* delNode;
	int _size;

public:
	Queue() {
		this->head = this->tail = this->delNode = nullptr;
		this->_size = 0;
	}

	template <typename T>
	void push(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		if (this->_size == 0)
			this->head = this->tail = newNode;
		else {
			this->tail->next = newNode;
			this->tail = newNode;
		}
		this->_size++;
	}

	void pop() {
		this->delNode = this->head;
		this->head = this->head->next;
		this->_size--;
		delete this->delNode;
	}

	T front() const {
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
	Queue<char> q;

	q.push('a');
	q.push('b');
	q.push('c');
	cout << q.front() << endl;
	cout << q.size() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.size() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.size() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.size() << endl;
	cout << q.empty();

	return 0;
}
#include <iostream>

using namespace std;

template <typename T>
class Deque {
private:
	template <typename T>
	class Node {
	private:
		T data;
		Node* next;
		Node* prev;

		friend class Deque<T>;
	public:
		Node(const T& data) 
			: data(data), next(nullptr), prev(nullptr) { }
	};

	Node<T>* head;
	Node<T>* tail;
	size_t _size;

public:
	Deque()
		: head(nullptr), tail(nullptr), _size(0) { }

	void push_back(const T& data) {
		Node<T>* newNode = new Node<T>(data);

		if (this->_size == 0)
			this->head = this->tail = newNode;
		else {
			this->tail->next = newNode;
			newNode->prev = this->tail;
			this->tail = newNode;
		}

		this->_size++;
	}
	
	void push_front(const T& data) {
		Node<T>* newNode = new Node<T>(data);

		if (this->_size == 0)
			this->head = this->tail = newNode;
		else {
			newNode->next = this->head;
			this->head->prev = newNode;
			this->head = newNode;
		}

		this->_size++;
	}

	void pop_back() {
		if (this->_size == 0)
			return;

		Node<T>* delNode = this->tail;
		if (this->_size > 1) {
			this->tail = this->tail->prev;
			this->tail->next = nullptr;
		}

		delete delNode;
		this->_size--;
	}

	void pop_front() {
		if (this->_size == 0)
			return;

		Node<T>* delNode = this->head;
		if (this->_size > 1) {
			this->head = this->head->next;
			this->head->prev = nullptr;
		}

		delete delNode;
		this->_size--;
	}

	T front() const {
		return this->head->data;
	}

	T back() const {
		return this->tail->data;
	}

	size_t size() const {
		return this->_size;
	}

	bool empty() const {
		return (this->_size == 0 ? true : false);
	}
};


int main() {
	Deque<int> dq;

	dq.push_back(3);
	cout << dq.front() << endl;
	cout << dq.back() << endl;
	dq.push_front(1);
	cout << dq.front() << endl;
	cout << dq.back() << endl;
	dq.pop_back();
	cout << dq.front() << endl;
	cout << dq.back() << endl;
	dq.pop_front();
	if (dq.empty()) cout << "empty" << endl;
	else cout << "not empty" << endl;
	dq.push_back(2);
	cout << dq.front() << endl;


	return 0;
}
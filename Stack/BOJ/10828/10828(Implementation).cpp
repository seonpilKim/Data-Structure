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
	Node<T>* delNode;
	int _size;

public:
	Stack() {
		this->head = this->delNode = nullptr;
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
	Stack<int> s;

	int T;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--) {
		string cmd;

		cin >> cmd;

		if (cmd == "push") {
			int data;

			cin >> data;
			s.push(data);
		}
		else if (cmd == "pop") {
			if (s.empty()) cout << "-1\n";
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << s.empty() << '\n';
		}
		else if (cmd == "top") {
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << '\n';
		}
	}

	return 0;
}
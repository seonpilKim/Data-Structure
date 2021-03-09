#include <iostream>

using namespace std;

class Node {
public:
	char c;
	Node* next;
	Node* prev;

	Node(char c) {
		this->c = c;
		this->next = this->prev = nullptr;
	}
};

class DoublyLinkedList {
public:
	Node* empty;
	Node* head;
	Node* tail;
	Node* curNode;

	DoublyLinkedList() {
		this->empty = this->head = this->tail = this->curNode = nullptr;
	}
	
	void insert(char c) {
		Node* newNode = new Node(c);
		if (this->curNode == nullptr) {
			this->head = this->tail = newNode;
			this->empty = new Node(' ');
			this->head->prev = this->empty;
			this->empty->next = this->head;
		}
		else {
			if (this->curNode == this->tail) {
				this->tail->next = newNode;
				newNode->prev = this->tail;
				this->tail = newNode;
			}
			else if (this->curNode == this->empty) {
				this->head->prev = newNode;
				newNode->next = this->head;
				this->head = newNode;
				this->head->prev = this->empty;
				this->empty->next = this->head;
			}
			else {
				this->curNode->next->prev = newNode;
				newNode->next = this->curNode->next;
				this->curNode->next = newNode;
				newNode->prev = this->curNode;
			}
		}
		this->curNode = newNode;
	}

	void remove() {
		if (this->curNode == this->empty || this->curNode == nullptr)
			return;
		Node* delNode = this->curNode;
		if (delNode == this->head) {
			this->head = this->head->next;
			this->head->prev = this->empty;
			this->empty->next = this->head;
		}
		else if (delNode == this->tail) 
			this->tail = this->tail->prev;
		else {
			this->curNode->prev->next = this->curNode->next;
			this->curNode->next->prev = this->curNode->prev;
		}
		this->curNode = this->curNode->prev;
		delete delNode;
	}

	void moveLeft() {
		if (this->curNode == this->empty || this->curNode == nullptr)
			return;
		this->curNode = this->curNode->prev;
	}

	void moveRight() {
		if (this->curNode == this->tail || this->curNode == nullptr)
			return;
		this->curNode = this->curNode->next;
	}

	void printStr() {
		this->curNode = this->head;
		while (this->curNode) {
			cout << this->curNode->c;
			this->curNode = this->curNode->next;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	DoublyLinkedList editor;
	string input;

	cin >> input;

	for (char c : input) {
		editor.insert(c);
	}

	int T;

	cin >> T;

	while (T--) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L')
			editor.moveLeft();
		else if (cmd == 'D')
			editor.moveRight();
		else if (cmd == 'B')
			editor.remove();
		else if (cmd == 'P') {
			char add;
			cin >> add;
			editor.insert(add);
		}
	}

	editor.printStr();

	return 0;
}
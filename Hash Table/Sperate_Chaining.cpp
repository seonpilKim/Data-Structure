#include <iostream>

using namespace std;

#define MAX 353333
#define EMPTY -1
#define ISITEM 1
#define NOITEM 0

struct chain {
	int key;
	int value;
	chain* next;
	chain() 
		: key(EMPTY), value(EMPTY), next(nullptr) {}
	chain(int key, int value)
		: key(key), value(value), next(nullptr) {}
};

struct cell {
	int flag;
	chain* next;
	cell()
		: flag(NOITEM), next(nullptr) {}
};


cell* hashArr[MAX];

int hashfunc(int idx) {
	return idx % MAX;
}

void Insert(int key, int value) {
	if (hashArr[hashfunc(key)]->flag == NOITEM) {
		hashArr[hashfunc(key)]->flag = ISITEM;
		hashArr[hashfunc(key)]->next = new chain(key, value);
	}
	else {
		chain* cur = hashArr[hashfunc(key)]->next;
		while (cur->next != nullptr) 
			cur = cur->next;
		cur->next = new chain(key, value);
	}
}

int Search(int key) {
	if (hashArr[hashfunc(key)]->flag == ISITEM) {
		chain* cur = hashArr[hashfunc(key)]->next;
		while (cur != nullptr) {
			if (cur->key == key) 
				return cur->value;
			cur = cur->next;
		}
	}

	return -1;
}

void Delete(int key) {
	if (hashArr[hashfunc(key)]->flag == ISITEM) {
		chain* cur = hashArr[hashfunc(key)]->next;
		if (cur->key == key) {
			if (cur->next == nullptr)
				hashArr[hashfunc(key)]->flag = NOITEM;
			hashArr[hashfunc(key)]->next = cur->next;
			delete cur;
		}
		else {
			while (cur) {
				if (cur->next->key == key) {
					chain* del = cur->next;
					cur->next = cur->next->next;
					delete del;
				}
				cur = cur->next;
			}
		}
	}
}

int main() {
	fill(hashArr, hashArr + MAX, new cell());
	Insert(1, 1);
	Insert(353334, 2);
	cout << Search(1) << endl;
	cout << Search(353334) << endl;
	Delete(1);
	cout << Search(353334) << endl;
	Delete(353334);
	int val = Search(353334);
	if (val == -1)
		cout << "NOITEM\n";
	else
		cout << val;

	return 0;
}
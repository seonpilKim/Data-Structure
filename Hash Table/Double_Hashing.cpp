#include <iostream>

using namespace std;

#define MAX 353333
#define EMPTY -1
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct cell {
	int key;
	int flag;
	int value;
	cell()
		: key(EMPTY), flag(NOITEM), value(EMPTY) {}
};

cell hashArr[MAX];

int hashfunc(int idx) {
	return idx % MAX;
}

int hashfunc2(int idx) {
	return (17 - (idx % 17));
}

void Insert(int key, int value) {
	int probing = 0;

	while (hashArr[hashfunc(hashfunc(key) + (probing * hashfunc2(key)))].flag == ISITEM)
		probing++;

	hashArr[hashfunc(hashfunc(key) + (probing * hashfunc2(key)))].key = key;
	hashArr[hashfunc(hashfunc(key) + (probing * hashfunc2(key)))].flag = ISITEM;
	hashArr[hashfunc(hashfunc(key) + (probing * hashfunc2(key)))].value = value;
}

int Search(int key) {
	int probing = 0;

	while (hashArr[hashfunc(hashfunc(key) + (probing * hashfunc2(key)))].flag != NOITEM) {
		if (hashArr[hashfunc(hashfunc(key) + (probing * hashfunc2(key)))].key == key)
			return hashArr[hashfunc(hashfunc(key) + (probing * hashfunc2(key)))].value;
		probing++;
	}

	return -1;
}

void Delete(int key) {
	int probing = 0;

	while (hashArr[hashfunc(hashfunc(key) + probing * hashfunc2(key))].flag != NOITEM) {
		if (hashArr[hashfunc(hashfunc(key) + probing * hashfunc2(key))].key == key) {
			hashArr[hashfunc(hashfunc(key) + probing * hashfunc2(key))].key = EMPTY;
			hashArr[hashfunc(hashfunc(key) + probing * hashfunc2(key))].flag = AVAILABLE;
			hashArr[hashfunc(hashfunc(key) + probing * hashfunc2(key))].value = EMPTY;
			return;
		}
		probing++;
	}
}

int main() {
	int T, N, M, key, value;

	cin >> T;

	while (T--) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> key >> value;
			Insert(key, value);
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> key;
			value = Search(key);
			if (value != -1)
				cout << value << endl;
			else
				cout << "NOITEM\n";
		}
	}
	return 0;
}
#include <iostream>
#include <vector>

#define MIN -1
#define MAX 1

using namespace std;

template <typename T>
class Heap {
private:
	vector<T> BST;
	int type;
	int root_idx;

	int par(int idx) const {
		return idx / 2;
	}
	
	int left(int idx) const {
		return 2 * idx;
	}

	int right(int idx) const {
		return 2 * idx + 1;
	}

	void swap(int idx, int paridx) {
		T temp = this->BST[idx];
		this->BST[idx] = this->BST[paridx];
		this->BST[paridx] = temp;
	}

	void UpHeap(int idx) {
		while (idx != this->root_idx && this->BST[idx] * this->type > this->BST[par(idx)] * this->type) {
			swap(idx, par(idx));
			idx = par(idx);
		}
	}

	void DownHeap() {
		int idx = this->root_idx;

		while (true) {
			if (right(idx) <= this->BST.size() - 1) {
				if (this->BST[left(idx)] * this->type >= this->BST[right(idx)] * this->type) {
					if (this->BST[left(idx)] * this->type > this->BST[idx] * this->type) {
						swap(idx, left(idx));
						idx = left(idx);
					}
					else
						break;
				}
				else {
					if (this->BST[right(idx)] * this->type > this->BST[idx] * this->type) {
						swap(idx, right(idx));
						idx = right(idx);
					}
					else
						break;
				}
			}
			else if (left(idx) <= this->BST.size() - 1) {
				if (this->BST[left(idx)] * this->type > this->BST[idx] * this->type) {
					swap(idx, left(idx));
					idx = left(idx);
				}
				else
					break;
			}
			else
				break;
		}
	}

public:
	Heap(const int& type) {
		this->type = type;
		this->root_idx = 1;
	}

	void insert(const T& data) {
		if (this->BST.size() == 0)
			this->BST.push_back(data);
		this->BST.push_back(data);
		UpHeap(this->BST.size() - 1);
	}

	void remove() {
		this->BST[this->root_idx] = this->BST[this->BST.size() - 1];
		this->BST.pop_back();
		DownHeap();
	}

	T peek() const {
		return this->BST[this->root_idx];
	}

	void print() const {
		for (int i = this->root_idx; i <= this->BST.size() - 1; i++) {
			cout << this->BST[i] << ' ';
		}
		cout << '\n';
	}

};

int main() {
	Heap<int> heap(MAX);

	heap.insert(9);
	cout << heap.peek() << endl;
	heap.insert(7);
	cout << heap.peek() << endl;
	heap.insert(6);
	cout << heap.peek() << endl;
	heap.insert(5);
	cout << heap.peek() << endl;
	heap.insert(4);
	cout << heap.peek() << endl;
	heap.insert(3);
	cout << heap.peek() << endl;
	heap.insert(2);
	cout << heap.peek() << endl;
	heap.insert(2);
	cout << heap.peek() << endl;
	heap.insert(1);
	cout << heap.peek() << endl;
	heap.insert(3);
	cout << heap.peek() << endl;
	heap.insert(8);
	cout << heap.peek() << endl;
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();
	heap.remove();
	heap.print();

	return 0;
}
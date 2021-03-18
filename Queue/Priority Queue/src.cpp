#include <iostream>
#include <vector>

using namespace std;

template <typename T1, typename T2>
class Priority_queue {
private:
	vector<pair<T1, T2>> BST;
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
		pair<T1, T2> temp = this->BST[idx];
		this->BST[idx] = this->BST[paridx];
		this->BST[paridx] = temp;
	}

	void UpHeap(int idx) {
		while (idx != this->root_idx && this->BST[idx].first > this->BST[par(idx)].first) {
			swap(idx, par(idx));
			idx = par(idx);
		}
	}

	void DownHeap() {
		int idx = this->root_idx;

		while (true) {
			if (right(idx) <= this->BST.size() - 1) {
				if (this->BST[left(idx)].first >= this->BST[right(idx)].first) {
					if (this->BST[left(idx)].first > this->BST[idx].first) {
						swap(idx, left(idx));
						idx = left(idx);
					}
					else
						break;
				}
				else {
					if (this->BST[right(idx)].first > this->BST[idx].first) {
						swap(idx, right(idx));
						idx = right(idx);
					}
					else
						break;
				}
			}
			else if (left(idx) <= this->BST.size() - 1) {
				if (this->BST[left(idx)].first > this->BST[idx].first) {
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
	Priority_queue() {
		this->root_idx = 1;
	}

	void insert(const pair<T1, T2>& element) {
		if (this->BST.size() == 0)
			this->BST.push_back(element);
		this->BST.push_back(element);
		UpHeap(this->BST.size() - 1);
	}

	void remove() {
		this->BST[this->root_idx] = this->BST[this->BST.size() - 1];
		this->BST.pop_back();
		DownHeap();
	}

	T2 peek() const {
		return this->BST[this->root_idx].second;
	}

	void print() const {
		for (int i = this->root_idx; i <= this->BST.size() - 1; i++) {
			cout << this->BST[i].second << ' ';
		}
		cout << '\n';
	}

};

int main() {
	Priority_queue<int, int> pq;
	
	pq.insert(make_pair(9, 9));
	cout << pq.peek() << endl;
	pq.insert(make_pair(7, 7));
	cout << pq.peek() << endl;
	pq.insert(make_pair(6, 6));
	cout << pq.peek() << endl;
	pq.insert(make_pair(5, 5));
	cout << pq.peek() << endl;
	pq.insert(make_pair(4, 4));
	cout << pq.peek() << endl;
	pq.insert(make_pair(3, 3));
	cout << pq.peek() << endl;
	pq.insert(make_pair(2, 2));
	cout << pq.peek() << endl;
	pq.insert(make_pair(2, 2));
	cout << pq.peek() << endl;
	pq.insert(make_pair(1, 1));
	cout << pq.peek() << endl;
	pq.insert(make_pair(3, 3));
	cout << pq.peek() << endl;
	pq.insert(make_pair(8, 8));
	cout << pq.peek() << endl;
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();
	pq.remove();
	pq.print();

	return 0;
}
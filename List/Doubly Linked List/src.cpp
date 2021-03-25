#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class DoublyLinkedList {
private:
	template <typename T>
	class Node {
	private:
		T element;
		Node<T>* next;
		Node<T>* prev;

		Node() { this->next = this->prev = nullptr; }
		Node(const T& element) {
			this->element = element;
			this->next = this->prev = nullptr;
		}

		friend class DoublyLinkedList<T>;
	};

	int _size;
	Node<T>* head;
	Node<T>* tail;
	T* tmplist;

	void merge(int left, int right) noexcept {
		T* arr2 = new T[size()];
		int mid = (left + right) / 2;
		int i = left;
		int j = mid + 1;
		int k = left;

		while (i <= mid && j <= right) {
			if (this->tmplist[i] <= this->tmplist[j])
				arr2[k++] = this->tmplist[i++];
			else
				arr2[k++] = this->tmplist[j++];
		}

		int tmp = i > mid ? j : i;

		while (k <= right)
			arr2[k++] = this->tmplist[tmp++];

		for (int i = left; i <= right; i++)
			this->tmplist[i] = arr2[i];
	}

	void partition(int left, int right) noexcept {
		if (left < right) {
			int mid = (left + right) / 2;

			partition(left, mid);
			partition(mid + 1, right);
			merge(left, right);
		}
	}

public:
	DoublyLinkedList() {
		this->head = new Node<T>();
		this->tail = new Node<T>();
		this->head->next = this->tail;
		this->tail->prev = this->head;
		this->_size = 0;
	}
	~DoublyLinkedList() {
		clear();
		delete this->head;
		delete this->tail;
	}

	class Iterator {
	private:
		Node<T>* curNode;
		Iterator(Node<T>* curNode) {
			this->curNode = curNode;
		}

		friend class DoublyLinkedList<T>;

	public:
		T& operator*() noexcept {
			return this->curNode->element;
		}

		bool operator ==(const Iterator& ptr) const noexcept {
			return this->curNode == ptr.curNode;
		}

		bool operator !=(const Iterator& ptr) const noexcept {
			return this->curNode != ptr.curNode;
		}

		Iterator& operator++() noexcept {
			this->curNode = this->curNode->next;
			return *this;
		}

		Iterator& operator--() noexcept {
			this->curNode = this->curNode->prev;
			return *this;
		}
	};

	class rIterator {
	private:
		Node<T>* curNode;
		rIterator(Node<T>* curNode) {
			this->curNode = curNode;
		}

		friend class DoublyLinkedList<T>;

	public:
		T& operator*() noexcept {
			return this->curNode->element;
		}

		bool operator ==(const rIterator& ptr) const noexcept {
			return this->curNode == ptr.curNode;
		}

		bool operator !=(const rIterator& ptr) const noexcept {
			return this->curNode != ptr.curNode;
		}

		rIterator& operator--() noexcept {
			this->curNode = this->curNode->next;
			return *this;
		}

		rIterator& operator++() noexcept {
			this->curNode = this->curNode->prev;
			return *this;
		}
	};

	Iterator begin() const noexcept {
		return Iterator(this->head->next);
	}

	rIterator rbegin() const noexcept {
		return rIterator(this->tail->prev);
	}

	Iterator end() const noexcept {
		return Iterator(this->tail);
	}

	rIterator rend() const noexcept {
		return rIterator(this->head);
	}

	void sort() noexcept {
		this->tmplist = new T[size()];
		int idx = 0;
		for (Iterator iter = begin(); iter != end(); ++iter) {
			this->tmplist[idx] = iter.curNode->element;
			idx++;
		}

		partition(0, size() - 1);

		idx = 0;
		for (Iterator iter = begin(); iter != end(); ++iter) {
			iter.curNode->element = this->tmplist[idx];
			idx++;
		}

		delete[] tmplist;
	}

	void unique() noexcept {
		stack<Node<T>*> delNodes;
		Iterator iter = begin();
		Node<T>* first = iter.curNode;
		T curElement = first->element;

		while (++iter != end()) {
			if (curElement == iter.curNode->element) 
				delNodes.push(iter.curNode);
			else {
				if (!delNodes.empty()) {
					first->next = iter.curNode;
					iter.curNode->prev = first;

					while (!delNodes.empty()) {
						delete delNodes.top();
						delNodes.pop();
					}
				}

				first = iter.curNode;
				curElement = first->element;
			}
		}

		if (!delNodes.empty()) {
			first->next = iter.curNode;
			iter.curNode->prev = first;

			while (!delNodes.empty()) {
				delete delNodes.top();
				delNodes.pop();
			}
		}
	}

	void clear() noexcept {
		Node<T>* curNode = this->head->next;

		while (curNode != this->tail) {
			Node<T>* delNode = curNode;
			curNode = curNode->next;
			delete delNode;
		}

		this->head->next = this->tail;
		this->tail->prev = this->head;
		this->_size = 0;
	}

	void insert(const Iterator& iter, const T& element) noexcept {
		Node<T>* curNode = iter.curNode;
		Node<T>* prevNode = curNode->prev;
		Node<T>* newNode = new Node<T>(element);

		newNode->next = curNode;
		curNode->prev = newNode;
		newNode->prev = prevNode;
		prevNode->next = newNode;

		this->_size++;
	}

	void push_front(const T& element) noexcept { insert(begin(), element); }
	void push_back(const T& element) noexcept { insert(end(), element); }

	void erase(const Iterator& iter) noexcept {
		Node<T>* curNode = iter.curNode;
		Node<T>* nextNode = curNode->next;
		Node<T>* prevNode = curNode->prev;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete curNode;
		empty() ? this->_size = 0 : this->_size--;
	}

	void pop_front() noexcept { erase(begin()); }
	void pop_back() noexcept { erase(--end()); }

	void remove(const T& element) noexcept {
		for (Iterator iter = begin(); iter != end(); ++iter) {
			if (iter.curNode->element == element) {
				erase(iter);
				return;
			}
		}
	}

	T front() const noexcept(noexcept(!empty())) {
		return this->head->next->element;
	}

	T back() const noexcept(noexcept(!empty())) {
		return this->tail->prev->element;
	}

	int size() const noexcept {
		return this->_size;
	}

	bool empty() const noexcept {
		return size() > 0 ? false : true;
	}
};


int main() {
	DoublyLinkedList<int> list;
	list.clear();
	cout << "push back 3\n";
	list.push_back(3);
	cout << "push front 100\n";
	list.insert(list.begin(), 100);
	cout << "push front 1\n";
	list.push_front(1);
	cout << "front : " << list.front() << endl;
	cout << "push front 2\n";
	list.push_front(2);
	cout << "front : " << list.front() << endl;
	cout << "pop front\n";
	list.pop_front();
	cout << "front : " << list.front() << endl;
	cout << "erase front\n";
	list.erase(list.begin());
	cout << "front : " << list.front() << endl;
	cout << "push back 3\n";
	list.push_back(3);
	cout << "insert front 30\n";
	list.insert(list.begin(), 30);
	cout << "front : " << list.front() << endl;
	cout << "insert back 20\n";
	list.insert(list.end(), 20);
	cout << "back : " << list.back() << endl;
	cout << "remove 20\n";
	list.remove(20);
	cout << "back : " << list.back() << endl;
	cout << "push back 3\n";
	list.push_back(3);
	cout << "push front 3\n";
	cout << "push front 3\n";
	list.push_front(3);
	list.push_front(3);
	for (DoublyLinkedList<int>::Iterator iter = list.begin(); iter != list.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << '\n';
	list.sort();
	list.unique();
	for (DoublyLinkedList<int>::Iterator iter = list.begin(); iter != list.end(); ++iter) {
		cout << *iter << " ";
	}

	return 0;
}
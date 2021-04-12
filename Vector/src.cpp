#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
	T* arr;
	size_t _size;
	size_t _capacity;
	static constexpr size_t DEFAULT_CAPACITY = 8;

public:
	Vector(size_t capacity = DEFAULT_CAPACITY)
		: arr(new T[capacity]), _size(0), _capacity(capacity) { }
	~Vector() { clear(); }

	T& operator[](const size_t& idx) {
		if (idx < this->_size)
			return this->arr[idx];
		cerr << "vector subscript out of range\n";
		exit(0);
	}

	void push_back(const T& val) {
		if (this->_size >= this->_capacity) {
			if (this->_capacity < DEFAULT_CAPACITY)
				this->_capacity = DEFAULT_CAPACITY;
			else
				this->_capacity *= 2;
			T* tmp = new T[this->_capacity];
			for (size_t i = 0; i < this->_size; i++)
				tmp[i] = this->arr[i];
			delete[] this->arr;
			this->arr = tmp;
		}
		this->arr[this->_size++] = val;
	}

	void pop_back() { 
		if (this->_size) {
			this->_size--;
			this->arr[this->_size] = T();
		}
	}

	void reserve(const size_t& n) {
		if (n <= this->_capacity)
			return;

		T* tmp = new T[n];
		for (size_t i = 0; i < this->_size; i++)
			tmp[i] = this->arr[i];
		delete[] this->arr;
		this->arr = tmp;
		this->_capacity = n;
	}

	void resize(const size_t& n, T val = T()) {
		T* tmp = new T[n];
		this->_size = this->_size < n ? _size : n;
		this->_capacity = n;
		for (size_t i = 0; i < this->_size; i++)
			tmp[i] = this->arr[i];
		for (size_t i = this->_size; i < this->_capacity; i++)
			tmp[i] = val;
		delete[] this->arr;
		this->arr = tmp;
		this->_size = n;
	}

	void clear() { 
		this->_size = 0; 
		this->_capacity = DEFAULT_CAPACITY;
		delete[] this->arr;
	}

	bool empty() const { return this->_size > 0 ? false : true; }

	size_t size() const { return this->_size; }

	size_t capacity() const { return this->_capacity; }
};

int main() {
	Vector<int> v;

	cout << v.capacity() << endl;
	v.reserve(10);
	cout << v.capacity() << endl;
	v.resize(12);
	cout << v[11] << endl;
	v.push_back(5);
	cout << v[12] << endl;
	v.pop_back();
	cout << v[12];

	return 0;
}
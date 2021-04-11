#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T> class General_Tree;

template <typename T>
class Node {
private:
	T data;
	Node<T>* par;
	vector<Node<T>*> children;

	friend class General_Tree<T>;
public:
	Node(const T& data) {
		this->data = data;
		this->par = nullptr;
	}
};

template <typename T>
class General_Tree {
private:
	Node<T>* _root;
	int _size;

	Node<T>* search(const T& data) const {
		if (this->_root->data == data) 
			return this->_root;

		Node<T>* curNode;
		queue<Node<T>*> q;
		q.push(this->_root);

		while (!q.empty()) {
			curNode = q.front(); q.pop();

			for (Node<T>* child : curNode->children) {
				if (child->data == data) 
					return child;
				q.push(child);
			}
		}

		return nullptr;
	}

	void process(Node<T>* node) const {
		cout << node->data << " ";
	}

	void _preorder(Node<T>* curNode) const {
		process(curNode);
		for (Node<T>* child : curNode->children) {
			_preorder(child);
		}
	}

	void _postorder(Node<T>* curNode) const {
		for (Node<T>* child : curNode->children) {
			_postorder(child);
		}
		process(curNode);
	}

	int __height() const {
		int _height = -1;
		queue<Node<T>*> q;
		queue<Node<T>*> tmp_q;

		tmp_q.push(this->_root);

		while (!tmp_q.empty()) {
			while (!tmp_q.empty()) {
				q.push(tmp_q.front()); tmp_q.pop();
			}

			while (!q.empty()) {
				Node<T>* curNode = q.front(); q.pop();

				for (Node<T>* child : curNode->children) {
					tmp_q.push(child);
				}
			}
			_height++;
		}

		return _height;
	}

public:
	General_Tree() {
		this->_root = nullptr;
		this->_size = 0;
	}

	void insert(const T& par_data, const T& data) {
		Node<T>* newNode = new Node<T>(data);

		if (this->_size == 0)
			this->_root = newNode;
		else {
			Node<T>* parNode = search(par_data);
			if (parNode == nullptr) return;
			parNode->children.push_back(newNode);
			newNode->par = parNode;
		}
		this->_size++;
	}

	void remove(const T& data) {
		Node<T>* delNode = search(data);
		if (delNode == nullptr || delNode == this->_root) return;

		for (Node<T>* child : delNode->children) {
			child->par = delNode->par;
			delNode->par->children.push_back(child);
		}
		int idx = 0;
		for (Node<T>* child : delNode->par->children) {
			if (child == delNode) {
				delNode->par->children.erase(delNode->par->children.begin() + idx);
				break;
			}
			idx++;
		}
		delete delNode;
		this->_size--;
	}

	int height() const {
		return __height();
	}

	T root() const {
		return this->_root->data;
	}

	int size() const {
		return this->_size;
	}

	bool empty() const {
		return (this->_size == 0 ? true : false);
	}

	void preorder() const { _preorder(this->_root); cout << '\n'; }

	void postorder() const { _postorder(this->_root); cout << '\n'; }
};


int main() {
	General_Tree<char> tree;

	cout << tree.empty() << endl;

	tree.insert('A', 'A');
	tree.insert('A', 'B');
	tree.insert('A', 'C');
	tree.insert('A', 'D');
	tree.insert('B', 'E');
	tree.insert('B', 'F');
	tree.insert('B', 'G');
	tree.insert('F', 'H');
	tree.insert('H', 'I');
	tree.insert('H', 'J');

	cout << tree.size() << endl;
	tree.preorder();
	tree.postorder();
	cout << tree.height() << endl;
	cout << tree.root() << endl;
	cout << endl;
	tree.remove('B');
	cout << tree.size() << endl;
	tree.preorder();
	tree.postorder();
	cout << tree.height() << endl;
	cout << tree.root() << endl;

	return 0;
}
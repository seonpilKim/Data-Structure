#include <iostream>
#include <queue>

using namespace std;

template <typename T> class Binary_Tree;

template <typename T>
class Node {
private:
	T data;
	Node<T>* par;
	Node<T>* left;
	Node<T>* right;

	friend class Binary_Tree<T>;
public:
	Node(const T& data) {
		this->data = data;
		this->par = this->left = this->right = nullptr;
	}
};

template <typename T>
class Binary_Tree {
private:
	Node<T>* _root;
	int _size;

	Node<T>* search(const T& data) const {
		if (this->_root->data == data) return this->_root;

		Node<T>* curNode;
		queue<Node<T>*> q;
		q.push(this->_root);

		while (!q.empty()) {
			curNode = q.front(); q.pop();

			if (curNode->left && curNode->left->data == data) 
				return curNode->left;			
			else if (curNode->right && curNode->right->data == data) 
				return curNode->right;
			
			if (curNode->left) q.push(curNode->left);
			if (curNode->right) q.push(curNode->right);
		}

		return nullptr;
	}

	void process(Node<T>* node) const {
		cout << node->data << " ";
	}

	void _preorder(Node<T>* curNode) const {
		process(curNode);
		if (curNode->left) _preorder(curNode->left);
		if (curNode->right) _preorder(curNode->right);
	}

	void _inorder(Node<T>* curNode) const {
		if (curNode->left) _inorder(curNode->left);
		process(curNode);
		if (curNode->right) _inorder(curNode->right);
	}

	void _postorder(Node<T>* curNode) const {
		if (curNode->left) _postorder(curNode->left);
		if (curNode->right) _postorder(curNode->right);
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

				if (curNode->left) tmp_q.push(curNode->left);
				if (curNode->right) tmp_q.push(curNode->right);
			}
			_height++;
		}

		return _height;
	}

public:
	Binary_Tree() {
		this->_root = nullptr;
		this->_size = 0;
	}

	void insert_root(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		this->_root = newNode;
		this->_size++;
	}

	void insert_left(const T& par_data, const T& data) {
		Node<T>* newNode = new Node<T>(data);
		Node<T>* parNode = search(par_data);
		
		if (parNode == nullptr) 
			return;

		if (parNode->left == nullptr) {
			parNode->left = newNode;
			newNode->par = parNode;
			this->_size++;
		}
		else 
			parNode->left->data = newNode->data;
	}

	void insert_right(const T& par_data, const T& data) {
		Node<T>* newNode = new Node<T>(data);
		Node<T>* parNode = search(par_data);

		if (parNode == nullptr)
			return;

		if (parNode->right == nullptr) {
			parNode->right = newNode;
			newNode->par = parNode;
			this->_size++;
		}
		else
			parNode->right->data = newNode->data;
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
	void inorder() const { _inorder(this->_root); cout << '\n'; }
	void postorder() const { _postorder(this->_root); cout << '\n'; }
};


int main() {
	Binary_Tree<char> tree;

	cout << tree.empty() << endl;

	tree.insert_root('A');
	tree.insert_left('A', 'B');
	tree.insert_right('A', 'C');
	tree.insert_left('B', 'E');
	tree.insert_right('B', 'F');
	tree.insert_left('F', 'H');
	tree.insert_left('H', 'I');
	tree.insert_right('H', 'J');

	cout << tree.size() << endl;
	tree.preorder();
	tree.inorder();
	tree.postorder();
	cout << tree.height() << endl;
	cout << tree.root() << endl;

	return 0;
}
//#include <iostream>
//
//using namespace std;
//
//template <typename T> class Binary_Tree;
//
//template <typename T>
//class Node {
//private:
//	T data;
//	Node<T>* par;
//	Node<T>* left;
//	Node<T>* right;
//	friend class Binary_Tree<T>;
//
//public:
//	Node(const T &data) {
//		this->data = data;
//		this->par = left = right = nullptr;
//	}
//};
//
//template <typename T>
//class Binary_Tree {
//private:
//	Node<T>* _root;
//	int _size;
//
//	Node<T>* find(const T& data) {
//		Node<T>* curNode = this->_root;
//
//		while (true) {
//			if (curNode->data > data) {
//				if (curNode->right == nullptr)
//					return curNode;
//				else
//					curNode = curNode->right;
//			}
//			else {
//				if (curNode->left == nullptr)
//					return curNode;
//				else
//					curNode = curNode->left;
//			}
//		}
//	}
//
//public:
//	void insert(const T& data) {
//		Node<T>* newNode = Node<T>(data);
//		if (this->_size == 0)
//			this->_root = newNode;
//		else {
//			Node<T>* parNode = find(data);
//			if (parNode > data) {
//				parNode->right = newNode;
//				newNode->par = parNode;
//			}
//			else {
//				parNode->left = newNode;
//				newNode->par = parNode;
//			}
//		}
//		this->_size++;
//	}
//
//	void remove(const T& data) {
//		Node<T>* delNode = find(data);
//	}
//};
//
//int main() {
//
//	return 0;
//}

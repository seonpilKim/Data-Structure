#include <iostream>
#include <queue>

using namespace std;

template <typename T> class Binary_Search_Tree;

template <typename T>
class Node {
private:
	T data;
	Node<T>* par;
	Node<T>* left;
	Node<T>* right;
	friend class Binary_Search_Tree<T>;

public:
	Node(const T &data) {
		this->data = data;
		this->par = left = right = nullptr;
	}
};

template <typename T>
class Binary_Search_Tree {
private:
	Node<T>* _root;
	int _size;

	Node<T>* find(const T& data) const {
		queue<Node<T>*> q;
		Node<T>* curNode;
		q.push(this->_root);

		while (!q.empty()) {
			curNode = q.front(); q.pop();
			if (curNode->data == data) return curNode;

			if (curNode->data > data) {
				if (curNode->left != nullptr)
					q.push(curNode->left);
			}
			else if (curNode->data < data) {
				if (curNode->right != nullptr)
					q.push(curNode->right);
			}
		}

		return nullptr;
	}

	void process(Node<T>* curNode) const {
		cout << curNode->data << ' ';
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
	Binary_Search_Tree() {
		this->_root = nullptr;
		this->_size = 0;
	}

	void insert(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		if (this->_size == 0)
			this->_root = newNode;
		else {
			Node<T>* curNode = this->_root;

			while (true) {
				if (curNode->data > data) {
					if (curNode->left) 
						curNode = curNode->left;
					else {
						curNode->left = newNode;
						curNode->left->par = curNode;
						break;
					}
				}
				else if (curNode->data < data) {
					if (curNode->right) 
						curNode = curNode->right;			
					else {
						curNode->right = newNode;
						curNode->right->par = curNode;
						break;
					}
				}
			}
		}
		this->_size++;
	}

	void remove(const T& data) {
		Node<T>* delNode = find(data);
		if (delNode == nullptr) 
			return;

		if (delNode->left && delNode->right) {
			Node<T>* curNode = delNode->left;

			while (curNode->right) {
				curNode = curNode->right;
			}
			curNode->par->right = nullptr;

			curNode->par = delNode->par;
			if (curNode->par->left == delNode) 
				curNode->par->left = curNode;			
			else if (curNode->par->right == delNode) 
				curNode->par->right = curNode;	

			curNode->left = delNode->left;
			delNode->left->par = curNode;
			curNode->right = delNode->right;
			delNode->right->par = curNode;
		}
		else if (delNode->left && !delNode->right) {
			if (delNode->par->left == delNode) {
				delNode->par->left = delNode->left;
				delNode->left->par = delNode->par;
			}
			else if (delNode->par->right == delNode) {
				delNode->par->right = delNode->left;
				delNode->left->par = delNode->par;
			}
		}
		else if (!delNode->left && delNode->right) {
			if (delNode->par->left == delNode) {
				delNode->par->left = delNode->right;
				delNode->right->par = delNode->par;
			}
			else if (delNode->par->right == delNode) {
				delNode->par->right = delNode->right;
				delNode->right->par = delNode->par;
			}
		}
		else if (!delNode->left && !delNode->right) {
			if (delNode->par->left == delNode)
				delNode->par->left = nullptr;
			else if (delNode->par->right == delNode)
				delNode->par->right = nullptr;
		}

		delete delNode;
		this->_size--;
	}

	void preorder() const {
		_preorder(this->_root);
		cout << '\n';
	}
	void inorder() const {
		_inorder(this->_root);
		cout << '\n';
	}
	void postorder() const {
		_postorder(this->_root);
		cout << '\n';
	}

	bool empty() const {
		return this->_size == 0 ? true : false;
	}

	int size() const {
		return this->_size;
	}

	int root() const {
		return this->_root->data;
	}

	int height() const {
		return __height();
	}
};

int main() {
	Binary_Search_Tree<int> BST;

	BST.insert(35);
	BST.insert(18);
	BST.insert(68);
	BST.insert(7);
	BST.insert(26);
	BST.insert(99);
	BST.insert(3);
	BST.insert(12);
	BST.insert(22);
	BST.insert(30);
	BST.inorder();
	BST.remove(30);
	BST.inorder();
	BST.remove(68);
	BST.inorder();
	BST.remove(18);
	BST.inorder();
	cout << BST.height();

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Tree {
private:
	struct Node {
		char digit;
		vector<Node*> chi;
		Node(char digit)
			: digit(digit) {}
	};
public:
	Node* root;

	Tree()
		: root(new Node('R')) {}
	
	bool add(string digits) {
		Node* cur = this->root;
		int idx = 0;

		for (char digit : digits) {
			bool flag = true;
			
			for (Node* chi : cur->chi) {
				if (chi->digit == digit) {
					if (idx == digits.size() - 1 || chi->chi.size() == 0)
						return false;
					
					cur = chi;
					flag = false;
					break;
				}
			}

			if (flag) {
				cur->chi.push_back(new Node(digit));
				cur = cur->chi.back();
			}

			idx++;
		}

		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	
	while (T--) {
		Tree list;
		int N;
		bool flag = true;

		cin >> N;

		while (N--) {
			string number;
			cin >> number;
			if (list.add(number) == false)
				flag = false;
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}
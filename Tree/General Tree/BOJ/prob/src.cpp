#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;

void converter(vector<int>, vector<int>);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, N;

	cin >> T;

	while (T--) {
		cin >> N;

		vector<int> depth;
		vector<int> postorder;

		for (int i = 0; i < N; i++) {
			int X;
			cin >> X;
			postorder.push_back(X);
		}
		for (int i = 0; i < N; i++) {
			int X;
			cin >> X;
			depth.push_back(X);
		}

		converter(postorder, depth);

		for (int val : preorder)
			cout << val << ' ';

		preorder.clear();
		cout << '\n';
	}
	return 0;
}

void converter(vector<int> subtree, vector<int> subdepth) {
	// push the subtree's root to preorder
	preorder.push_back(subtree.back());

	if (subtree.size() == 1)
		return;

	// create a subtree that root's depth is 'current subtree's depth + 1'
	vector<int> st, sd;
	for (int i = 0; i < subtree.size(); i++) {
		sd.push_back(subdepth[i]);
		st.push_back(subtree[i]);

		// subdepth.back() : the root's depth in the subtree
		if (subdepth[i] == subdepth.back() + 1) {
			// recursive call with the subtree which was just made
			converter(st, sd);

			// initailize the subtree
			st.clear();
			sd.clear();
		}
	}
}
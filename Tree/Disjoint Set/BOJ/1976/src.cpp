#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class DisjointSet {
private:
	vector<int> par, rank;

public:
	DisjointSet(int n)
		: par(n), rank(n, 1) {
		for (int i = 0; i < n; i++) 
			par[i] = i;	
	}

	int find(int node) {
		if (node == par[node])
			return node;

		return par[node] = find(par[node]);
	}

	void merge(int node1, int node2) {
		node1 = find(node1);
		node2 = find(node2);

		if (node1 != node2) {
			if (rank[node1] > rank[node2])
				swap(node1, node2);
			par[node1] = node2;

			if (rank[node1] == rank[node2])
				++rank[node2];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;

	cin >> n >> m;

	DisjointSet set(n);
	for (int city = 0; city < n; city++) {
		for (int i = 0; i < n; i++) {
			int next;
			cin >> next;
			if (next == 1)
				set.merge(city, i);
		}
	}
	
	stack<int> s;
	while (m--) {
		int city;
		cin >> city;
		s.push(city - 1);
	}

	int cmp = s.top(); s.pop();
	bool flag = true;

	while (!s.empty()) {
		if (set.find(cmp) != set.find(s.top())) {
			flag = false;
			break;
		}
		s.pop();
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
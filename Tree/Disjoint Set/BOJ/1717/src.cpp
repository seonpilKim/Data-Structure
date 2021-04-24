#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
	vector<int> par, rank;
	
public:
	DisjointSet(int n)
		: par(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	int find(int node) {
		if (node == par[node])
			return node;

		return par[node] = find(par[node]);
	}

	void merge(int node1, int node2) {
		node1 = find(node1);
		node2 = find(node2);

		if (node1 == node2)
			return;

		if (rank[node1] > rank[node2])
			swap(node1, node2);
		par[node1] = node2;

		if (rank[node1] == rank[node2])
			++rank[node2];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;

	cin >> n >> m;

	DisjointSet set(n + 1);
	
	while (m--) {
		int cmd, a, b;

		cin >> cmd >> a >> b;
		
		if (cmd == 0) 
			set.merge(a, b);	
		else if (cmd == 1) {
			if (set.find(a) == set.find(b)) 
				cout << "YES\n";
			else 
				cout << "NO\n";
		}
	}




	return 0;
}
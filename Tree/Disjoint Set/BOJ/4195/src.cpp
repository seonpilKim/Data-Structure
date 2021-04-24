#include <iostream>
#include <vector>
#include <map>

using namespace std;

class DisjointSet {
private:
	vector<int> par, rank, size;
	map<string, int> people;
	int idx;

public:
	DisjointSet(int n)
		: par(n), rank(n, 1), size(n, 1), idx(0) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	int find(int node) {
		if (node == par[node])
			return node;

		return par[node] = find(par[node]);
	}

	void merge(string person1, string person2) {
		int node1, node2;
		if (people.find(person1) == people.end()) {
			people.emplace(person1, idx);
			node1 = idx++;
		}
		else 
			node1 = people.find(person1)->second;
		
		if (people.find(person2) == people.end()) {
			people.emplace(person2, idx);
			node2 = idx++;
		}
		else
			node2 = people.find(person2)->second;

		node1 = find(node1);
		node2 = find(node2);

		if (node1 != node2) {

			if (rank[node1] > rank[node2])
				swap(node1, node2);
			par[node1] = node2;
			size[node2] += size[node1];

			if (rank[node1] == rank[node2])
				++rank[node2];
		}
		cout << size[node2] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		DisjointSet set(2 * m);
		
		while (m--) {
			string p1, p2;
			cin >> p1 >> p2;

			set.merge(p1, p2);
		}
	}

	return 0;
}
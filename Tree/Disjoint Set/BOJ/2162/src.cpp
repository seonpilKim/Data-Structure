#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;

	Point(int x, int y)
		: x(x), y(y) {}
};

struct Line {
	Point start;
	Point end;

	Line(Point start, Point end)
		: start(start), end(end) {}
};

long long CCW(const Point&, const Point&, const Point&);
bool isIntersect(const Line&, const Line&);

class DisjointSet {
private:
	vector<int> par, rank, size;
	vector<Line> list;

public:
	DisjointSet(int n)
		: par(n), rank(n, 1), size(n, 0) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	void solution() {
		int max = 0;
		int groups = 0;

		for (int i = 0; i < this->par.size(); i++) {
			if (par[i] == i) {
				groups++;
				size[i]++;
				if (size[i] > max)
					max = size[i];
			}
			else {
				int node = find(i);
				size[node]++;
				if (size[node] > max)
					max = size[node];
			}
		}

		cout << groups << '\n';
		cout << max;
	}

	void push(const Line& A) {
		list.push_back(A);
	}

	int find(int node) {
		if (node == par[node])
			return node;

		return par[node] = find(par[node]);
	}

	void merge(int node1, int node2) {
		if (isIntersect(list[node1], list[node2])) {
			node1 = find(node1);
			node2 = find(node2);

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

	int N;

	cin >> N;
	DisjointSet set(N);

	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		set.push(Line(Point(x1, y1), Point(x2, y2)));
	}

	for (int i = 0; i < N; i++) 
		for (int j = i + 1; j < N; j++) 
			set.merge(i, j);		

	set.solution();
	
	return 0;
}

long long CCW(const Point& A, const Point& B, const Point& C) {
	return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

bool isIntersect(const Line& A, const Line& B) {
	const int case1 = CCW(A.start, A.end, B.start) * CCW(A.start, A.end, B.end);
	const int case2 = CCW(B.start, B.end, A.start) * CCW(B.start, B.end, A.end);

	if (case1 == 0 && case2 == 0) {
		pair<int, int> p1 = make_pair(A.start.x, A.start.y);
		pair<int, int> p2 = make_pair(A.end.x, A.end.y);
		pair<int, int> p3 = make_pair(B.start.x, B.start.y);
		pair<int, int> p4 = make_pair(B.end.x, B.end.y);

		if (p1 > p2)
			swap(p1, p2);
		if (p3 > p4)
			swap(p3, p4);

		return p1 <= p4 && p3 <= p2;
	}

	return case1 <= 0 && case2 <= 0;
}
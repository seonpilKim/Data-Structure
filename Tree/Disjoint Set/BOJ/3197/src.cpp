#include <iostream>
#include <queue>

using namespace std;

int r, c;
pair<char, bool> arr[1500][1500];
pair<int, int> par[1500][1500];
pair<int, int> duck[2];
queue<pair<int, int>> q;

pair<int, int> find(int row, int col);
void merge(pair<int, int> p1, pair<int, int> p2);
void BFS(pair<int, int> duck1, pair<int, int> duck2);
void solution(int row, int col);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c;

	solution(r, c);

	return 0;
}

pair<int, int> find(int row, int col) {
	if (make_pair(row, col) == par[row][col])
		return make_pair(row, col);

	return par[row][col] = find(par[row][col].first, par[row][col].second);
}

void merge(pair<int, int> p1, pair<int, int> p2) {
	p1 = find(p1.first, p1.second);
	p2 = find(p2.first, p2.second);

	if (p1 == p2)
		return;
	par[p1.first][p1.second] = p2;
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool check(int x, int y) {
	return (0 <= x && x < r && 0 <= y && y < c);
}

void BFS(pair<int, int> duck1, pair<int, int> duck2) {
	queue<pair<int, int>> next_q;
	int time = 0;

	while (true) {
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			int x = cur.first;
			int y = cur.second;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (check(nx, ny) == false)
					continue;

				pair<int, int> next = make_pair(nx, ny);

				if (arr[nx][ny].first == 'X' && arr[nx][ny].second == false) {
					arr[nx][ny].second = true;
					next_q.push(next);
				}
				else if (arr[nx][ny].first != 'X') 
					merge(cur, next);
			}
		}

		if (find(duck1.first, duck1.second) == find(duck2.first, duck2.second)) {
			cout << time;
			return;
		}

		while (!next_q.empty()) {
			pair<int, int> p = next_q.front(); next_q.pop();
			arr[p.first][p.second].first = '.';
			q.push(p);
		}

		time++;
	}
}

void input(int row, int col) {
	int idx = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			char input;
			cin >> input;
			arr[i][j] = make_pair(input, false);
			if (input == 'L' || input == '.') {
				if (input == 'L')
					duck[idx++] = make_pair(i, j);
				arr[i][j] = make_pair(input, true);
				q.push(make_pair(i, j));
			}
			par[i][j] = make_pair(i, j);
		}
	}
}

void solution(int row, int col) {
	input(r, c);
	BFS(duck[0], duck[1]);
}
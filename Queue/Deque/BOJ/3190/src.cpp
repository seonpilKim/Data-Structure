#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<pair<int, int>> snake;
	int apple[101][101] = {0,};
	int N, K, L;
	int time = 0;

	cin >> N >> K;

	while (K--) {
		int row, col;
		cin >> row >> col;
		apple[col][row] = 1;
	}

	int Right = 1;
	int Left = 0;
	int Up = 0;
	int Down = 0;
	bool flag = false;
	snake.push_front(make_pair(1, 1));

	cin >> L;
	while (L--) {
		int n;
		char rotate;

		cin >> n >> rotate;

		while (time < n) {
			time++;
			pair<int, int> XY = snake.front();

			int x = XY.first + Right - Left;
			int y = XY.second - Up + Down;

			if (x > N || y > N || x == 0 || y == 0) {
				flag = true;
				break;
			}

			if (apple[x][y] != 1) {
				if (XY != snake.back()) {
					for (deque<pair<int, int>>::iterator iter = snake.begin(); iter != snake.end(); ++iter) {
						if (*iter == make_pair(x, y)) {
							flag = true;
							break;
						}
					}
				}
				if (flag)
					break;

				snake.pop_back();
			}

			snake.push_front(make_pair(x, y));
			apple[x][y] = 0;
		}
		if (flag)
			break;

		if (rotate == 'D') {
			if (Right) {
				Right = 0;
				Down = 1;
			}
			else if (Left) {
				Left = 0;
				Up = 1;
			}
			else if (Up) {
				Up = 0;
				Right = 1;
			}
			else if (Down) {
				Down = 0;
				Left = 1;
			}
		}
		else if (rotate == 'L') {
			if (Right) {
				Right = 0;
				Up = 1;
			}
			else if (Left) {
				Left = 0;
				Down = 1;
			}
			else if (Up) {
				Up = 0;
				Left = 1;
			}
			else if (Down) {
				Down = 0;
				Right = 1;
			}
		}
	}

	while (!flag) {
		time++;
		pair<int, int> XY = snake.front();

		int x = XY.first + Right - Left;
		int y = XY.second - Up + Down;

		if (x > N || y > N || x == 0 || y == 0) {
			flag = true;
			break;
		}

		if (apple[x][y] != 1) {
			if (XY != snake.back()) {
				for (deque<pair<int, int>>::iterator iter = snake.begin(); iter != snake.end(); ++iter) {
					if (*iter == make_pair(x, y)) {
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;

			snake.pop_back();
		}

		snake.push_front(make_pair(x, y));
		apple[x][y] = 0;
	}

	cout << time;

	return 0;
}
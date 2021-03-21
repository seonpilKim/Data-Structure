#include <iostream>
#include <stack>
#include <limits.h>

#define MAX INT_MAX

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<pair<int, int>> s;
	int n;

	while (true) {
		cin >> n;
		if (n == 0)
			break;

		long long width, height;
		int rec;
		long long area = 0;

		for (int i = 0; i < n; i++) {
			cin >> rec;

			if (s.empty() || (!s.empty() && s.top().first <= rec))
				s.push(make_pair(rec, i));
			else if (!s.empty() && s.top().first > rec) {
				height = MAX;
				
				while (!s.empty() && s.top().first >= rec) {
					if (height > s.top().first)
						height = s.top().first;
					s.pop();

					if (s.empty())
						width = i;
					else
						width = i - s.top().second - 1;

					if (area < width * height)
						area = width * height;
				}

				s.push(make_pair(rec, i));
			}
		}

		height = MAX;
		while (!s.empty()) {
			if (height > s.top().first)
				height = s.top().first;
			s.pop();

			if (s.empty())
				width = n;
			else
				width = n - s.top().second - 1;

			if (area < width * height)
				area = width * height;
		}

		cout << area << '\n';
	}

	return 0;
}
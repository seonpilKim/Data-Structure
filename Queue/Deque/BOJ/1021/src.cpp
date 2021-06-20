#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <limits.h>
#include <numeric>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int num, idx;
		cin >> num;

		for (int i = 0; i < dq.size(); i++) {
			if (dq.at(i) == num) {
				idx = i;
				break;
			}
		}

		if (dq.size() - idx > idx) {
			while(dq.front() != num) {
				dq.push_back(dq.front()); 
				dq.pop_front();
				cnt++;
			}
		}
		else {
			while(dq.front() != num) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		dq.pop_front();
	}

	cout << cnt;

	return 0;
}
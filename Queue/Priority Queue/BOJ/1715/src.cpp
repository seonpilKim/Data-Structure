#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <stack>
#include <queue>
#include <math.h>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> card;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		card.push(n);
	}

	int ans = 0;
	while (card.size() > 1) {
		int sum = card.top();
		card.pop();
		sum += card.top();
		card.pop();
		card.push(sum);
		ans += sum;
	}
	
	cout << ans;

	return 0;
}
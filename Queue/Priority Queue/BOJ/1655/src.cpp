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
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <numeric>
#include <functional>
#include <sstream>
#include <cctype>

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	
	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;
		
		if (minHeap.size() >= maxHeap.size())
			maxHeap.push(n);
		else if (minHeap.size() < maxHeap.size()) 
			minHeap.push(n);
		
		if (!minHeap.empty() && !maxHeap.empty()) {
			if (maxHeap.top() > minHeap.top()) {
				int tmp = minHeap.top();
				minHeap.pop();
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(tmp);
			}
		}

		cout << maxHeap.top() << '\n';
	}

	return 0;
} 
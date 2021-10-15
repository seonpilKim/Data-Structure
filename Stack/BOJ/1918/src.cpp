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

using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e9;

const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dh[] = {1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string infix;
	cin >> infix;
	
	stack<char> s;
	string postfix = "";
	for (int i = 0; i < infix.size(); i++) {
		char cur = infix[i];

		if (cur == '+' || cur == '-') {
			while (!s.empty() && s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			s.push(cur);
		}
		else if (cur == '*' || cur == '/') {
			while (!s.empty() && s.top() != '+' && s.top() != '-' && s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			s.push(cur);
		}
		else if (cur == '(')
			s.push(cur);
		else if (cur == ')') {
			while (!s.empty() && s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
		else 
			postfix += cur;
	}
	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	cout << postfix;

	return 0;
} 
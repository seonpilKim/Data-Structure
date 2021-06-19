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

	int T;
	cin >> T;


	while (T--) {
		string p;
		cin >> p;

		int n;
		cin >> n;

		string input;
		cin >> input;
		deque<string> dq;
		int s = 1;
		for (int i = 1; i < input.size() - 1; i++) {
			if (input.at(i) != ',') {
				continue;
			}
			
			dq.push_back(input.substr(s, i - s));
			s = i + 1;
		}
		if(n != 0)
			dq.push_back(input.substr(s, input.size() - 1 - s));
		
		bool flag = true;
		bool reverse = false;
		for (int i = 0; i < p.size(); i++) {
			if (p.at(i) == 'R') 
				reverse = !reverse;
			else if (p.at(i) == 'D') {
				if (n == 0 || dq.empty()) {
					flag = false;
					break;
				}

				if (reverse) 
					dq.pop_back();
				else 
					dq.pop_front();
			}
		}

		if (flag) {
			cout << '[';
			
			if (dq.size() > 0) {
				if (reverse) {
					for (int i = dq.size() - 1; i > 0; i--)
						cout << dq.at(i) << ',';
					cout << dq.front();
				}
				else {
					for (int i = 0; i < dq.size() - 1; i++)
						cout << dq.at(i) << ',';
					cout << dq.back();
				}
			}

			cout << "]\n";
			dq.clear();
		}
		else
			cout << "error\n";
	}

	return 0;
}
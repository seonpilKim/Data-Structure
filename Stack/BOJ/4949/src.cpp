#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	stack<char> s;
	vector<string> ans;
	string input;

	while (true) {
		int idx = 0;
		getline(cin, input);
		if (input[0] == '.') 
			break;
				
		bool flag = true;
		for (int idx = 0; idx < 100; idx++) {
			if (input[idx] == '.') break;
			else if (input[idx] == '(' || input[idx] == '[')
				s.push(input[idx]);
			else if (input[idx] == ')') {
				if (s.empty() || s.top() != '(') {
					flag = false;
					break;
				}
				s.pop();
			}
			else if (input[idx] == ']') {
				if (s.empty() || s.top() != '[') {
					flag = false;
					break;
				}
				s.pop();
			}
		}

		if (!flag || !s.empty()) {
			ans.push_back("no");
			while (!s.empty())
				s.pop();
		}
		else if(flag && s.empty())
			ans.push_back("yes");
	}

	for (string answer : ans) {
		cout << answer << '\n';
	}

	return 0;
}
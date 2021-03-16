#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    stack<char> s;
    int val = 1;
    int answer = 0;

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
            val *= 2;
        }
        else if (str[i] == '[') {
            s.push(str[i]);
            val *= 3;
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                answer = 0;
                break;
            }
            else {
                if (str[i - 1] == '(')
                    answer += val;
                val /= 2;
                s.pop();
            }
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {
                answer = 0;
                break;
            }
            else {
                if (str[i - 1] == '[')
                    answer += val;
                val /= 3;
                s.pop();
            }
        }
    }

    if (!s.empty()) answer = 0;

    cout << answer;
   
    return 0;
}
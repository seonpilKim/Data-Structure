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

void postorder(const vector<int>& preorder, const vector<int>& inorder, int start, int end, int pre_root) {
    if (start == end)
        return;

    int in_root = find(inorder.begin() + start, inorder.begin() + end, preorder[pre_root]) - inorder.begin();

    postorder(preorder, inorder, start, in_root, pre_root + 1);
    postorder(preorder, inorder, in_root + 1, end, pre_root + in_root - start + 1);

    cout << inorder[in_root] << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> preorder(N), inorder(N);
        for (int i = 0; i < N; i++)
            cin >> preorder[i];
        for (int i = 0; i < N; i++)
            cin >> inorder[i];

        postorder(preorder, inorder, 0, N, 0);
        cout << '\n';
    }
	
	return 0;
}
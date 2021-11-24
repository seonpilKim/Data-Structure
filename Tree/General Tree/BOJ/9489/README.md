# [[9489] 사촌](https://www.acmicpc.net/problem/9489)

## 🤔접근
___
## 💡풀이
- <B>알고리즘</B>
- <b>자료구조</b>
	- `Tree`
- <b>구현</b>
	- 먼저, n은 1이상의 값이므로, 0번째 인덱스의 노드를 -1으로 초기화해주었다.
		- 그래야, 첫 번째 입력을 루트로 처리할 수 있다.
	- 현재 노드가 k라면, 해당 인덱스를 `idx` 변수에 저장하였다.
	- 현재 노드가 이전 노드보다 값이 2 이상이라면, cnt를 증가시켰다.
		- cnt로 각 노드가 속하는 그룹을 표현할 수 있다.
	- `두 노드의 부모가 형제일 때, 두 노드를 사촌이라 부를 수 있으므로`, 아래의 조건에 만족하는 노드는 idx번째 노드와 사촌 관계이다.
		- `par[i] != par[idx]` && `par[par[i]] == par[par[idx]]`
		- 현재 부모가 서로 같지 않고, 조부모가 같은 경우
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
	...

	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0) 
			break;

		vector<int> nodes(n + 1), par(n + 1);
		nodes[0] = par[0] = -1;
		
		int cnt = -1, idx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> nodes[i];

			if (nodes[i] == k)
				idx = i;
			if (nodes[i] != nodes[i - 1] + 1)
				cnt++;
			par[i] = cnt;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (par[i] != par[idx] && par[par[i]] == par[par[idx]])
				ans++;
		cout << ans << '\n';
	}

	...
}
```
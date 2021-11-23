# [[3584] 가장 가까운 공통 조상](https://www.acmicpc.net/problem/3584)

## 🤔접근
___
## 💡풀이
- <B>알고리즘</B>
- <b>자료구조</b>
	- `Tree`
- <b>구현</b>
	- 각 노드마다 부모 노드를 `par` 배열에 저장하고, 입력받은 노드부터 부모노드까지 위쪽으로 하나씩 탐색하는 방식으로 가장 가까운 공통 조상을 찾을 수 있다.
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
int main() {
	...

	while (T--) {
		int N;
		cin >> N;
		vector<int> par(N + 1);
		for (int i = 1; i <= N; i++)
			par[i] = i;
		for (int i = 1; i < N; i++) {
			int u, v;
			cin >> u >> v;
			par[v] = u;
		}

		int u, v;
		cin >> u >> v;
		vector<bool> isVisited(N + 1);
		while (u != par[u]) {
			isVisited[u] = true;
			u = par[u];
		}
		while (true) {
			if (isVisited[v]) {
				cout << v << '\n';
				break;
			}
			isVisited[v] = true;
			v = par[v];
		}
	}

	...
}
```
# Segment Tree, 구간 트리

## 💡 도입 배경
- 예를 들어, 배열이 주어졌을 때 특정 구간의 값을 구하라는 부탁을 받았다고 가정해보자.
	- 간단히 반복문을 사용하여 일일이 구하는 방법의 시간 복잡도는 `O(N)`이다.
		- 이 작업을 M번 해야 한다면, `O(N * M)` 일 것이다.
	- 미리 prefix sum을 저장해 놓고, 구간 합을 구하는 방법의 시간 복잡도는 `O(N)`이다.
		- 이 작업을 M번 해야 한다면, `O(N + M)` 일 것이다.
		- 위의 방법보다 상당히 성능히 개선되었다. 하지만..
			- 만약, 도중에 특정 위치의 값이 변경된다면?
			- 값이 변경될 때마다 prefix sum을 새로 구해야 하므로, 결국 위의 작업을 M번 할 때 시간 복잡도는 `O(N * M)`이 될 것이다.
- 그렇다면, 도중에 특정 위치의 값이 변경되어도 구간에 대한 연산을 빠르게 수행할 수 있는 방법은 없을까?
## 📖 개념
- `특정 구간 내 연산(query)`을 빠르게 수행하기 위해 고안된 자료구조이다.
	> ex) 구간 합, 구간 최솟/최댓 값, 구간 GCD 등
- 도중에 `특정 위치의 값이 변경`되어도, 연산을 빠르게 수행할 수 있다는 것이 특징이다.
## 🕒 시간 복잡도
- 특정 구간 내 연산: `O(log₂N)`
- 특정 위치의 값을 변경: `O(log₂N)`
## ⚙ 원리
- 예를 들어, 10개의 원소가 주어졌을 때 구간 합을 구해야 하는 상황을 가정해 보자.
- 먼저, 구간 합을 아래와 같이 Binary Tree 형태로 저장한다.
	![image](https://user-images.githubusercontent.com/68049320/151559636-8c893663-408c-4c24-ad9b-0ee84428b4e5.png)
	- 위의 형태를 만들기 위해 먼저 벡터 변수를 생성해보자.
	```c++
	// 10개의 원소를 a 벡터에 저장
	vector<long long> a(10);

	// Leaf node의 개수가 10개인 Binary Tree를 만들어 보자.
	// 먼저, Tree의 높이는 ceil(log₂(N)) 으로 구할 수 있다.
		// 예를 들어, Leaf node가 2개 있는 상황에서는 총 노드의 개수가 3개이고, 높이는 1이 된다. -> log₂(N)
		// 만약, Full Binary Tree가 아닌 경우에도 같은 높이를 가져야 하므로, ceil 함수로 감싸주어야 한다.
	int h = ceil(log2(N));

	// 2^h는 Leaf node의 개수이며, Full Binary Tree 기준 총 노드의 개수는 Leaf node 개수 * 2 - 1 이다.
	// 따라서, 2 * 2^h의 크기의 공간을 tree 벡터에 할당해 주었다.
    vector<long long> tree(1 << (h + 1));
	```
	- 이제 초기 변수 설정은 끝났으므로, 트리 형태로 구간 합을 저장하는 함수가 필요하다.
	```c++
	// a: 벡터 a
	// tree: 세그먼트 트리
	// node: 세그먼트 트리 노드 번호
	// node가 담당하는 합의 범위가 start ~ end
	long long init(const vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    	if (start == end) { // Leaf node인 경우, 현재 노드에 a 벡터의 값을 저장
    	    return tree[node] = a[start];
    	} else { // Leaf node가 아닌 경우, 왼쪽 자식 + 오른쪽 자식의 합을 현재 노드에 저장
      	  return tree[node] = init(a, tree, node * 2, start, (start+end) / 2) + init(a, tree, node * 2 + 1, (start+end) / 2 + 1, end);
    	}
	}
	```
- 다음으로, 특정 구간 내 연산 함수를 만들어 보자.<br>
현재 예시에서는 구간 합을 구하는 함수를 만들면 된다.
	- 3 ~ 9번째 구간 합을 구하는 예시
	![image](https://user-images.githubusercontent.com/68049320/151562321-b4be5086-5796-4f24-9eb0-faab998ef711.png)
	```c++
	// 루트 노드부터 시작하여, 각각 왼쪽과 오른쪽 자식으로 내려가면서 탐색을 진행한다.
	// 만약 현재 범위가 left ~ right 구간을 벗어난다면, 0을 반환한다.
	// 현재 범위가 left ~ right 구간에 속한다면, Tree에 저장되어 있는 구간 합을 반환한다.
	long long sum(const vector<long long> &tree, int node, int start, int end, int left, int right) {
    	if (left > end || right < start) // 현재 범위(start ~ end)가 탐색 구간(left ~ right)을 벗어나는 경우 0 반환
        	return 0;
    	if (left <= start && end <= right) // 현재 범위(start ~ end)가 탐색 구간(left ~ right) 내에 속하는 경우, 현재 노드에 저장되어 있는 구간 합을 반환
        	return tree[node];
		// 루트 노드부터 시작해서 왼쪽 자식과 오른쪽 자식으로 탐색을 진행하며 구한 구간 합을 더한 값을 반환
    	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
	```
- 이제 특정 위치의 값을 바꾸는 함수를 만들어 보자.<br>
그 숫자가 포함된 구간을 담당하는 모든 노드의 구간 합을 업데이트해 주어야 한다.
	- a 벡터의 5번째 값을 변경하는 경우 발생하는 업데이트
		![image](https://user-images.githubusercontent.com/68049320/151564161-d21f8246-c81c-4933-813f-b8fd2d5c1434.png)
	```c++
	void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    	if (index < start || index > end) // 현재 범위(start ~ end)가 탐색 위치(index)를 벗어난다면 재귀 함수 호출 종료
			return;
    	tree[node] = tree[node] + diff; // (변경된 값 - 기존 값)을 현재 구간 합에 더함
    	if (start != end) { // Leaf node인 경우 더 이상 아래로 탐색을 진행하지 않음
			// 루트 노드부터 시작하여, 각각 왼쪽 자식과 오른쪽 자식의 구간 합을 업데이트함
        	update(tree, node * 2, start, (start + end) / 2, index, diff);
        	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    	}
	}
	```
## 💻 구현 코드
```c++
long long init(const vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    if (start == end) 
        return tree[node] = a[start];
    return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end); 
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) 
        return;

    tree[node] += diff;
    if (start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

long long sum(const vector<long long>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) 
        return 0;
    if (left <= start && end <= right) 
        return tree[node];
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
	
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int h = ceil(log2(n));
    vector<long long> tree(1 << (h + 1));
    init(a, tree, 1, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;

        if (u == 1) {
            long long diff = w - a[v - 1];
            a[v - 1] = w;
            update(tree, 1, 0, n - 1, v - 1, diff);
        }
        else if (u == 2) 
            cout << sum(tree, 1, 0, n - 1, v - 1, w - 1) << '\n';
    }

	return 0;
}
```
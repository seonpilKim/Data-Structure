# [[2263] 트리의 순회](https://www.acmicpc.net/problem/2263)

## 🤔접근
- 중위 순회와 후위 순회 모두 맨 왼쪽 자식부터 탐색을 시작한다.
- 후위 순회는 항상 루트 노드를 마지막에 탐색한다.
- 위의 특성을 이용하여 전위 순회를 구할 수 있다.
___
## 💡풀이
- <B>알고리즘</B>
- <b>자료구조</b>
	- `Tree`
- <b>구현</b>
	- 후위 순회는 항상 마지막에 루트 노드를 탐색한다는 특성을 이용하여, 현재 탐색 범위에서 루트 노드가 무엇인지 찾는다.
    - 해당 노드가 중위 순회에서 몇 번째 인덱스에 위치하는지 찾으면, 왼쪽 서브트리와 오른쪽 서브트리를 구분할 수 있게 된다.
    - 먼저 루트 노드를 출력한 다음, 순서대로 왼쪽 서브트리와 오른쪽 서브트리를 탐색하면서 위와 같은 방식으로 순회하면 전위 순회를 할 수 있다.
        - 왼쪽 서브 트리를 탐색할 때는, 후위 순회에서 루트 노드의 위치는 다음과 같이 구할 수 있다.
            - 현재 후위 순회 루트 노드의 위치에서 오른쪽 서브트리 노드 개수를 빼준 값 (`post_root - end + in_root`)
        - 오른쪽 서브 트리릍 탐색할 때는, 후위 순회 루트 노드의 위치에서 1 빼준 값이다.
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
void preorder(const vector<int>& postorder, const vector<int>& inorder, const vector<int>& inroot,
	int start, int end, int post_root) {
	if (start >= end)
		return;

	int in_root = inroot[postorder[post_root]];

	cout << inorder[in_root] << ' ';
	preorder(postorder, inorder, inroot, start, in_root, post_root - end + in_root);
	preorder(postorder, inorder, inroot, in_root + 1, end, post_root - 1);
}
```
# [[4256] 트리](https://www.acmicpc.net/problem/4256)

## 🤔접근
- 중위 순회를 기준으로 보았을 때, 탐색 순서는 다음과 같아야 후위 순회를 구할 수 있다.
	- 루트 노드 왼쪽에 있는 노드들 탐색 -> 루트 노드 오른족에 있는 노드들 탐색 -> 루트 노드 탐색
___
## 💡풀이
- <B>알고리즘</B>
- <b>자료구조</b>
	- `Tree`
- <b>구현</b>
	- 전위 순회는 루트부터 탐색하므로, 맨 처음 인덱스가 루트 노드이다.
	- 이를 이용하여, 먼저 중위 순회에서 루트 노드와 동일한 노드의 인덱스를 찾는다.
	- 다음으로 중위 순회의 `[start, in_root)`, `(in_root, end]` 범위를 순서대로 탐색한 후에 루트 노드를 출력하는 과정을 반복한다.
___
## ✍ 피드백
___
## 💻 핵심 코드
```c++
void postorder(const vector<int>& preorder, const vector<int>& inorder, int start, int end, int pre_root) {
    if (start == end)
        return;

    int in_root = find(inorder.begin() + start, inorder.begin() + end, preorder[pre_root]) - inorder.begin();

    postorder(preorder, inorder, start, in_root, pre_root + 1);
    postorder(preorder, inorder, in_root + 1, end, pre_root + in_root - start + 1);

    cout << inorder[in_root] << ' ';
}
```
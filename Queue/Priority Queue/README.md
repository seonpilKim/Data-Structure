# Priority Queue, 우선순위 큐

## 개념
- `우선순위`가 가장 높은 데이터가 큐에서 먼저 나오는 자료구조로, 아래와 같이 3 가지 방법으로 구현할 수 있다.
	1. `정렬된 배열` 기반 구현
		- 탐색 연산 : `O(1)`
		- 삽입 연산 : `O(N)`
		- 삭제 연산 : `O(1)`
	2. `정렬된 연결리스트` 기반 구현
		- 탐색 연산 : `O(1)`
		- 삽입 연산 : `O(N)`
		- 삭제 연산 : `O(1)`
	3. `힙` 기반 구현
		- 탐색 연산 : `O(1)`
		- 삽입 연산 : `O(log N)`
		- 삭제 연산 : `O(log N)`
- `힙 기반`으로 구현하는 것이 가장 효율적인 것을 알 수 있다.
- 보편적으로 우선순위 큐의 원소(entry) 형태는 `Pair(key, value)` 이며, `Max-Heap 기반`으로 구현하였다.
- [[자료구조 힙] 바로가기](https://github.com/seonpilKim/Data-Structure/tree/master/Tree/Heap)
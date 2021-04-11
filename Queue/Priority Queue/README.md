# Priority Queue, 우선순위 큐

## 개념
- 우선순위가 가장 높은 데이터가 큐에서 먼저 나오는 자료구조이다.
- 정렬된 배열, 정렬된 연결리스트, 힙 기반으로 구현이 가능하며, `힙 기반 구현`이 가장 효율적이다.
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
- 보편적으로 우선순위 큐의 원소(entry) 형태는 `Pair(key, value)` 이며, `Max-Heap 기반`으로 구현하였다.
- [[자료구조 힙(Heap)] 바로가기](https://github.com/seonpilKim/Data-Structure/tree/master/Tree/Heap)

## C++ STL
- 헤더 파일
```c++
#include <queue>
```
- 선언
```c++
// priority_queue<자료형, Container, 비교함수> 식별자;
priority_queue<pair<int, int>, vector<pair<int ,int>>, compare> pq;
struct compare{
	bool operator()(const pair<int, int>& n1, const pair<int, int>& n2){
		return (n1.first >= n2.first) ? true : false;
	}
}
```
- 우선순위 큐에 원소를 삽입
	- 내부적으로 우선순위에 따라 정렬된다.
	- 우선순위가 가장 높은 원소가 우선순위 큐의 맨 앞으로 오게 된다.
```c++
pq.push(make_pair(key, value));
```
- 우선순위 큐의 맨 앞에 있는 원소 삭제
```c++
pq.pop();
```
- 우선순위 큐의 맨 앞에 있는 원소 반환
```c++
T front_element = pq.top();
```
- 우선순위 큐에 들어있는 원소 개수를 int 타입으로 반환
```c++
int size = pq.size();
```
- 우선순위 큐가 비어있는지 여부를 bool 타입으로 반환
```c++
bool isempty = pq.empty();
```
- 서로 다른 우선순위 큐간에 원소들 교환
```c++
priority_queue<T> pq1;
priority_queue<T> pq2;
pq1.swap(q2);
```
- C++11 emplace
```c++
priority_queue<int> pq;
pq.push(make_pair(1, 2));
pq.emplace(1, 2); // 불필요한 복사 or 이동 작업을 피하면서 새로운 요소 구성 가능
```
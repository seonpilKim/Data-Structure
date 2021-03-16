[General Tree, 일반 트리]

# 개념 : 그래프의 일종으로, 여러 노드가 한 노드를 가리킬 수 없는 비선형 구조이다. 간단하게는 사이클(cycle)이 없고, 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프를 트리라고 부른다.

# 종류 : 
 - Binary Tree
 - Binary Search Tree
 - AVL Tree
 - Red-Black Tree
 - etc.

# 연산 : 
 - insert(par_data, data) : par_data를 갖는 부모노드에 data를 가진 자식노드를 삽입.
 - remove(data) : data를 갖는 노드를 제거하고, 제거한 노드의 자식노드를 부모노드에 추가.
 - height() : 트리의 높이를 반환.
 - root() : 트리의 root 노드의 data를 반환.
 - size() : 트리의 노드개수를 반환.
 - empty() : 트리에 노드가 존재하면 true, 그렇지 않으면 false를 반환.
 - preorder() : 트리에 존재하는 노드를 전위순회.
 - postorder() : 트리에 존재하는 노드를 후위순회.

# 구현 : 연결리스트(Linked-List)와 벡터(Vector)를 이용하여 노드(Node)와 트리(Tree)를 구현함.

# 시간복잡도 : 
 - 삽입 : O(n)
 - 삭제 : O(n)
 - 탐색 : O(n)

p.s) 트리의 높이는 각 노드마다 깊이(depth)를 유지하면 O(1)에 구할 수 있다.
그러나, 구현한 코드에서는 노드를 제거하면 부모노드에 자식노드를 이동시키기 때문에, 매번 높이를 갱신해주도록 했다.

# 사용 용도
 - 파일 시스템(File System)
 - 계층적 데이터 관리 시스템
 - etc.
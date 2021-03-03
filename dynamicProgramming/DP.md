# Dynamic Programming
## DP Vs. Divide & Conquer
1. 두 방식 모두 subproblem을 이용하는 점에서 비슷하다. 
2. dp: subproblem들의 값을 특정 container에 저장하고, 추후에 동일한 문제를 만나면 값만 바로 반환하는 방식이다. 
3. divide&conquer: 하나의 문제를 여러 개의 문제로 나누어 하나씩 풀어 합치는 (conquer) 방식이다. DP와는 달리 겹치는 subproblem이 없다는 것이 특징. 
## Hallmarks of DP
1. Optimal Substructure를 모든 문제에 적용할 수 있다. 즉, 모든 subproblem들의 형태는 동일하며, 이에 적용되는 optimal solution은 항상 동일하다. 
2. 재귀적으로 구현하면 각 노드가 subproblem을 나타내는 재귀 트리를 그릴 수 있는데, 동일한 subproblem을 만나게 될 가능성이 있다. 
## DP의 효능
1. 보통 bruteforce를 하거나 끝없는 재귀호출을 하며 문제를 풀면 exponential한 시간 복잡도가 나온다. DP를 적용하면 시간 복잡도가 polynomial하게 줄어드는 효과를 볼 수 있다. 
## Top-Down & Bottom-Up
직관적으로 생각하면 전자는 재귀호출을, 후자는 반복문을 이용해서 문제를 해결하는 것으로 볼 수 있다.     
1. Top-Down   
	1. 재귀 호출을 이용해서 구현   
	2. 재귀 함수의 처음에는 이전에 해당 문제를 풀었는지 검사하는 table look up이 자리한다.    
2. Bottom-Up   
	1. 주로 반복문을 이용해서 구현   
	2. 알고리즘의 진행은 subproblem의 ‘크기’에 의거한다.    
	3. 작은 크기의 문제들 부터 풀기 시작한다.   
	4. 큰 문제를 풀때는 종전에 풀어 둔 작은 문제들이 포함되어 있으며(depends on smaller subproblems), 저장해 둔 결과를 이용해서 빠르게 풀어나갈 수 있다.     

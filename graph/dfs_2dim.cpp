/*
 * Author: lufovic77@gmail.com
 *
 * This implementation is about DFS. 
 * Among, DFS with 2-dimensional array.
 * With V vertices, the time complextiy would be O(V^2)
 *
 * DFS 'might' find the optimal case, but in terms of optimal, 
 * recommend to use BFS rather. 
 *
 * 결과를 볼때 주의 깊게 볼거는 
 * dfs가 기본적으로 재귀이므로 스택의 형태로 탐색이 진행된다. 
 * dr, dc의 순서에 의한 방향을 보고 어디를 방문할지 예상해보자. 
 * */
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, n) for(int i=0;i<n;i++)
vector<vector<int> > map; //5 x 5 map (No matter if  using array)
int dr[4] = {-1, 0, 1, 0}; // row index: up, right, down, left
int dc[4] = {0, 1, 0, -1}; // column
bool visited[100][100];
void dfs(int r, int c){
	if(visited[r][c])
		return ;
	cout<<map[r][c]<<", "<<r<<" "<<c<<endl;
	visited[r][c] = true;
	FOR(i, 4){
		int newr = r + dr[i];
		int newc = c + dc[i];
		if(newr>=0 && newr<5 && newc>=0 && newc<5 && !visited[newr][newc])
			dfs(newr, newc);
	}
	return ;
}
int main(){
	FOR(i, 5){
		vector<int> tmp;
		FOR(j, 5){
			tmp.push_back(j);
		}
		map.push_back(tmp);
	}	
	dfs(0, 0);
	return 0;
}

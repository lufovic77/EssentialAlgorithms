/*
 * Author: lufovic77@gmail.com
 *
 * This implementation is about BFS. 
 * Among, BFS with 2-dimensional array.
 * With V vertices, the time complextiy would be O(V^2)
 *
 * BFS searches graph as a queue (DFS uses a stack)
 * 결과를 볼때 주의 깊게 볼거는 
 * bfs는 주위를 한겹 한겹 확장해나가면서 본다. 
 *
 * * dr, dc의 순서에 의한 방향을 보고 어디를 방문할지 예상해보자. 
 * */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i, n) for(int i=0;i<n;i++)
vector<vector<int> > map; //5 x 5 map (No matter if  using array)
int dr[4] = {-1, 0, 1, 0}; // row index: up, right, down, left
int dc[4] = {0, 1, 0, -1}; // column
bool visited[100][100];
void bfs(int r, int c){
	queue<pair<int, int> > q;
	q.push(make_pair(r, c));
	visited[r][c] = true;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int curR = p.first;
		int curC = p.second;
		cout<<map[curR][curC]<<", "<<curR<<" "<<curC<<endl;
		FOR(i, 4){
			int newr = curR + dr[i];
			int newc = curC + dc[i];
			if(newr>=0 & newr<5 && newc>=0 && newc<5 && !visited[newr][newc]){
				visited[newr][newc] = true;
				q.push(make_pair(newr, newc));
			}
		}
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
	bfs(0, 0);
	return 0;
}

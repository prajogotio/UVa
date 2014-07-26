#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int R,C,M,N,W;
int score;
int vis[103][103];

void check(queue<pair<int,int> > &q, int &state, int i, int j){
	//printf("%d %d\n", i, j);
	if(vis[i][j] != -1) ++state;
	if(vis[i][j] == -2) {
		q.push(make_pair(i,j));
		vis[i][j] = -3;
	}
}
//BFS WHY BFS..
void bfs(){
	queue<pair<int, int> > q;
	q.push(make_pair(0,0));
	while(!q.empty()){
		pair<int,int> g = q.front();
		int i = g.first, j = g.second;
		//printf("%d %d %d\n", i, j, vis[i][j]);
		q.pop();
		int state = 0;
		if(M == 0 || N == 0){
			int K = max(M,N);
			if(i - K >= 0){
				check(q, state, i-K, j);
			}
			if(i + K < R){
				check(q,state, i+K, j);
			}
			if(j - K >= 0){
				check(q,state, i, j-K);
			}
			if(j + K < C){
				check(q, state, i, j+K);
			}
		} else {
			if(i + M < R && j + N < C){
				check(q, state, i+M, j+N);
			}
			if((M!=N) && i + N < R && j + M < C){
				check(q, state, i+N, j+M);
			}
			if(i - N >= 0 && j + M < C){
				check(q, state, i-N, j+M);
			}
			if((M!=N) && i - M >= 0 && j + N < C){
				check(q, state, i-M, j+N);
			}
			if(i + M < R && j - N >=0){
				check(q,state,i+M,j-N);
			}
			if((M!=N) && i+N<R && j-M>=0){
				check(q,state,i+N,j-M);
			}
			if(i-N>=0 && j-M>=0){
				check(q,state,i-N,j-M);
			}
			if((M!=N) && i-M>=0 && j-N>=0){
				check(q,state,i-M,j-N);
			}
		}
		vis[i][j] = state;
	}
}

int main(){
	int TC,T=1,W;
	scanf("%d",&TC);
	while(TC--){
		printf("Case %d: ", T++);
		score = 0;
		scanf("%d %d %d %d", &R, &C, &M, &N);
		for(int i=0;i<R;++i)
			for(int j=0;j<C;++j)
				vis[i][j] = -2;

		vis[0][0] = -3;
		scanf("%d",&W);
		for(int i=0;i<W;++i){
			int u,v;
			scanf("%d %d",&u,&v);
			vis[u][v] = -1;
		}
		if(M==0 && N==0) {
			printf("0 1\n");
			continue;
		}
		bfs();
		int even = 0, odd = 0;
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(vis[i][j] != -1 && vis[i][j] != -2){
					if(vis[i][j] %2 == 0) ++even;
					else ++odd;
				}
			}
		}
		printf("%d %d\n", even, odd);
	}
	return 0;
}

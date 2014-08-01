#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int vis[1003][1003];
int R,C;
int x,y,s,t, dist;

void bfs(){
	int u,v,d;
	vis[x][y] = 1;
	queue<pair<int, pair<int,int> > > q;
	q.push(make_pair(0, make_pair(x,y)));
	while(!q.empty()){
		u = q.front().second.first;
		v = q.front().second.second;
		d = q.front().first;
		//printf("%d %d %d\n", u,v,d);
		q.pop();
		if(u > 0 && !vis[u-1][v]){
			if(s == u-1 && t == v){
				dist = d+1;
				return;
			}
			vis[u-1][v] = 1;
			q.push(make_pair(d+1, make_pair(u-1,v)));
		}
		if(v > 0 && !vis[u][v-1]){
			if(s == u && t == v-1){
				dist = d+1;
				return;
			}
			vis[u][v-1] = 1;
			q.push(make_pair(d+1, make_pair(u,v-1)));
		}
		if(u < R-1 && !vis[u+1][v]){
			if(s == u+1 && t == v){
				dist = d+1;
				return;
			}
			vis[u+1][v] = 1;
			q.push(make_pair(d+1, make_pair(u+1, v)));
		}
		if(v < C-1 && !vis[u][v+1]){
			if(s == u && t == v+1){
				dist = d+1;
				return;
			}
			vis[u][v+1] = 1;
			q.push(make_pair(d+1, make_pair(u,v+1)));
		}
	}
}

int main(){
	int B, r,n,c;
	while(scanf("%d %d", &R, &C), R+C != 0){
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				vis[i][j] = 0;
			}
		}
		scanf("%d", &B);
		while(B--){
			scanf("%d %d", &r, &n);
			while(n--){
				scanf("%d", &c);
				vis[r][c] = 1;
			}
		}
		scanf("%d %d", &x, &y);
		scanf("%d %d", &s, &t);
		bfs();
		printf("%d\n", dist);
	}
	return 0;
}
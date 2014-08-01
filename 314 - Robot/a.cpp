#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int map[52][52];
int vis[52][52][4];
int R, C, ans;

bool check2(int u, int v){
	bool a,b,c,d;
	a=b=c=d=false;
	if(map[u][v] == 0) d = true;
	if(u-1 >= 0 && map[u-1][v] == 0) a = true;
	if(u-1 >= 0 && v-1>=0  && map[u-1][v-1] == 0) b = true;
	if(v-1 >= 0 && map[u][v-1] == 0) c = true;
	return a && b && c && d;
}

void check(int u, int v, int d, int state, int p, priority_queue<pair<pair<int,int>, pair<int,int> > > &q){
	if(state == 1){
		if(u - p >= 1 && !vis[u-p][v][state]){
			bool ch = true;
			for(int i=1;i<=p;++i){
				ch &= check2(u-i, v);
			}
			if(ch){
				vis[u-p][v][state] = 1;
				q.push(make_pair(make_pair(-(d+1), state), make_pair(u-p,v)));
			}
		}
	}
	if (state == 2){
		if(v + p <= C-1 && !vis[u][v+p][state]){
			bool ch = true;
			for(int i=1;i<=p;++i){
				ch &= check2(u, v+i);
			}
			if(ch){
				vis[u][v+p][state] = 1;
				q.push(make_pair(make_pair(-(d+1), state), make_pair(u,v+p)));
			}
		}
	}
	if (state==3){
		if(u + p <= R-1 && !vis[u+p][v][state]){
			bool ch = true;
			for(int i=1;i<=p;++i){
				ch &= check2(u +i, v);
			}
			if(ch){
				vis[u+p][v][state] = 1;
				q.push(make_pair(make_pair(-(d+1), state), make_pair(u+p, v)));
			}
		}
	}
	if (state == 0){
		if(v - p >= 1 && !vis[u][v-p][state]){
			bool ch = true;
			for(int i=1;i<=p;++i){
				ch &= check2(u, v-i);
			}
			if(ch){
				vis[u][v-p][state] = 1;
				q.push(make_pair(make_pair(-(d+1), state), make_pair(u, v-p)));
			}
		}
	}
}

void bfs(int u, int v, int s, int t, int state){
	//printf("%d %d %d %d %d\n", u, v, s, t, state);
	priority_queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push(make_pair(make_pair(0, state), make_pair(u, v)));
	vis[u][v][state] = 1;
	while(!q.empty()){
		int x = q.top().second.first, y = q.top().second.second;
		int d = - (q.top().first.first);
		int d2, st2;
		int st = q.top().first.second;
		q.pop();
		//printf("%d %d %d %d\n", x, y, d, st);
		if(x == s && y == t){
			ans = d;
			return;
		}
		for(int i=1; i<=3;++i){
			check(x, y, d, st, i, q);
		}
		st2 = (st+1)%4;
		if(!vis[x][y][st2]){
			vis[x][y][st2] = 1;
			q.push(make_pair(make_pair(-(d+1), st2), make_pair(x,y)));
		}
		st2 = (st+3)%4;
		if(!vis[x][y][st2]){
			vis[x][y][st2] = 1;
			q.push(make_pair(make_pair(-(d+1), st2), make_pair(x,y)));
		}
	}
	ans = -1;
}

int main(){
	while(scanf("%d %d", &R, &C), R+C!=0){
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				scanf("%d", &map[i][j]);
				for(int k=0;k<4;++k){
					vis[i][j][k] = 0;
				}
			}
		}
		int u,v,s,t, state;
		scanf("%d %d %d %d", &u, &v, &s, &t);
		string str;
		cin >> str;
		if(str == "south") state = 3;
		if(str == "north") state = 1;
		if(str == "west") state = 0;
		if(str == "east") state = 2;
		bfs(u,v,s,t,state);
		printf("%d\n", ans);
	}
	return 0;
}
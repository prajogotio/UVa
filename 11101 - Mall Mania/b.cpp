#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int> > mall1;
int vis[2003][2003]; //mall1 vis 1 mall2 vis 2, -1, 0
int ans, N, M;
bool reached;
void check(int u, int v, int d, queue<pair<int, pair<int,int> > > &q){
	if(reached) return;
	//printf("%d %d %d\n", u,v,d);
	if(u < 0 || v < 0 || u >= 2000 || v>=2000)return;
	if(vis[u][v] == 2){
		ans = d+1;
		reached = true;
		return;
	}
	if(vis[u][v] == -1){
		vis[u][v] = 0;
		q.push(make_pair((d+1), make_pair(u,v)));
	}
}

void bfs(){
	queue<pair<int, pair<int,int> > > q;
	for(int i=0;i<mall1.size();++i){
		q.push(make_pair(0, make_pair(mall1[i].first, mall1[i].second)));
	}
	while(!q.empty()){
		int d = q.front().first;
		int u = q.front().second.first;
		int v = q.front().second.second;
		q.pop();
		//printf("%d %d %d %d\n", u, v, d, vis[u][v]);
		check(u-1, v, d, q);
		check(u+1, v, d, q);
		check(u, v-1, d, q);
		check(u, v+1, d, q);
		if(reached) return;
	}
}

int main(){
	int u,v;
	while(scanf("%d", &N), N!=0){
		ans = 2000000000;
		mall1.clear();
		reached = false;
		for(int i=0;i<2000;++i){
			for(int j=0;j<2000;++j){
				vis[i][j] = -1;
			}
		}
		for(int i=0;i<N;++i){
			scanf("%d %d", &u, &v);
			vis[u][v] = 1;
			mall1.push_back(make_pair(u,v));
		}
		scanf("%d", &M);
		for(int i=0;i<M;++i){
			scanf("%d %d", &u, &v);
			vis[u][v] = 2;
		}
		bfs();
		if(ans == 2000000000) printf("0\n");
		else printf("%d\n", ans);

	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int maxint = (int) 1e9;
vector<vector<int> > adj;
int lvl[102][6];
int dist[102][6];
int t[6];
int K, n, ans;
void djikstra(){
	priority_queue<pair<int,pair<int,int> > > pq;
	for(int i=0;i<102;++i)
		for(int j=0;j<6;++j)
			dist[i][j] = maxint;

	for(int i=1;i<=n;++i){
		if(lvl[0][i] != -1){
			dist[0][i] = 1;
			pq.push(make_pair(0, make_pair(0, i)));
		}
	}
	while(!pq.empty()){
		int d = -pq.top().first;
		int u = pq.top().second.first;
		int st = pq.top().second.second;
		int cur = adj[st][u];
		pq.pop();
		//printf("u = %d, st = %d, cur = %d, d = %d\n", u, st, cur, d);
		if(cur == K){
			ans = d;
			return;
		}
		if(dist[cur][st] < d) continue;
		if(u+1 < adj[st].size()){
			int nxt = adj[st][u+1];
			int w = (nxt - cur)*t[st];
			if(dist[nxt][st] > d + w){
				dist[nxt][st] = d+w;
				pq.push(make_pair(-(d+w), make_pair(u+1, st)));
			}
		}
		if(u-1 >= 0){
			int nxt = adj[st][u-1];
			int w = (cur-nxt)* t[st];
			if(dist[nxt][st] > d+w){
				dist[nxt][st] = d+w;
				pq.push(make_pair(-(d+w), make_pair(u-1, st)));
			}
		}
		for(int i=1;i<=n;++i){
			if(i==st) continue;
			int v = lvl[cur][i];
			if(v != -1){
				if(dist[cur][i] > d + 60){
					dist[cur][i] = d + 60;
					pq.push(make_pair(-(d+60), make_pair(v, i)));
				}
			}
		}
	}
}


int main(){
	while(scanf("%d %d", &n, &K)!=EOF){
		//printf("%d %d test\n", n, K);
		for(int i=1;i<=n;++i){
			scanf("%d", &t[i]);
		}
		adj = vector<vector<int> >(n+2);
		ans = -1;
		for(int i=0;i<102;++i){
			for(int j=1;j<=n;++j){
				lvl[i][j] = -1;
			}
		}
		for(int i=1;i<=n;++i){
			int p, idx = 0;
			while(scanf("%d", &p)!=EOF){
				adj[i].push_back(p);
				lvl[p][i] = idx;
				char c = getchar();
				++idx;
				if(c == '\n') break;
			}
		}
		djikstra();
		if(ans == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}
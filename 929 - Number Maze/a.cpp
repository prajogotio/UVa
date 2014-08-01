#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
ll maxll = (ll) 2e17;
ll vis[1003][1003];
ll val[1003][1003];
int N, M;

void check(int u, int v, int dist, priority_queue<pair<int, pair<int,int> > > &pq){
	if(u <0 || v <0 || u >= N || v >= M) return;
	if(vis[u][v] > val[u][v] + dist){
		vis[u][v] = val[u][v] + dist;
		pq.push(make_pair(-vis[u][v], make_pair(u,v)));
	}
}

void djikstra(){
	for(int i = 0;i <N;++i)
		for(int j=0;j<M;++j){
			vis[i][j] = maxll;
		}
	vis[0][0] = val[0][0];
	priority_queue<pair<int, pair<int,int> > > pq;
	pq.push(make_pair(-val[0][0], make_pair(0,0)));
	while(!pq.empty()){
		ll dist = -pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		//printf("%d %d %lld\n", u, v, dist);
		pq.pop();
		if(vis[u][v] < dist) continue;
		check(u-1, v, dist, pq);
		check(u, v-1, dist, pq);
		check(u+1, v, dist, pq);
		check(u, v+1, dist, pq);
	}

}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf(" %d %d", &N, &M);
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				scanf("%lld", &val[i][j]);
			}
		}
		djikstra();
		printf("%lld\n", vis[N-1][M-1]);
	}
	return 0;
}
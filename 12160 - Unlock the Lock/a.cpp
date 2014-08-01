#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int vis[10002], but[13];
int B, U, V;
int ans;

void bfs(int u, int v){
	queue<pair<int,int> > q;
	q.push(make_pair(0, u));
	vis[u] = 1;
	while(!q.empty()){
		int d = q.front().first;
		int s = q.front().second;
		q.pop();
		for(int i=0;i<B;++i){
			int t = (s+but[i])%10000;
			if (t == v){
				ans = d+1;
				return;
			}
			if(!vis[t]){
				vis[t] = 1;
				q.push(make_pair(d+1, t));
			}
		}
	}
	ans = -1;
}

int main(){
	int T=1;
	while(scanf("%d %d %d", &U, &V, &B), U+V+B!=0){
		printf("Case %d: ", T++);
		for(int i=0;i<10000;++i){
			vis[i] = 0;
		}
		for(int i=0;i<B;++i){
			scanf("%d", &but[i]);
		}
		bfs(U, V);
		if(U == V) printf("0\n");
		else if(ans == -1) printf("Permanently Locked\n");
		else printf("%d\n", ans);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

vector<vector<int> > adj;
int E;
vector<int> track;

void bfs(int s){
	track = vector<int>(E+2, 0);
	int vis[2502] = {0};
	queue<pair<int, int> > q;
	vis[s] = 1;
	q.push(make_pair(s, 0));
	while(!q.empty()){
		int u = q.front().first, d = q.front().second;
		q.pop();
		for(int i=0;i<adj[u].size();++i){
			int v = adj[u][i];
			if(vis[v] == 0){
				//printf("%d %d %d\n", u, v, d+1);
				++track[d+1];
				vis[v] = 1;
				q.push(make_pair(v, d+1));
			}
		}
	}
}

int main(){
	scanf("%d", &E);
	adj = vector<vector<int> > (E+3);
	for(int i =0 ;i<E;++i){
		int k;
		scanf("%d", &k);
		for(int j=0;j<k;++j){
			int b;
			scanf("%d", &b);
			adj[i].push_back(b);
		}
	}
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int s;
		scanf("%d", &s);
		bfs(s);
		int bloom=0, day = -1;
		for(int i=0;i<track.size();++i){
			if(track[i] > bloom){
				bloom = track[i];
				day = i;
			}
		}
		if(bloom == 0) printf("0\n");
		else printf("%d %d\n", bloom, day);
	}
	return 0;
}

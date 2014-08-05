#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
int maxint = (int) 2e9;
vector<vector<pair<int, pair<int, int> > > > adj;
int dist[5000][26];
map<string, int> dict;
int M, N, ans;

void djikstra(){
	priority_queue<pair<int, pair<int,int> > > pq;
	for(int i=0; i<=N; ++i){
		for(int j=0;j<26;++j){
			dist[i][j] = maxint;
		}
	}
	for(int i=0;i<26;++i){
		dist[0][i] = 0;
	}
	for(int i = 0; i < adj[0].size();++i){
		int u = adj[0][i].first;
		int w = adj[0][i].second.first;
		int q = adj[0][i].second.second;
		pq.push(make_pair(-w, make_pair(u, q)));
	}
	while(!pq.empty()){
		int d = -pq.top().first;
		int u = pq.top().second.first;
		int st = pq.top().second.second;
		pq.pop();
		//printf("%d %d %d\n", d, u, st);
		if(u == 1){
			ans = d;
			return;
		}
		if(dist[u][st] < d) continue;
		for(int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			int w = adj[u][i].second.first;
			int q = adj[u][i].second.second;
			//printf("%d %d %d %d \n", u, v, w, q);
			if(q == st) continue;
			if(dist[v][q] > d + w){
				dist[v][q] = d+w;
				pq.push(make_pair(-(d+w), make_pair(v, q)));
			}
		}
	}
}

int main(){
	string a, b, c;
	int u, v, w, q;
	while(scanf("%d", &M), M!= 0){
		adj = vector<vector<pair<int,pair<int, int> > > > (5000);
		dict.clear();
		N = 0; ans = -1;
		cin >> a >> b;
		dict[a] = N++;
		dict[b] = N++;
		for(int i=0;i<M;++i){
			cin >> a >> b >> c;
			if(dict.find(a) == dict.end()){
				dict[a] = N++;
			}
			if(dict.find(b) == dict.end()){
				dict[b] = N++;
			}
			u = dict[a];
			v = dict[b];
			w = c.size();
			q = c[0] - 'a';
			adj[u].push_back(make_pair(v, make_pair(w, q)));
			adj[v].push_back(make_pair(u, make_pair(w, q)));
			//printf("%d %d %d %d\n", u, v , w ,q);
		}
		djikstra();
		if(ans == -1) printf("impossivel\n");
		else printf("%d\n", ans);
	}
	return 0;
}

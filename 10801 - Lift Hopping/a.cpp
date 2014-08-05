#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int adj[101][101][7];
int dist[101][7];
int n, k;
vector<vector<int> > serve;

void djikstra(){
	priority_queue<pair<int, pair<int,int> > > pq;
	for(int i=1;i<=n;++i){
		pq.push(make_pair(-adj[0][0][i], make_pair(0, i)));
		dist[0][i] = adj[0][0][i];
	}
	while(!pq.empty()){
		int d = -pq.top().first;
		int u = pq.top().second.first;
		int st = pq.top().second.second;
		pq.pop();
		if(dist[u][st] < d) continue;

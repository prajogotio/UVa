#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int maxint = (int) 10000;
vector<pair<int,int> edge;
int room[103];
int dist[103];
int N;
void bellman(){
	int sz = edge.size();
	for(int i =0;i<=N;++i){
		dist[i] = maxint;
	}
	dist[1] = 0;
	for(int k=0;k<sz+1;++k){
		bool relaxed = false;
		for(int i=0;i<sz;++i){
			int u = edge[i].first;
			int v = edge[i].second;
			int w = -room[v];
			if(dist[u] == maxint) continue;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				relaxed = true;
			}
		}
		if(!relaxed) break;
	}
	for(int i=0;i<sz;++i){
		int u = edge[i].first;
		int v = edge[i].second;
		int w = -room[v];
		if(dist[u] == maxint) continue;
		if(dist[v] > dist[u] + w){
			dist[v] = -maxint;
			dist[w] = -maxint;
		}
	}
}

int main(){
	

}
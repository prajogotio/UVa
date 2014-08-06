#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
int maxint = (int) 1e9;
map<string, int> dict;
int adj[53][53];
int N,M;

void floyd(){
	for(int k=0;k<N;++k)
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main(){
	string p, q;
	int ip, iq, n, T=1;
	while(scanf("%d %d", &N, &M), N+M != 0){
		printf("Network %d: ", T++);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j)
				adj[i][j] = maxint;
			adj[i][i] = 0;
		}
		dict.clear();
		n = 0;
		for(int i=0;i<M;++i){
			cin >> p >> q;
			if(dict.find(p) == dict.end()){
				dict[p] = n++;
			}
			if(dict.find(q) == dict.end()){
				dict[q] = n++;
			}
			ip = dict[p];
			iq = dict[q];
			adj[ip][iq] = 1;
			adj[iq][ip] = 1;
		}
		floyd();
		int deg = -1;
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				deg = max(adj[i][j], deg);
		if(deg == maxint) printf("DISCONNECTED\n");
		else printf("%d\n", deg);
		printf("\n");
	}
	return 0;
}
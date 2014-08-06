#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string,int> dict;
vector<string> name;
int adj[503][503];
int N;

void floyd(){
	for(int k=0;k<N;++k)
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				adj[i][j] |= (adj[i][k] & adj[k][j]);
}

int main(){
	int NC, NM, n, m, previ, nowi, T=1;
	string prev, now;
	while(scanf("%d", &NC), NC != 0){
		printf("Case %d, ", T++);
		dict.clear();
		name.clear();
		N = 0;
		for(int i=0;i<500;++i)
			for(int j=0;j<500;++j)
				adj[i][j] = 0;

		for(int i=0;i<NC;++i){
			scanf("%d", &n);
			cin >> prev;
			if(dict.find(prev) == dict.end()){
				name.push_back(prev);
				dict[prev] = N++;
			}
			previ = dict[prev];
			for(int i=1;i<n;++i){
				cin >> now;
				if(dict.find(now) == dict.end()){
					name.push_back(now);
					dict[now] = N++;
				}
				nowi = dict[now];
				adj[previ][nowi] = 1;
				previ = nowi;
				prev = now;
			}
		}
		scanf("%d", &NM);
		for(int i=0;i<NM;++i){
			cin >> prev; cin >> now;
			previ = dict[prev];
			nowi = dict[now];
			adj[previ][nowi] = 1;
		}
		floyd();
		int tot = 0;
		int x[2], y[2];
		for(int i=0;i<N;++i)
			for(int j=i+1;j<N;++j)
				if((adj[i][j] | adj[j][i]) == 0){
					if(tot < 2){
						x[tot] = i;
						y[tot] = j;
					}
					++tot;
				}

		if(tot == 0) printf("no concurrent events.\n");
		else {
			printf("%d concurrent events:\n", tot);
			for(int i=0; i < tot && i < 2; ++i){
				printf("(%s,%s) ", name[x[i]].c_str(), name[y[i]].c_str());
			}
			printf("\n");
		}
	}
	return 0;
}
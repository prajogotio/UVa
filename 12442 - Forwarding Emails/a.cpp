#include <iostream>
#include <cstdio>
using namespace std;
//WRONG, GRAPH IS DIRECTED
int par[50004];
int rank[50004];
int N;
int dsfind(int i){ return (par[i] == i) ? i : (par[i] = dsfind(par[i])) ; }
int dssame(int i, int j) { return dsfind(i) == dsfind(j); }
void dsunion(int i, int j) {
	if(dssame(i,j)) return;
	int x = dsfind(i), y = dsfind(j);
	par[x] = y;
	rank[y] = rank[x] + rank[y];
}

int main(){
	int TC, T=1;
	scanf("%d",&TC);
	while(TC--){
		printf("Case %d: ", T++);
		scanf("%d",&N);
		for(int i=0;i<=N;++i){
			par[i] = i;
			rank[i] = 1;
		}
		for(int i=0;i<N;++i){
			int u,v;
			scanf("%d %d", &u, &v);
			dsunion(u,v);
		}
		int maxval = -1, idx = -1;
		for(int i=1;i<=N;++i){
			if(maxval < rank[dsfind(i)]){
				maxval = rank[dsfind(i)];
				idx = i;
			}
		}
		printf("%d\n", idx);
	}
	return 0;
}
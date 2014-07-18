//PERSPECTIVE : RATHER THAN FROM A LOT TO A FEW, GENERATE FROM A FEW

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int p[10] = {3,5,7,11,13,17,19,23,29,31};
int c[32] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1};
vector<vector<int> > ans;
int N;

void dfs(vector<int> v, int s, int ctr){
	if(ctr == N){
		if(c[v[ctr-1] + 1]) ans.push_back(v);
		return;
	}
	for(int i=0;i<10;++i){
		int t = p[i] - v[ctr-1];
		if( t > N || t < 1) continue;
		if( s & (1<<(t-1))) continue;
		v.push_back(t);
		dfs(v, s|(1<<(t-1)), ctr+1);
		v.pop_back();
	}
}

int main(){
	int T=1;
	bool flag = false;
	while(scanf("%d",&N) != EOF){
		if(flag) printf("\n");
		printf("Case %d:\n", T++);
		ans.clear();
		dfs(vector<int>(1,1), 1, 1);
		/*
		for(it = ans.begin(); it != ans.end(); ++it){
			for(int i=0;i<N;++i){
				if(i!=0)printf(" ");
				printf("%d",(*it)[i]);
			}
			printf("\n");
		}
		*/
		for(int i=0;i<ans.size();++i){
			for(int j=0;j<N;++j){
				if(j!=0)printf(" ");
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
		flag = true;
	}
}
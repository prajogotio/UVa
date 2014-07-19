#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > adj;
int N, M;
int maxval,way[105];

void rec(vector<int> arr, int i){
	if(i==N+1){
		int temp=0;
		for(int i=1;i<=N;++i){
			if(arr[i]==1)
				++temp;
		}
		if(maxval < temp){
			maxval = temp;
			for(int i=1;i<=N;++i){
				way[i] = arr[i];
			}
		}
		return;
	}
	if(arr[i] != -1){
		rec(arr, i+1);
		return;
	}
	bool canblack = true;
	vector<int> temp = arr;
	temp[i] = 1;
	for(int j=0;j<adj[i].size();++j){
		int u = adj[i][j];
		if(arr[u] == 1){
			canblack = false;
			break;
		}
		temp[u] = 0;
	}
	if(canblack){
		rec(temp, i+1);
	}
	if(!adj[i].size()) return;
	arr[i] = 0;
	rec(arr, i+1);
}

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d %d", &N, &M);
		adj.assign(N+1, vector<int>());
		for(int i=0;i<M;++i){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		maxval = -1;
		rec(vector<int>(N+1, -1), 1);
		printf("%d\n", maxval);
		bool flag = false;
		for(int i=1;i<=N;++i){
			if(way[i]){
				if(flag) printf(" ");
				printf("%d", i);
				flag = true;
			}
		}
		printf("\n");
	}
	return 0;
}
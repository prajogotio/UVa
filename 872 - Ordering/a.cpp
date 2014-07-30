#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int indeg[26];
int isin[26];
vector<vector<int> > adj;
vector<vector<int> > ans;
int N;

void topo(vector<int> state, vector<int> arr, int ctr){
	/*
	for(int i=0;i<state.size(); ++i){
		printf("%d ", state[i]);
	}
	printf("\n");
	*/
	if(ctr == N){
		ans.push_back(arr);
		return ;
	}
	for(int i=0;i<26;++i){
		if(state[i] == 0){
			vector<int> temp = state;
			--temp[i];
			for(int j=0;j<adj[i].size();++j){
				--temp[adj[i][j]];
			}
			arr.push_back(i);
			topo(temp, arr, ctr + 1);
			arr.pop_back();
		}
	}
}

int main(){
	int TC;
	scanf("%d", &TC);
	getchar();
	bool flag = false;
	while(TC--){
		getchar();
		if(flag) printf("\n");
		string str;
		getline(cin, str);
		ans.clear();
		N = 0;
		for(int i=0;i<26;++i) {
			isin[i] = 0;
			indeg[i] = 0;
		}
		for(int i=0;i<str.size(); i += 2){
			char c = str[i];
			int u = c - 'A';
			isin[u] = 1;
			++N;
			//printf("%d\n", u);
		}
		adj = vector<vector<int> > (27);
		getline(cin, str);
		for(int i=0;i<str.size(); i += 4){
			int u = str[i] - 'A';
			int v = str[i+2] - 'A';
			//printf("%d %d\n", u, v);
			adj[u].push_back(v);
			++indeg[v];
		}
		for(int i=0;i<26;++i){
			if(isin[i] == 0){
				indeg[i] = -1;
			}
		}
		topo(vector<int>(indeg, indeg+26), vector<int>(), 0);
		sort(ans.begin(), ans.end());
		if(ans.empty()) {
			printf("NO\n");
			continue;
		}
		for(int i=0;i<ans.size();++i){
			for(int j=0;j<ans[i].size();++j){
				if(j != 0) printf(" ");
				//printf("%d", ans[i][j]);
				printf("%c", (char) (ans[i][j] + 'A') );
			}
			printf("\n");
		}
		flag = true;
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
string entry;
string list[203];
map<string, int> dict;
vector<vector<int> > adj;
int N;

int bfs(int u, int v){
	int vis[203] = {0};
	queue<pair<int, int> > q;
	q.push(make_pair(u, 0));
	while(!q.empty()){
		int t = q.front().first, d = q.front().second; q.pop();
		for(int i=0;i<adj[t].size();++i){
			int s = adj[t][i];
			if(s == v){
				return d+1;
			}
			if(vis[s] == 0){
				vis[s] = 1;
				q.push(make_pair(s, d+1));
			}
		}
	}
	return -1;
}

int main(){
	int Tc;
	scanf("%d", &Tc);
	bool flag = false;
	while(Tc--){
		if(flag) printf("\n");
		N = 0;
		while(cin >> entry){
			if(entry == "*") break;
			list[N] = entry;
			dict[entry] = N;
			++N;
		}
		getchar();
		adj = vector<vector<int> >(N+2);
		for(int i=0;i<N;++i){
			for(int j=i+1; j<N;++j){
				int diff = 0;
				if(list[i].size() != list[j].size()) continue;
				for(int k=0;k<list[i].size();++k){
					if(list[i][k] != list[j][k]) ++diff;
				}
				if(diff == 1){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}



		while(getline(cin, entry) ){
			if(entry.size() == 0) break;
			string a, b;
			for(int i=0;i<entry.size();++i){
				if(entry[i] == ' '){
					a = entry.substr(0, i);
					b = entry.substr(i+1, entry.size() - (i+1) );
					break;
				}
			}
			//cout << a << " " << b << endl;
			int u = dict[a], v = dict[b];
			int ans = bfs(u, v);
			cout << a << " " << b << " " << ans << endl;

		}	
		flag = true;

	}
	return 0;
}
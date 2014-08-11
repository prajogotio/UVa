#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int inf = (int) 1e9;
int res[40][40];
int par[40];
int vis[40];
int mf, f;

void augment(int u, int me){
	if(u == 0) { f = me; return; }
	else if (par[u] != -1) {
		augment(par[u], min(me, res[par[u]][u]));
		res[par[u]][u] -= f;
		res[u][par[u]] += f;
	}
}

void maxflow(){
	mf = 0;
	while(1){
		f = 0;
		for(int i=0;i<40;++i){
			par[i] = -1;
			vis[i] = 0;
		}
		queue<int> q;
		q.push(0);
		vis[0] = 1;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			if(u == 37) break;
			for(int i=0; i<= 37; ++i){
				if(res[u][i] > 0 && !vis[i]){
					vis[i] = 1;
					q.push(i);
					par[i] = u;
				}
			}
		}
		augment(37, inf);
		if(f == 0) break;
		//printf("%d\n", f);
		mf += f;
	}
}

int main(){
	string str;
	int work;
	while(1){
		for(int i=0;i<40;++i)
			for(int j=0;j<40;++j)
				res[i][j] = 0;
		for(int i=27;i<=36;++i)
			res[i][37] = 1;
		work = 0;
		bool flag = false;
		while(getline(cin, str)){
			if(str.size() == 0) break;
			int c = str[0] - 'A' + 1;
			int d = str[1] - '0';
			work += d;
			res[0][c] = d;
			int k = 3;
			while(str[k] != ';'){
				int p = str[k] - '0' + 27;
				res[c][p] = 1;
				++k;
			}
			flag = true;
		}
		if(!flag) break;
		maxflow();
		if(mf != work) printf("!\n");
		else {
			string ans = "__________";
			for(int i=1;i<=26;++i){
				for(int j=27;j<=36;++j){
					if(res[i][j] == 0 && res[j][i] == 1){
						ans[j-27] = (char) ('A' + i - 1);
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
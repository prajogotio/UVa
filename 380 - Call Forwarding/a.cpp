#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector<vector<pair<int,pair<int,int> > > > req; //source time duration target
int mark[10002];
int vis[10002];

int rec(int T, int R){
	if(vis[R]) return 9999;
	if(!mark[R]) return R;
	int idx = -1;
	for(int i=0;i<req[R].size();++i){
		if(req[R][i].second.first <= T && T <= req[R][i].second.second + req[R][i].second.first) {
			idx = req[R][i].first;
			break;
		}
	}
	if(idx == -1) return R;
	vis[R] = 1;
	return rec(T, idx);
}
int s,t,d,tg, ans;

int main(){
	int TC, T=1;
	scanf("%d", &TC);
	printf("CALL FORWARDING OUTPUT\n");
	while(TC--){
		printf("SYSTEM %d\n", T++);
		for(int i=0;i<10002;++i) mark[i] = 0;
		req = vector<vector<pair<int, pair<int,int> > > > (10002);
		while( cin >> s ){
			if( s==0 ) break;
			mark[s] = 1;
			scanf("%d %d %d", &t, &d, &tg);
			req[s].push_back(make_pair(tg, make_pair(t,d)));
		}
		while( cin >> t ){
			if( t == 9000) break;
			cin >> s;
			for(int i=0;i<10002;++i) vis[i] = 0;
			ans = rec(t,s);
			printf("AT %04d CALL TO %04d RINGS %04d\n", t, s, ans);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int> > mall1, mall2;
int N, M,u,v;
int main(){
	while(scanf("%d", &N), N!=0){
		mall1.clear();
		mall2.clear();
		for(int i=0;i<N;++i){
			scanf("%d %d", &u, &v);
			mall1.push_back(make_pair(u,v));
		}
		scanf("%d", &M);
		for(int i=0;i<M;++i){
			scanf("%d %d", &u, &v);
			mall2.push_back(make_pair(u,v));
		}
		int ans = 2000000000;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				int dx = mall1[i].first - mall2[j].first;
				int dy = mall1[i].second - mall2[j].second;
				if (dx < 0) dx = -dx;
				if (dy < 0) dy = -dy;
				ans = min(ans, dx+dy);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
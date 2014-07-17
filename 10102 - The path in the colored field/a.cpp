#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<string> vs;
vector<pair<int,int> > one;
vector<pair<int,int> > three;
vector<int> dist;
int main(){
	int M;
	while(scanf("%d",&M)!=EOF){
		vs = vector<string>(M+1);
		one.clear();
		three.clear();
		dist.clear();
		for(int m=0;m<M;++m){
			cin>>vs[m];
		}
		for(int i=0;i<M;++i){
			for(int j=0;j<M;++j){
				if(vs[i][j] == '1'){
					one.push_back(make_pair(i,j));
				} else if(vs[i][j] == '3'){
					three.push_back(make_pair(i,j));
				}
			}
		}
		for(int i=0;i<one.size(); ++i){
			int min = 999999999;
			for(int j=0;j<three.size(); ++j){
				int d = one[i].first - three[j].first;
				int e = one[i].second - three[j].second;
				if(d < 0) d = -d;
				if(e < 0) e = -e;
				if(d+e < min) min = d+e;
			}
			dist.push_back(min);
		}
		nth_element(dist.begin(), dist.end()-1, dist.end());
		printf("%d\n", dist[dist.size()-1]);
	}
	return 0;
}
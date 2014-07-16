#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<pair<int,int> > sl;
vector<int> pos;
int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=0;T<TC;++T){
		sl.clear();
		pos.clear();
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<b;++i){
			int m,n;
			scanf("%d%d",&m,&n);
			sl.push_back(make_pair(m,n));
		}
		sort(sl.begin(),sl.end());
		pos=vector<int>(a+3,1);
		int cur=0;
		bool completed=false;
		for(int i=0;i<c;++i){
			int d;
			scanf("%d",&d);
			if(completed)continue;
			pos[cur]+=d;
			if(pos[cur]>=100){
				pos[cur]=100;
				completed=true;
				continue;
			}
			for(int j=0;j<sl.size();++j){
				if(sl[j].first==pos[cur]){
					pos[cur]=sl[j].second;
					break;
				}
			}
			if(pos[cur]>=100){
				pos[cur]=100;
				completed=true;
				continue;
			}
			cur=(cur+1)%a;
		}
		for(int i=0;i<a;++i){
			printf("Position of player %d is %d.\n",i+1,pos[i]);
		}
	}
	return 0;
}
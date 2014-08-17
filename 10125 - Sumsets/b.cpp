#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<pair<int,pair<int,int> > > st1, st2;
vector<int> ans;
int s[1003];
int N;

int main(){
	while(scanf("%d", &N), N!=0){
		for(int i=0;i<N;++i){
			scanf("%d", &s[i]);
		}
		st1.clear(); st2.clear();
		ans.clear();
		for(int i=0;i<N;++i)
			for(int j=i+1;j<N;++j){
				st1.push_back(make_pair(s[i]+s[j], make_pair(s[i], s[j]) ));
				st2.push_back(make_pair(s[i]-s[j], make_pair(s[i], s[j]) ));
				st2.push_back(make_pair(s[j]-s[i], make_pair(s[j], s[i]) ));
			}
		sort(st1.begin(), st1.end());
		sort(st2.begin(), st2.end());
		int sz = st2.size();
		for(vector<pair<int,pair<int,int> > >::iterator it = st1.begin(); it != st1.end();++it){
			int val = it->first;
			int a = it->second.first, b = it->second.second;
			int hi=sz-1, lo=0;
			while(lo <= hi){
				int mid = (hi+lo)/2;
				int cur = st2[mid].first;
				if(cur < val){
					lo = mid+1;
				} else {
					hi = mid-1;
				}
			}
			if(st2[lo].first == val){
				while(lo < sz && st2[lo].first == val){
					int d = st2[lo].second.first, c = st2[lo].second.second;
					if( a==d || a == c || b == d || b == c){
						++lo;
						continue;
					}
					ans.push_back(d);
					++lo;
				}
			}
		}
		sort(ans.begin(),ans.end());
		if(!ans.empty()) printf("%d\n", ans[ans.size()-1]);
		else printf("no solution\n");

	}
	return 0;
}
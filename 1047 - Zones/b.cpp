#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

vector<int> towers;
map<int,int> common;
vector<int> sets;
vector<vector<int> > tset;
vector<int> ans;

void getset(int sz, int i, int n, int p){
	if(n == 0){
		sets.push_back(p);
		return;
	}
	if(i == sz-1){
		return;
	}
	for(int k = i+1; k < sz; ++k){
		getset(sz, k, n-1, (p | (1<<k)));
	}
}

//choose towers, then run from 1 to tower inclusion exclusion
//code common area sets as bitmask
int excinc(vector<int> tows){
	int sz = tows.size();
	int ret = 0;
	for(int i=0; i < sz; ++i){
		ret+=towers[tows[i]];
	}
	for(int i=2; i <= sz; ++i){
		sets.clear();
		getset(sz, -1, i, 0);
		for(int j=0;j<sets.size();++j){
			int tot = 0;
			int val = 0;
			int idx=0;
			//still wrong: need to find those intersecting outside tows
			while(sets[j] != 0){
				//cout << sets[j]%2;
				if(sets[j]%2 == 1){
					val+=(1<<tows[idx]);
				}
				++idx;
				sets[j] = (sets[j] >> 1);
			}
			//cout << endl;
			tot = common[val];
			ret -= (i-1)*tot;
		}
	}
	return ret;
}

int main(){
	int P,T;
	int tc = 1;
	while(scanf("%d %d",&P,&T), P!=0 && T!=0){
		printf("Case Number  %d\n", tc++);
		towers.clear(); common.clear(); tset.clear();
		for(int i=0;i<P;++i){
			int t;
			scanf("%d",&t);
			towers.push_back(t);
		}
		int C;
		scanf("%d",&C);
		for(int i=0;i<C;++i){
			int nc, m;
			scanf("%d",&nc);
			int mval=0;
			for(int j=0;j<nc;++j){
				int tow;
				scanf("%d",&tow);
				mval |= (1<<(tow-1));
			}
			scanf("%d",&m);
			common[mval] = m;
		}
		sets.clear();
		getset(P,-1,T,0);
		for(int i=0;i<sets.size();++i){
			int idx=0;
			vector<int> temp;
			while(sets[i] != 0){
				//printf("%d",sets[i]%2);
				if(sets[i] %2 == 1){
					temp.push_back(idx);
				}
				sets[i] = (sets[i] >> 1);
				++idx;
			}
			//printf("\n");
			tset.push_back(temp);
			/*
			for(int i=0;i<T;++i){
				cout << temp[i] << " ";
			}
			cout << endl;
			*/
		}
		ans.clear();
		ans.assign(T, 0);
		ans[0] = -1;
		for(int i=0;i<tset.size();++i){
			int val = excinc(tset[i]);
			bool lower = true;
			for(int j=0;j<T;++j){
				if(ans[j+1] > tset[i][j]){
					lower = false;
					break;
				}
			}
			printf("%d %d\n",ans[0], val);
			if(ans[0] < val || (ans[0] == val && !lower)){
				ans[0] = val;
				for(int j=0;j<T;++j){
					ans[j+1] = tset[i][j];
				}
			}
		}
		printf("Number of Customers: %d\nLocations recommended:",ans[0]);
		for(int i=0;i<T;++i){
			printf(" %d",ans[i+1]+1);
		}
	
		printf("\n");
	}

	return 0;
}
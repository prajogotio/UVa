#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <utility>
using namespace std;
typedef vector<pair<int, pair<int, int> > > vpp;
typedef pair<int, pair<int, int> > pp;
vector<pair<int, pair<int, int> > > vp;
vector<string> vs;

int main(){
	int TC;
	scanf("%d",&TC);
	bool flag = false;
	while(TC--){
		if(flag) printf("\n");
		vs.clear(); vp.clear();
		string str;
 		int D,Q;
 		scanf("%d %d", &D, &Q);
		for(int i=0;i<D;++i){
			int L, H;
			cin>>str;
			cin >> L >> H;
			vs.push_back(str);
			vp.push_back(make_pair(L,make_pair(H,i)));
		}
		scanf("%d",&Q);
		for(int q=0;q<Q;++q){
			int P,tot=0,idx=-1;
			scanf("%d",&P);
			for(int i = 0; i< D;++i){
				if(vp[i].first <= P && P <= vp[i].second.first){
					++tot;
					idx = vp[i].second.second;
					if(tot > 1) break;
				}
			}
			if(tot == 0 || tot >1)
				printf("UNDETERMINED\n");
			else
				cout << vs[idx] << endl;
		}
		flag = true;
	}
	return 0;
}

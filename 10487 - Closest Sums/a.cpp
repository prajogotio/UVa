#include <set>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
vector<ll> v;
set<ll> s;
int main(){
	int N,Q,T=1;
	while(scanf("%d", &N), N != 0){
		printf("Case %d:\n",T++);
		v.clear();
		s.clear();
		for(int i=0;i<N;++i){
			ll val;
			scanf("%lld",&val);
			for(int j=0;j<v.size(); ++j){
				ll sum = val+v[j];
				s.insert(sum);
			}
			v.push_back(val);
		}
		scanf("%d",&Q);
		for(int q=0;q<Q;++q){
			ll query;
			scanf("%lld",&query);
			printf("Closest sum to %lld is ", query);
			set<ll>::iterator it = s.lower_bound(query);
			if(it == s.end()){
				printf("%lld.\n", *(--it));
			}
			else if(*it == query)
				printf("%lld.\n", *it);
			else {
				//A is bigger than val
				ll A = *it, B;
				ll dA = A - query, dB;
				if (it != s.begin()) {
					B = *(--it);
					dB = query - B;
				} else {
					B = A;
					dB = dA;
				}
				if(dA < dB){
					printf("%lld.\n",A);
				} else {
					printf("%lld.\n",B);
				}
			}
		}
	}
	return 0;
}
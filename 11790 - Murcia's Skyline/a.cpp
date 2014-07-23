#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> height;
vector<ll> width;
vector<ll> lis;
vector<ll> lds;

int N;
int main(){
	int TC,k;
	scanf("%d",&TC);
	for(int T=1;T<=TC;++T){
		printf("Case %d. ", T);
		height.clear(); width.clear();
		lis.clear(); lds.clear();
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%d",&k);
			height.push_back(k);
		}
		for(int i=0;i<N;++i){
			scanf("%d",&k);
			width.push_back(k);
		}
		ll max_lds = 0;
		ll max_lis = 0;
		for(int i=0;i<N;++i){
			lis.push_back(width[i]);
			lds.push_back(width[i]);
			for(int j=i-1; j>=0; --j){
				if(height[i] > height[j]){
					lis[i] = max(lis[i], lis[j] + width[i]);
				}
				if(height[i] < height[j]){
					lds[i] = max(lds[i], lds[j] + width[i]);
				}
			}
			//printf("%lld %lld\n", lds[i], lis[i]);
			max_lds = max(lds[i], max_lds);
			max_lis = max(lis[i], max_lis);
		}
		if(max_lis >= max_lds){
			printf("Increasing (%lld). Decreasing (%lld).\n", max_lis, max_lds);
		} else {
			printf("Decreasing (%lld). Increasing (%lld).\n", max_lds, max_lis);
		}
	}
	return 0;
}
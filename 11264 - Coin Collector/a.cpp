#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll arr[1005];
int N;

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%lld",&arr[i]);
		}
		ll trail=0;
		int k=0;
		for(int i=0;i<N;++i){
			if(trail < arr[i]){
				trail += arr[i];
				++k;
			} else {
				trail -= arr[i-1];
				trail += arr[i];
			}
		}
		printf("%d\n", k);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[23][23][23];
int A,B,C;
int main(){
	int TC;
	scanf("%d",&TC);
	bool flag = false;
	while(TC--){
		if(flag) printf("\n");
		scanf("%d %d %d",&A, &B,&C);
		for(int i=0;i<A;++i){
			for(int j=0;j<B;++j){
				for(int k=0;k<C;++k){
					ll val;
					scanf("%lld", &val);
					if(i > 0) val += arr[i-1][j][k];
					if(j > 0) val += arr[i][j-1][k];
					if(k > 0) val += arr[i][j][k-1];
					if(i > 0 && j > 0) val -= arr[i-1][j-1][k];
					if(i > 0 && k > 0) val -= arr[i-1][j][k-1];
					if(j > 0  && k>0) val -= arr[i][j-1][k-1];
					if(i>0 && j>0 && k>0) val += arr[i-1][j-1][k-1];
					arr[i][j][k] = val;
					//printf("%d %d %d, %lld\n", i,j,k,val);
				}
			}
		}
		ll max_sum = -40000000000000;
		for(int a1 = 0; a1<A;++a1){
			for(int a2 =0; a2<B;++a2){
				for(int b1=a1; b1<A;++b1){
					for(int b2=a2;b2<B;++b2){
						ll trail = 0;
						for(int i=0;i<C;++i){
							ll temp = arr[b1][b2][i];
							if(a1>0) temp -= arr[a1-1][b2][i];
							if(a2>0) temp -= arr[b1][a2-1][i];
							if(a1>0 && a2>0) temp += arr[a1-1][a2-1][i];
							ll bef = 0;
							if(i>0) {
								bef = arr[b1][b2][i-1];
								if(a1>0) bef -= arr[a1-1][b2][i-1];
								if(a2>0) bef -= arr[b1][a2-1][i-1];
								if(a1>0 && a2>0) bef += arr[a1-1][a2-1][i-1];
							}
							ll curr = temp - bef;
							//printf("%d %d %d %d %d curr: %lld\n", a1,a2,b1,b2,i,curr);
							if(trail + curr < 0) trail = curr;
							else trail = max(curr, curr + trail);
							//printf("trail: %lld\n", trail);
							max_sum = max(trail, max_sum);
		} } } } }
		printf("%lld\n", max_sum);
		flag = true;
	}
	return 0;
}
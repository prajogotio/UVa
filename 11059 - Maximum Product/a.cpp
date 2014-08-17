#include <iostream>
#include <cstdio>
using namespace std;
typedef long long llong;

llong dp[20];
int cc[20];
int N; int ff;

int main(){
	int k,T=1;
	llong ans;

	while( cin >> N){
		ff = 0;
		for(int i=0;i<N;++i){
			scanf("%d", &k);
			cc[i] = ff;
			if(i > 0 && dp[i-1] != 0) dp[i] = dp[i-1] * (llong) k;
			else dp[i] = k;
			if(k == 0) ++ff;
		}
		ans = -1;
		for(int i=0;i<N;++i)
			for(int j=i;j<N;++j)
			{
				llong temp = dp[j];
				if(i>0 && dp[i-1] != 0) temp /= dp[i-1];
				if(cc[i] != cc[j]) temp = -1;
				if(ans < temp) ans = temp;
			}
		if(ans < 0) ans = 0;
		printf("Case #%d: The maximum product is %lld.\n\n", T++, ans);
	}
	return 0;
}
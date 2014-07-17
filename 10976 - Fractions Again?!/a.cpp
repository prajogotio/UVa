#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
vector<pair<int,int> > vp;
int main(){
	int k;
	while(scanf("%d",&k)!=EOF){
		int tot = 0;
		vp.clear();
		for(int i=k+1; i <= 2*k; ++i){
			int A = k*i;
			int B = i-k;
			if(A%B == 0){
				vp.push_back(make_pair(A/B,i));
				++tot;
			}
		}
		printf("%d\n",tot);
		for(int i=0;i<tot;++i){
			printf("1/%d = 1/%d + 1/%d\n",k, vp[i].first, vp[i].second);
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};
int even[] = {2,4,6,8,10,12,14,16};
int odd[] = {1,3,5,7,9,11,13,15};
vector<vector<int> > ans;

int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		ans.clear();
		sort(even,even+8);
		sort(odd,odd+8);
		int lim = N/2;
		do{
			sort(even,even+8);
			do{
				bool isfound = true;
				for(int i=0;i<lim;++i){
					int aft = (i+1 < lim) ? i+1 : 0;
					int p1 = odd[i] + even[i];
					int p2 = even[i] + odd[aft];
					bool p1prime = false;
					bool p2prime = false;
					for(int j=0;j<11;++j){
						if(primes[j] == p1) p1prime = true;
						if(primes[j] == p2) p2prime = true;
					}
					if(!p1prime || !p2prime){
						isfound = false;
						break;
					}
					/*
					for(int i=0;i<lim;++i){
						if(i!=0) printf(" ");
						printf("%d %d", odd[i], even[i]);
					}
					printf("\n");
					*/
				}
				if(isfound){
					vector<int> res(N);
					for(int i=0;i<lim;++i){
						res[2*i] = odd[i];
						res[2*i+1] = even[i];
					}
					ans.push_back(res);
				}
			} while(next_permutation(even, even+lim));
		} while(next_permutation(odd+1, odd+lim));
		sort(ans.begin(), ans.end());
		for(int i=0;i<ans.size();++i){
			for(int j=0;j<N;++j){
				if(j!=0) printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
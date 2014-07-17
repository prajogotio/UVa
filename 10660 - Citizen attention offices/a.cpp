#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int ans[6];
vector<int> pop;

int dist(int a, int b){
	int m = a/5;
	int n = a - 5*m;
	int i = b/5;
	int j = b - 5*i;
	int d = m - i;
	int e = n - j;
	if (d < 0) d = -d;
	if (e < 0) e = -e;
	return (d+e)*pop[a];
}

bool comp(int val,int a, int b, int c, int d, int e){
	if(ans[0] == val){
		if(ans[1] == a){
			if(ans[2] == b){
				if(ans[3] == c){
					if(ans[4] == d){
						return ans[5] > e;
					}
					return ans[4] > d;
				}
				return ans[3] > c;
			}
			return ans[2] > b;
		}
		return ans[1] > a;
	}
	return ans[0] > val;
}

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		pop.clear();
		pop.assign(25,0);
		ans[0] = 2000000000;
		//cout << ans[0] << endl;
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			int m,n,o;
			scanf("%d %d %d",&m,&n,&o);
			pop[5*m+n] = o;
		}
		for(int a=0;a<25;++a){
			for(int b=a+1;b<25;++b){
				for(int c=b+1;c<25;++c){
					for(int d=c+1;d<25;++d){
						for(int e=d+1;e<25;++e){
							int val = 0;
							for(int f=0;f<25;++f){
								if(f == a || f == b || f == c || f == d || f == e)continue;
								val += min(dist(f,a), min(dist(f,b), min(dist(f,c), min(dist(f,d), dist(f,e)))));
							}
							//printf("%d\n",val);
							if (comp(val,a,b,c,d,e)){
								ans[0] = val;
								ans[1] = a;
								ans[2] = b;
								ans[3] = c;
								ans[4] = d;
								ans[5] = e;
							}
		}	}	}	}	}
		printf("%d %d %d %d %d\n", ans[1], ans[2], ans[3], ans[4] ,ans[5]);
	}
	return 0;
}
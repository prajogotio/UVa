#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long llong;

vector<vector<int> > ans;
int N = 0;

int main(){
	int hi, lo, mid;
	llong cur, temp;
	for(llong b=2;b<=200;++b){
		for(llong c=b;c<=200;++c){
			for(llong d=c;d<=200;++d){
				temp = b*b*b + c*c*c + d*d*d;
				hi=200; lo=2;
				while(lo <= hi){
					//printf("%d %d %d %d %d\n", b, c, d, hi, lo);
					mid = (lo+hi)/2;
					cur = mid;
					cur = cur*cur*cur;
					if(cur < temp){
						lo = mid+1;
					} else {
						hi = mid-1;
					}
				}
				cur = lo;
				//printf("%d %d %d %d\n", cur, b,c,d);
				cur = cur*cur*cur;
				if(cur == temp && lo <= 200){						
					ans.push_back(vector<int>());
					ans[N].push_back(lo);
					ans[N].push_back(b);
					ans[N].push_back(c);
					ans[N].push_back(d);
					sort(ans[N].begin()+1, ans[N].end());
					++N;
					//printf("Cube = %d, Triple = (%d,%d,%d)\n", mid, b, c, d);
				}

			}
		}
	}
	sort(ans.begin(), ans.end());

	for(int i=0;i<N;++i){
		printf("Cube = %d, Triple = (%d,%d,%d)\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
	}
	return 0;
}

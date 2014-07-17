#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> front;
vector<int> back;
vector<double> dr;

int main(){
	int F,R;
	while(scanf("%d",&F), F!=0){
		scanf("%d",&R);
		front.clear();
		back.clear();
		dr.clear();
		for(int i=0;i<F;++i){
			int f;
			scanf("%d",&f);
			front.push_back(f);
		}
		for(int i=0;i<R;++i){
			int r;
			scanf("%d",&r);
			back.push_back(r);
		}
		for(int i=0;i<F;++i){
			for(int j=0;j<R;++j){
				double d = ((double) back[j] )/((double) front[i] );
				dr.push_back(d);
			}
		}
		sort(dr.begin(), dr.end());
		double ans = 0;
		for(int i=0;i<dr.size()-1; ++i){
				double temp = dr[i+1]/dr[i];
				if(ans < temp) 
					ans = temp;
		}
		printf("%.2lf\n", ans);
		
	}
	return 0;
}
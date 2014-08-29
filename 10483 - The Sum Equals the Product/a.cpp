#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<pair<int,int>,pair<int,int> > > val;

int main(){
	int upp, low;
	int hi,lo,mid,sz;
	int a,b,c,d;	
	int lim1, lim2;
	for(int i=1;i<=25600;++i){
		lim1 = 256000000/i;
		for(int j=i;j<=lim1 && j<=25600-i;++j){
			lim2 = lim1/j;
			for(int k=j;k<=lim2 && k <=25600-i-j;++k){
				if(i*j*k == (i+j+k)*10000){
					//printf("{%d,%d,%d,%d},",i+j+k,i,j,k);
					val.push_back(make_pair(make_pair(i+j+k, i),make_pair(j,k)));
				}
			}
		}
	}
	sort(val.begin(), val.end());

	sz = val.size();

	for(int i=0;i<sz;++i){
		printf("{%d,%d,%d,%d},",val[i].first.first, val[i].first.second, val[i].second.first, val[i].second.second);
	}
	/*
	while(scanf(" %d.%d %d.%d", &a,&b,&c,&d) != EOF){
		low = a*100+b;
		upp = c*100+d;
		lo = 0; hi = sz-1;
		while(lo <= hi){
			mid = (lo+hi)/2;
			if(val[mid].first.first < low){
				lo = mid+1;
			} else {
				hi = mid -1;
			}
		}
		lim1 = lo;
		lo = 0; hi = sz-1;
		while(lo <= hi){
			mid = (lo+hi)/2;
			if(val[mid].first.first <= upp){
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}
		lim2 = lo;
		for(int i=lim1; i<lim2;++i){
			printf("%d.%d = %d.%d + %d.%d + %d.%d = %d.%d * %d.%d * %d.%d\n", val[i].first.first/100, val[i].first.first%100, val[i].first.second/100, val[i].first.second%100, val[i].second.first/100, val[i].second.first%100, val[i].second.second/100, val[i].second.second%100,val[i].first.second/100, val[i].first.second%100, val[i].second.first/100, val[i].second.first%100, val[i].second.second/100, val[i].second.second%100); 
		}
	}
	*/
	return 0;
}
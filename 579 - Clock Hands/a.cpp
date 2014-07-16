#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int m,h;
	while(scanf("%d:%d",&h,&m)!=EOF, h||m){
		double dm = double(m)*6;
		double dh = double(h)*30 + double(m)*0.5L;
		if(dh<dm)swap(dh,dm);
		double diff = dh-dm;
		if(diff>180)diff=360L-diff;
		printf("%.3lf\n",diff);
	}
	return 0;
}
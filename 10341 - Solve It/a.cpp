#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
double p,q,r,s,t,u;

double f(double x){
	 return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){
	while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u) != EOF){
		double lo=0,hi=1;
		if(f(lo)*f(hi) > 0) {
			//assuming only one x satisfies e eqn
			printf("No solution\n");
			continue;
		}
		for(int i=0;i<50;++i){
			double mid = (lo+hi)/2;
			if(f(mid)*f(lo) > 0){
				lo = mid;
			} else {
				hi = mid;
			}
		}
		printf("%0.4lf\n",(lo+hi)/2);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

int num[105][610];
int dp[2][105][610];
int sz[105];
int dsz[2][105];
int sign[105];
int N;

int main(){
	int dig;
	N=0;
	while(scanf("%d",&dig) != EOF){
		if(dig == -999999){
			for(int i=0;i<sz[0];++i){
				dp[0][0][i] = num[0][i];
				dp[1][0][i] = num[0][i];
				dsz
			}
			for(int i=1;i<N;++i){
				int p[610], sz = 0;
				//find the most positive
				for(int j=i-1;j>=0;--j){
					int temp[610] = {0};
					int tsz = size[i];
					int sign = sign[i]*sign[j];
					for(int k=0;k<size[

				//find the most negative


			N=0;
		} else {
			sz[N]=0;
			if(dig < 0) sign[N] = -1;
			else if(dig>0) sign[N] = 1;
			else sign[N] = 0;

			if(dig < 0) dig = -dig;

			while(dig != 0){
				num[N][sz[N]] = dig%10;
				dig /= 10;
				++sz[N];
			}
			++N;
		}
	}
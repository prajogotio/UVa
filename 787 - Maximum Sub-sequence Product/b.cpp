#include <iostream>
#include <cstdio>
using namespace std;

struct bigint{
	int dig[610];
	int sz;
	int sign;

	void set(int num){
		if(num == 0){
			sz = 1;
			sign = 0;
			dig[0] = 0;
			return;
		}
		sz = 0;
		if(num < 0) sign = -1;
		if(num > 0) sign = 1;
		if(num < 0) num = -num;
		while(num){
			dig[sz] = num%10;
			num /= 10;
			++sz;
		}
	}

	void mult(bigint left, bigint right){
		sign = left.sign * right.sign;
		if(sign == 0){
			sz = 1;
			dig[0] = 0;
			return;
		}
		for(int i=0;i<610;++i) dig[i] = 0;
		sz = right.sz;
		for(int i=0;i<sz;++i){
			dig[i] = 0;
		}
		for(int i=0;i<left.sz;++i){
			for(int j=0;j<right.sz;++j){
				dig[j+i] += left.dig[i] * right.dig[j];
			}
		}
		int i=0;
		
		while(i < sz){
			if(dig[i] > 9){
				dig[i+1] += dig[i]/10;
				dig[i] %= 10;
				if(i+1 == sz) ++sz;
			}
			++i;
		}
		
	}

	void print(){
		if(sign == -1) printf("-");
		for(int i=0;i<sz;++i){
			//printf(" ");
			printf("%d", dig[sz-i-1]);
		}
	}
	//absolute value
	bool operator< (bigint right) const{
		if(sz == right.sz){
			for(int i=0;i<sz;++i){
				if(dig[sz-i-1] != right.dig[sz-i-1])
					return dig[sz-i-1] < right.dig[sz-i-1];
			}
		}
		return sz < right.sz;
	}

	void operator= (bigint right) {
		sz = right.sz;
		sign = right.sign;
		for(int i=0;i<sz;++i){
			dig[i] = right.dig[i];
		}
	}
};

bigint dp[2][105];
bigint num[105];
int idx;
int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		if(N == -999999){
			if(idx == 1){
				num[0].print();
				printf("\n");
				idx = 0;
				continue;
			}
			dp[0][0] = num[0];
			dp[1][0] = num[0];
			if(num[0].sign == 1){
				dp[1][0].set(0);
			} else if(num[0].sign == -1){
				dp[0][0].set(0);
			}
			for(int i=1;i<idx;++i){
				//max positive
				bigint maxi;
				if(num[i].sign == 0){
					dp[0][i].set(0);
					dp[1][i].set(0);
					continue;
				}
				if(num[i].sign == 1){
					maxi = num[i];
					for(int j=i-1; j>=0;--j){
						bigint temp;
						temp.mult(num[i], dp[0][j]);
						if(maxi < temp) maxi = temp;
					}
					dp[0][i] = maxi;
				} else if (num[i].sign == -1){
					maxi.set(0);
					for(int j=i-1; j>=0;--j){
						bigint temp;
						temp.mult(num[i], dp[1][j]);
						if(maxi < temp) maxi = temp;
					}
					dp[0][i] = maxi;
				}
				//max negative
				if(num[i].sign == -1){
					maxi = num[i];
					for(int j=i-1; j>=0;--j){
						bigint temp;
						temp.mult(num[i], dp[0][j]);
						if(maxi < temp) maxi = temp;
					}
					dp[1][i] = maxi;
				} else if (num[i].sign == 1){
					maxi.set(0);
					for(int j=i-1; j>=0;--j){
						bigint temp;
						temp.mult(num[i], dp[1][j]);
						if(maxi < temp) maxi = temp;
					}
					dp[1][i] = maxi;
				}
			}
			bigint maxi;
			maxi.set(0);
			for(int i=0;i<idx;++i){
				if(maxi < dp[0][i]) maxi = dp[0][i];
			}
			maxi.print();
			printf("\n");
			idx = 0;
		} else {
			num[idx].set(N);
			++idx;
		}
	}
	
	return 0;
}
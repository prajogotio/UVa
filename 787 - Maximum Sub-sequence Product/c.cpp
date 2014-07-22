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
		//printf("multiply "); left.print(); printf(" x "); right.print(); printf("\n");
		sign = left.sign * right.sign;
		if(sign == 0){
			sz = 1;
			dig[0] = 0;
			return;
		}
		for(int i=0;i<610;++i) dig[i] = 0;
		sz = right.sz+left.sz-1;
		for(int i=0;i<sz;++i){
			dig[i] = 0;
		}

		for(int i=0;i<left.sz;++i){
			for(int j=0;j<right.sz;++j){
				dig[j+i] += left.dig[i] * right.dig[j];
				//printf("%d %d %d\n", left.dig[i], right.dig[j], dig[i+j]);
			}
		}
		int i=0;
		//printf("result: "); this->print(); printf("\n");
		
		while(i < sz){
			if(dig[i] > 9){
				dig[i+1] += dig[i]/10;
				dig[i] %= 10;
				if(i+1 == sz) ++sz;
			}
			++i;
		}
		//printf("result: "); this->print(); printf("\n");
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
int N;

int main(){
	idx = 0;
	while(scanf("%d",&N)!=EOF){
		if(N == -999999){
			dp[0][0] = num[0];
			dp[1][0] = num[0];
			if(idx == 1){
				num[0].print();
				printf("\n");
				idx = 0;
				continue;
			}
			if(num[0].sign == 1){
				dp[1][0].set(0);
			} else if(num[0].sign == -1){
				dp[0][0].set(0);
			}
			//printf("0 "); num[0].print(); printf(" "); dp[0][0].print(); printf(" "); dp[1][0].print(); printf("\n");
			for(int i=1;i<idx;++i){
				bigint temp; //pos max
				bigint temp1; //neg max
				if(num[i].sign == -1){
					temp.mult(num[i], dp[1][i-1]);
					temp1.mult(num[i], dp[0][i-1]);
					if(temp.sign != 0 && temp < num[i]) temp = num[i];
					if(temp1 < num[i]) temp1 = num[i];
				} else if(num[i].sign == 0){
					temp.set(0);
					temp1.set(0);
				} else if(num[i].sign == 1){
					temp.mult(num[i], dp[0][i-1]);
					temp1.mult(num[i], dp[1][i-1]);
					if(temp < num[i]) temp = num[i];
					if(temp1.sign != 0 && temp1 < num[i]) temp1 = num[i];
				}
				dp[0][i] = temp;
				dp[1][i] = temp1;
				/*
				printf("%d ", i);
				num[i].print();
				printf(" ");
				dp[0][i].print();
				printf(" ");
				dp[1][i].print();
				printf("\n");
				*/
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
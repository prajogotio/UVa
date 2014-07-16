#include <cstdio>
using namespace std;

char cards[52][5];
char val[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=0;T<TC;++T){
		for(int i=0;i<52;++i){
			scanf("%2s",cards[i]);
		}
		int j=26,Y=0;
		for(int i=0;i<3;++i){
			int X;
			for(int k=0;k<13;++k){
				if(cards[j][0]==val[k])X=k+2;
			}
			if(X>10)X=10;
			Y+=X;
			j-=(10-X)+1;
		}
		if(Y-1<=j)printf("Case %d: %s\n",T+1,cards[Y]);
		else{
			Y-=j+1;
			printf("Case %d: %s\n",T+1,cards[26+Y]);
		}
	}
	return 0;
}
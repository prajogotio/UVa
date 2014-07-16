#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
string cards[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};

int main(){
	int T;
	scanf("%d",&T);
	bool flag=false;
	while(T){
		if(flag)printf("\n");
		--T;
		int n,shf[105][52];
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			for(int j=0;j<52;++j){
				scanf("%d",&shf[i][j]);
			}
		}
		int C[52];
		for(int i=0;i<52;++i){C[i]=i;}

		getchar();
		while(1){
			char inp[5]="";
			gets(inp);
			if(strlen(inp)==0)break;
			int w,B[52];
			sscanf(inp,"%d",&w);
			for(int i=0;i<52;++i){
				B[i]=C[shf[w-1][i]-1];
			}
			for(int i=0;i<52;++i){
				C[i]=B[i];
			}
		}
		for(int i=0;i<52;++i){
			printf("%s of %s\n",cards[C[i]%13].c_str(),suits[C[i]/13].c_str());
		}
		flag=true;
	}
	return 0;
}

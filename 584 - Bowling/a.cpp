#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		if(str=="Game Over")break;
		int roll[30]={0};
		int mark[30]={0};
		int k=0,j=0;
		bool inround=false;
		int len=str.size();
		while(k<len){
			if(str[k]=='X'){
				mark[j]=3;
				roll[j]=10;
				inround=false;
			}else if(str[k]=='/'){
				mark[j]=2;
				roll[j]=10-roll[j-1];
				inround=false;
			}else{
				if(inround){
					inround=false;
					mark[j]=1;
					roll[j]=str[k]-'0';
				}else{
					inround=true;
					mark[j]=0;
					roll[j]=str[k]-'0';
				}
			}
			k+=2;++j;
		}
		int i=0,prev=0,score=0;
		k=0;
	//	for(int s=0;s<30;++s)printf(" %2d",roll[s]);printf("\n");
	//	for(int s=0;s<30;++s)printf(" %2d",mark[s]);printf("\n");

		while(i<10){
			
			if(mark[k]==0){
				prev+=roll[k];
			}else if(mark[k]==1){
				score+=prev+roll[k];
				prev=0;
				++i;
			}else if(mark[k]==2){
				score+=10+roll[k+1];
				prev=0;
				++i;
			}else if(mark[k]==3){
				score+=10+roll[k+1]+roll[k+2];
				prev=0;
				++i;
			}
		//	printf(" %d",score);
			++k;
		}
		//printf("\n");
		printf("%d\n",score);
	}
	return 0;
}
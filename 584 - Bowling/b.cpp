#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	string inp;
	while(getline(cin,inp)){
		if(inp=="Game Over")break;
		cout<<inp<<endl;
		int roll[20]={0};
		int mark[20]={0};
		int len=inp.size();
		int idx=0;
		int jdx=0;
		int prev=0;
		bool in_round=false;
		while(idx*2<len){
		//	cout<<inp[2*idx]<<endl;
			if(inp[2*idx]=='X'){
				mark[jdx]=2;
				roll[jdx]=10;
				if(jdx==9){
					if(inp[2*(idx+1)]=='X'){
						roll[jdx+1]=10;
						if(inp[2*(idx+2)]=='X'){
							roll[jdx+2]=10;
						}else{
							roll[jdx+2]=inp[2*(idx+2)]-'0';
						}
					} else{
						if(inp[2*(idx+2)]=='/'){
							roll[jdx+1]=0;
							roll[jdx+2]=10;
						}else{
							roll[jdx+1]=inp[2*(idx+1)]-'0';
							roll[jdx+2]=inp[2*(idx+2)]-'0';
						}
					}
					break;
				}
				++jdx;
			} else if(inp[2*idx]=='/'){
				in_round=false;
				mark[jdx]=1;
				roll[jdx]=10;

				if(jdx==9){
					if(inp[2*(idx+1)=='X']){
						roll[jdx+1]=10;
					}else{
						roll[jdx+1]=inp[2*(idx+1)]-'0';
					}
					break;
				}
				++jdx;

			} else {
				if(in_round==true){
					in_round=false;
					mark[jdx]=0;
					roll[jdx]=inp[2*idx]-'0'+prev;
					prev=0;
					++jdx;
				} else {
					in_round=true;
					prev=inp[2*idx]-'0';
				}
			}
		//	cout<<roll[idx]<<endl;
			++idx;
		}
		int score=0;
		for(int i=0;i<10;++i){
			cout<<roll[i]<<" "<<mark[i]<<endl;
			score+=roll[i];
			if(mark[i]==1){
				score+=roll[i+1];
			} else if(mark[i]==2 && i+2<jdx){
				score+=roll[i+2];
			}
		}
		printf("%d\n",score);
	}
	return 0;
}
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		vector<string> card;
		for(int i=0;i<13;++i){
			card.push_back(str.substr(i*3,2));
		}
		int T=0;
		int tot[4]={0};
		for(int i=0;i<13;++i){
			if(card[i][0]=='A')T+=4;
			if(card[i][0]=='K')T+=3;
			if(card[i][0]=='Q')T+=2;
			if(card[i][0]=='J')T+=1;
			if(card[i][1]=='S')++tot[0];
			if(card[i][1]=='H')++tot[1];
			if(card[i][1]=='D')++tot[2];
			if(card[i][1]=='C')++tot[3];
		}
		int subs[3] ={0};
		char c[3]={'K','Q','J'};
		char suit[4]={'S','H','D','C'};
		int stopped[4]={0};
		for(int j=0;j<3;++j){
			for(int i=0;i<13;++i){
				if(card[i][0]==c[j]){
					for(int k=0;k<4;++k){
						if(card[i][1]==suit[k]){
							if(tot[k]<=j+1){
								++subs[j];
							}
							if(tot[k]>=j+2 && j!=2){
								stopped[k]=1;
							}
						}
					}
				}
				if(card[i][0]=='A'){
					for(int k=0;k<4;++k){
						if(card[i][1]==suit[k]){
							stopped[k]=1;
						}
					}
				}
			}
		}
		//printf("%d %d %d\n",subs[0],subs[1],subs[2]);
		for(int j=0;j<3;++j){
			T-=subs[j];
			//if(subs[j]==1)--T;
		}
		bool not_stopped=false;
		for(int k=0;k<4;++k){
			if(stopped[k]==0)not_stopped=true;
		}
		if(T>=16 && !not_stopped){
			printf("BID NO-TRUMP\n");
			continue;
		}
		int m=0,idx=-1;
		for(int i=0;i<4;++i){
			if(m<tot[i]){
				m=tot[i];
				idx=i;
			}
			if(tot[i]==0)T+=2;
			if(tot[i]==1)T+=2;
			if(tot[i]==2)T+=1;
		}
		if(T<14){
			printf("PASS\n");
			continue;
		}
		printf("BID %c\n",suit[idx]);

	}
	return 0;
}
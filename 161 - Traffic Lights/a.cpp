#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int fin=0;
	while(1){
		int N=0;
		int a[105];
		while(cin>>a[N]){
			if(a[N]==0)break;
			++N;
		}
		if(N==0){
			++fin;
			if(fin==4)break;
			continue;
		}
		fin=0;
		int s=999;
		for(int i=0;i<N;++i){
			s=min(s,a[i]);
		}
		int p=2*s;
		s=2*s;
		bool all_green=false;
		bool exc=false;
		while(all_green==false){
			if(s>5*60*60){
				printf("Signals fail to synchronise in 5 hours\n");
				break;
			}
			for(int i=0;i<s-5;++i){
				if(s+i>5*60*60){
					break;
				}
				int temp=s+i;
				bool agreen=true;
				for(int j=0;j<N;++j){
					int per=temp%(2*a[j]);
					if(per>=a[j]-5){
						agreen=false;
						break;
					}
				}
				if(agreen){
					all_green=true;
					s=temp;
					break;
				}
			}
			if(all_green){
				printf("%02d:%02d:%02d\n",s/3600,(s/60)%60,s%60);
			}
			s+=p;
		}
	}
	return 0;
}

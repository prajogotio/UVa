#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int fin=0;
	while(1){
		int a[105];
		int N=0;
		while(cin>>a[N]){
			if(a[N]==0)break;
			++N;
		}
		if(N==0){
			++fin;
			if(fin==4)break;
		}
		fin=0;
		int t[5*60*60+4]={0};
		//hmm
	}
	return 0;
}
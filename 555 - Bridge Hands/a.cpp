#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string lhs, string rhs){
	int s1,s2;
	char s[4] = {'C','D','S','H'};
	for(int i=0;i<4;++i){
		if(lhs[0]==s[i])s1=i;
		if(rhs[0]==s[i])s2=i;
	}
	if(s1!=s2)return s1<s2;
	char f[] ="23456789TJQKA";
	int k1=-1,k2=-1;
	for(int i=0;i<13;++i){
		if(lhs[1]==f[i])k1=i+10;
		if(rhs[1]==f[i])k2=i+10;
	}
	return k1<k2;
}

int main(){
	int p[4] = {'S','W','N','E'};
	while(1){	
		vector<string> deck[4];
		char P;
		int pid;
		P=getchar();
		if(P=='#')break;
		if(P=='S')pid=0;
		if(P=='W')pid=1;
		if(P=='N')pid=2;
		if(P=='E')pid=3;
		getchar();
		string inp;
		int id=(pid+1)%4;
		for(int d=0;d<2;++d){
			getline(cin,inp);
			for(int i=0;i<26;++i){
				deck[id].push_back(inp.substr(i*2,2));
				id = (id+1)%4;
			}
		}
		for(int i=0;i<4;++i){
			sort(deck[i].begin(),deck[i].end(),cmp);
		}
		for(int i=0;i<4;++i){
			printf("%c:",p[i]);
			for(int j=0;j<13;++j){
				printf(" %s",deck[i][j].c_str());
			}
			printf("\n");
		}
	}
	return 0;
}

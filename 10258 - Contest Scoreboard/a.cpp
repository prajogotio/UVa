#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

int v[102];
int s[102][3];
int p[102][11];

bool comp(pair<int, pair<int,int> > L, pair<int, pair<int,int> > R){
	if(L.first == R.first){
		return L.second < R.second;
	}
	return L.first>R.first;
}

int main(){
	int tc;
	char buf[10000];
	scanf("%d", &tc);
	getchar();
	gets(buf);
	bool flag=false;
	while(tc--){
		if(flag)printf("\n");
		for(int i=0;i<102;++i){
			v[i]=0;
			for(int j=0;j<11;++j){
				p[i][j]=0;
			}
			for(int j=0;j<3;++j){
				s[i][j]=0;
			}
		}

		char ins[1000];
		while(gets(ins) && strlen(ins) ){
			//int k=1;
			//while(ins[k]=getchar(), ins[k] !='\n' && ins[k] != EOF)++k;
			//ins[k]='\0';
			//cout<<ins<<endl;
			int team,prob,t;
			char L;
			sscanf(ins, "%d %d %d %c",&team,&prob,&t,&L);
			//printf("%d %d %d %c\n",team,prob,t,L);
			v[team]=1;
			if(L=='I'){
				if(p[team][prob]==-1)continue;
				++p[team][prob];
			}
			if(L=='C'){
				if(p[team][prob]==-1)continue;
				++s[team][0];
				s[team][1]+=t+20*p[team][prob];
				p[team][prob]=-1;
			}	
		}
		
		vector<pair<int, pair<int,int> > > ppl;
		for(int i=1;i<=100;++i){
			if(v[i]==1){
				ppl.push_back(make_pair(s[i][0], make_pair(s[i][1], i)));
			}
		}
		sort(ppl.begin(),ppl.end(), comp);
		for(vector<pair<int, pair<int,int> > >::iterator it=ppl.begin();it!=ppl.end();++it){
			printf("%d %d %d\n", it->second.second,	it->first, 	it->second.first);
		}
		//printf("iter");
		flag=true;
		
	}
	return 0;
}
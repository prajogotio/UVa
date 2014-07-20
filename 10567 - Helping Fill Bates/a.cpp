#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<vector<int> > p( (int) 'z' + 3);
vector<int>::iterator it;
int main(){
	string str;
	cin>>str;
	int sz = str.size();
	for(int i=0;i<sz;++i){
		p[str[i]-'A'].push_back(i);
	}
	int TC;
	scanf("%d",&TC);
	while(TC--){
		string comp;
		cin>>comp;
		int prev = 0;
		int init = 0;
		int len = comp.size();
		bool finished = false;
		for(int i=0;i<len;++i){
			int key = comp[i]-'A';
			it = lower_bound(p[key].begin(), p[key].end(), prev);
			if( it == p[key].end()){
				printf("Not matched\n");
				finished = true;
				break;
			}
			prev = *it;
			if(i == 0) init = prev;
			++prev;
		}
		if(finished) continue;
		printf("Matched %d %d\n", init, prev-1);
	}
	return 0;
}
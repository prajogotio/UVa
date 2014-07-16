#include <cstdio>
#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<string,string> lhs, pair<string,string> rhs){
	return lhs.second < rhs.second;
}

int main(){
	vector<pair<string,string> > dict;
	string str;
	while(cin>>str){
		if(str=="#")break;
		char st[50];
		int len=str.size();
		for(int i=0;i<len;++i){
			st[i]=tolower(str[i]);
		}
		st[len]='\0';
		sort(st,st+len);
		dict.push_back(make_pair(st,str));
	}
	sort(dict.begin(),dict.end());
	int i=0;
	//there will always be one ananagram
	while(i<dict.size()-1){
		if(dict[i].first==dict[i+1].first){
			while(dict[i].first==dict[i+1].first)
				dict.erase(dict.begin()+i+1);
			dict.erase(dict.begin()+i);
		} else {
			++i;
		}
	}
	sort(dict.begin(),dict.end(),cmp);
	for(int i=0;i<dict.size();++i){
		cout<<dict[i].second<<endl;
	}
	return 0;
}
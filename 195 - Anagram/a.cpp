#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

bool cmp1(string lhs, string rhs){
	int len = lhs.size();
	if(tolower(lhs[0])==tolower(rhs[0]))
		if(lhs[0]!=rhs[0]) return lhs[0]<rhs[0];
		else if(len==1) return false;
	return tolower(lhs[0])<tolower(rhs[0]);
}

bool cmp(string lhs, string rhs){
	int len=lhs.size();
	for(int i=0;i<len;++i){
		if(tolower(lhs[i])!=tolower(rhs[i]))
			return tolower(lhs[i])<tolower(rhs[i]);
		else{
			if(lhs[i]!=rhs[i])
				return lhs[i]<rhs[i];
		}
	}
	return false;
}

int main(){
	int N;
	cin>>N;
	string str;
	vector<string> ans;
	for(int t=0;t<N;++t){
		ans.clear();
		cin>>str;
		char c[303];
		int len=str.size();
		/*
		for(int j=0;j<len;++j){
			c[j]=str[j];
		}
		c[len]='\0';
		sort(c,c+len);*/
		sort(str.begin(),str.end());
		//ans.push_back(c);
		ans.push_back(str);
		/*
		while(next_permutation(c,c+len)){
			ans.push_back(c);
		}*/
		while(next_permutation(str.begin(),str.end())){
			ans.push_back(str);
		}
		sort(ans.begin(),ans.end(), cmp);
		int i=0;
		/*while(i<ans.size()-1){
			if(ans[i]==ans[i+1]){
				ans.erase(ans.begin()+i+1);
			}	else {
				++i;
			}
		}*/
		for(int i=0;i<ans.size();++i){
			printf("%s\n",ans[i].c_str());
		}
	}
	return 0;
}
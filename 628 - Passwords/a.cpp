#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
using namespace std;


vector<string> dict;
vector<string> rules;
vector<vector<pair<char,int> > > ans;
vector<pair<char,int> > stack;
int W, R;

void gen(int r, int i, int sz){
	if(i == sz){
		//ans.push_back(stack);
		for(int j=0;j<sz;++j){
			if(stack[j].first == '#'){
				cout << dict[ stack[j].second ];
			} else {
				cout << stack[j].second;
			}
		}
		printf("\n");
		return;
	}
	if(rules[r][i] == '#'){
		for(int j=0;j<W;++j){
			stack.push_back(make_pair('#', j));
			gen(r, i+1, sz);
			stack.pop_back();
		}
	} else if( rules[r][i] == '0'){
		for(int j=0;j<10;++j){
			stack.push_back(make_pair('0', j));
			gen(r, i+1, sz);
			stack.pop_back();
		}
	}
}

int main(){
	string str;
	int rsz;
	while(cin >> W){
		printf("--\n");
		dict.clear();
		rules.clear();
		for(int i=0;i<W;++i){
			cin >> str;
			dict.push_back(str);
		}
		cin >> R;
		for(int i=0;i<R;++i){
			cin >> str;
			rules.push_back(str);
		}
		for(int i=0;i<R;++i){
			//ans.clear();
			rsz = rules[i].size();
			gen(i, 0, rsz);
			/*
			for(int j=0, sz = ans.size(); j < sz; ++j){
				for(int k=0; k < rsz; ++k){
					if(ans[j][k].first == '#'){
						cout << dict[ ans[j][k].second ];
					} else if (ans[j][k].first == '0'){
						cout << ans[j][k].second;
					}
				}
				printf("\n");
			}
			*/
		}
	}
	return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
	bool completed = false;
	while(1){
		char s[5];
		vector<string> stack[2]; //non-dealer 0 dealer 1
		vector<string> up; //face up
		int nd=0;
		for(int i=0;i<4;++i)
			for(int j=0;j<13;++j){
				scanf("%s",s);
				if(s[0]=='#'){
					return 0;
				}
				stack[nd].push_back(s);
				nd=(nd+1)%2;
			}
		/*for(int i=0;i<stack[0].size();++i)
			printf("%s\n",stack[0][i].c_str());*/
		nd=0;
		while(!stack[0].empty() || !stack[1].empty()){
			if(stack[nd].empty())
				break;
			if(!up.empty()){
				char c = up.back()[1];
				bool face=false;
				bool lose=false;
				if(c=='A'||c=='J'||c=='Q'||c=='K'){
					int k;
					if(c=='A')k=4;
					if(c=='J')k=1;
					if(c=='Q')k=2;
					if(c=='K')k=3;
					for(int i=0;i<k;++i){
						if(stack[nd].empty()){
							lose=true;
							break;
						}
						up.push_back(stack[nd].back());
						stack[nd].pop_back();
						char x= up.back()[1];
						if(x=='A'||x=='J'||x=='Q'||x=='K'){
							face=true;
							break;
						}
					}
					if(lose){
						break;
					}
					nd=(nd+1)%2;
					if(!face){
						reverse(up.begin(),up.end());
						stack[nd].insert(stack[nd].begin(),up.begin(),up.end());
						up.clear();
					}
					continue;
				}
			}
			up.push_back(stack[nd].back());
			stack[nd].pop_back();
			nd=(nd+1)%2;
		}
		int R=max(stack[0].size(),stack[1].size());
		int A[2] = {2,1};
		printf("%d% 3d\n",A[(nd+1)%2],R);
	}
	return 0;
}
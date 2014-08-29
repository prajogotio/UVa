#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string words[74];
int N;

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &N);
		for(int i=0;i<N;++i){
			cin >> words[i];
		}
		int ans = 0;
		for(int i=0;i<N;++i){
			for(int j=i+1;j<N;++j){
				int len1 = words[i].size();
				int len2 = words[j].size();
				int b = min(len1,len2);
				int cur = 0;
				for(int x=0;x<len1;++x){
					int c = 0;
					for(int y=0;y<b && y <len1-x; ++y){
						if(words[i][x+y] == words[j][y]) ++c;
					}
					cur = max(cur, c);
				}
				for (int x=0;x<len2;++x){
					int c = 0;
					for(int y=0;y<b && y < len2-x;++y){
						if(words[j][x+y] == words[i][y]) ++c;
					}
					cur = max(cur, c);
				}
				ans = max(cur, ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

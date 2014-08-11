#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char w[4] = "BGC";
int b[3][3];

int main(){
	while(scanf("%d", &b[0][0])!=EOF){
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j){
				if(i==0 && j==0) continue;
				scanf("%d", &b[i][j]);
			}

		int ans = -1;
		int x,y,z;
		string prev;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				for(int k=0;k<3;++k){
					if(i == j || i == k || j == k) continue;
					int temp = 0;
					string cur = "";
					for(int p=0;p<3;++p){
						if(p != i) temp += b[0][p];
						if(p != j) temp += b[1][p];
						if(p != k) temp += b[2][p];
					}
					cur += w[i];
					cur += w[j];
					cur += w[k];
					//cout << cur << endl;
					if(ans == -1 || temp < ans || (temp == ans && prev > cur)){
						ans = temp;
						x = i;
						y = j;
						z = k;
						prev = cur;
					}
				}

		printf("%c%c%c %d\n", w[x], w[y],w[z], ans);
	}
	return 0;
}
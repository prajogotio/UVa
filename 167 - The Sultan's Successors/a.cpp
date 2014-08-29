#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > arr;
vector<int> way(10);
int val[9][9];
int N = 0;

void rec(int n){
	if(n == 8){
		arr.push_back(way);
		++N;
		return;
	}
	for(int i=0;i<8;++i){
		bool ok = true;
		for(int j=0;j<n;++j){
			if( way[j] == i || way[j] - i == j - n || way[j] - i == n - j){
				ok = false;
				break;
			}
		}
		if(!ok) continue;
		way[n] = i;
		rec(n+1);
	}
}

int main(){
	rec(0);
	/*
	for(int i=0;i<N;++i){
		for(int j=0;j<8;++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	*/
	int K, ans, temp;
	scanf("%d", &K);
	while(K--){
		ans = 0;
		for(int i=0;i<8;++i){
			for(int j=0;j<8;++j){
				scanf("%d", &val[i][j]);
			}
		}
		for(int i=0;i<N;++i){
			temp = 0;
			for(int j=0;j<8;++j){
				temp += val[j][arr[i][j]];
			}
			ans = max(ans, temp);
		}
		printf("%5d\n", ans);
	}
	return 0;
}
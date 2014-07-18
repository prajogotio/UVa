#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > vall;

void dfs(int arr[], int c){
	if( c == 8 ){
		vall.push_back(vector<int>(arr,arr+8));
		return;
	}
	for(int i=1;i<=8;++i){
		bool nogood = false;
		for(int j=0;j<c;++j){
			if(arr[j] == i || (arr[j] - i == j - c) || (arr[j] - i == c - j)){
				nogood = true;
				break;
			}
		}
		if(nogood) continue;
		arr[c] = i;
		dfs(arr, c+1);
	}
}

int main(){
	int arr[8];
	dfs(arr, 0);
	printf("%d\n", vall.size());
	printf("{");
	for(int i=0;i<vall.size();++i){
		if(i!=0)printf(",");
		printf("{");
		for(int j=0;j<8;++j){
			if(j!=0)printf(",");
			printf("%d", vall[i][j]);
		}
		printf("}");
	}
	printf("}");
	return 0;
}
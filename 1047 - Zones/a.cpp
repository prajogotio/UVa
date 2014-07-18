#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
vector<int> tower;
map<int,int> common;
vector<int> choice;
int N,T;

int choose(int max, int num, int ctr, int i, int temp){
	if(ctr == num){
		return temp;
	}
	if(i == max){
		return -1;
	}
	for(int j=i+1; j<=max;++j){
		choose(max,num,ctr+1,j,temp+(1<<j));
	}
}


void dfs(int i, int ctr, vector<int> ch){
	if(ctr == T){


int main(){
	while(scanf("%d %d",&N,&T), N!= 0 && T != 0){
		choice.assign(T,99);
		tower.clear();
		tower.push_back(0);
		common.clear();
		int c;
		for(int i=0;i<N;++i){
			scanf("%d",&c);
			tower.push_back(c):
		}
		int M;
		for(int i=0;i<M;++i){
			int t,m=0;
			scanf("%d",&t);
			for(int j=0;j<t;++j){
				int tj;
				scanf("%d",&tj);
				m += 1<<tj;
			}
			int val;
			scanf("%d", &val);
			common[m] = val;
		}

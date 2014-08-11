#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool runnum(int N){
	int n = 0;
	int occ[11] = {0};
	int arr[11] = {0};
	int vis[11] = {0};
	int temp = N;
	while(temp){
		int cur = temp%10;
		arr[n++] = cur;
		++occ[cur];
		if(cur == 0 || occ[cur] > 1) return false;
		temp /= 10;
	}
	reverse(arr, arr+n);
	//for(int i=0;i<n;++i) printf("%d ", arr[i]); printf("\n");

	int i = 0, j, tot = 0;
	while(!vis[i]){
		//printf("%d %d\n", N, i);
		++tot;
		vis[i] = 1;
		j = (arr[i] + i) % n;
		i = j;
	}
	return (i == 0 && tot == n);
}

int main(){
	int N, T=1;
	
	while(scanf("%d", &N), N!=0){
		printf("Case %d: ", T++);
		while(!runnum(N)) ++N;
		printf("%d\n", N);
	}
	
	/*
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	while(next_permutation(arr, arr+9)){
		int k = 100000000 * arr[0] + 10000000 * arr[1] + 1000000 * arr[2] + 100000 * arr[3] + 10000 * arr[4] + 1000 * arr[5] + 100 * arr[6] + 10 * arr[7] + arr[8];
		if(runnum(k)) printf("%d\n", k);
	}
	*/
	return 0;

}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define NMAX 1200
typedef long long Long;

int a[NMAX];
int b[NMAX];
int ctr;
int K, N;

Long dp[NMAX][200][17];

Long rec(int cur, int idx, int k){
  //printf("%d %d %d\n", cur, idx, k);
  if(cur == 0 && idx <= 197 && k == K) return 1LL;
  if(cur <= 0 || k >= K || idx >= 197) return 0LL;
  if(dp[cur][idx][k] != -1) return dp[cur][idx][k];
  Long tmp = rec(cur-b[idx], idx+1, k+1);
  Long tmp2 = 0;
  if(idx+1 < 197 && b[idx+1] <= cur){
    tmp2 = rec(cur, idx+1, k);
  }
  dp[cur][idx][k] = tmp + tmp2;
  return dp[cur][idx][k];
}

int main(){
  //sieve
  for(int i=0;i<=NMAX;++i) a[i] = 0;
  for(int i=2;i*i<=NMAX;++i){
    for(int j=i;i*j<=NMAX;++j){
      a[i*j] = 1;
    }
  }
  /*
  for(int i=2;i<=NMAX;++i){
    if(!a[i]) printf("%d\n", i);
  }
  */
  ctr = 0;
  for(int i=2;i<=NMAX;++i){
    if(!a[i]){
      b[ctr++] = i;
    }
  }
  while(scanf("%d %d", &N, &K), N+K != 0){
    for(int i=0;i<=N;++i)
      for(int j=0;j<200;++j)
        for(int k=0;k<=K;++k)
          dp[i][j][k] = -1;
    printf("%lld\n", rec(N,0,0));
  }
    
  return 0;
}
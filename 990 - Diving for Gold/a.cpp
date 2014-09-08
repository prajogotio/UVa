#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int val[35], depth[35];
int dp[35][1004];
int mark[35][1004];
int mark2[35];
int W, N, Time;

int rec(int k, int cur){
  if(cur < 0) return (int) -1e9;
  if(k == N) return 0;
  if(dp[k][cur] != -1) return dp[k][cur];
  int tmp = val[k] + rec(k+1, cur-3*W*depth[k]);
  int tmp2 = rec(k+1, cur);
  dp[k][cur] = max(tmp, tmp2);
  if(tmp > tmp2){
    mark[k][cur] = 1;
    return tmp;
  }
  else return tmp2;
}

int main(){
  int ans, tmp;
  bool flag = false;
  while(scanf("%d %d", &Time, &W) != EOF){
    if(flag) printf("\n");
    scanf("%d", &N);
    for(int i=0;i<N;++i){
      scanf("%d %d", &depth[i], &val[i]);
    }
    for(int i=0;i<N;++i){
      for(int j=0;j<=Time;++j){
        dp[i][j] = -1;
        mark[i][j] = 0;
      }
    }
    for(int i=0;i<N;++i){ mark2[i] = 0; }
    ans = rec(0, Time);
    tmp = Time;
    int cnt = 0;
    printf("%d\n", ans);
    for(int i=0;i<N;++i){
      if(mark[i][tmp]){
        ++cnt;
        mark2[i] = 1;
        tmp -= 3*W*depth[i];
      }
    }
    printf("%d\n", cnt);
    for(int i=0;i<N;++i){
      if(mark2[i]){
        printf("%d %d\n", depth[i], val[i]);
      }
    }
    flag = true;
  }
  return 0;
}
    
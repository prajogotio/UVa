#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
//RECURRENCE F(N) = F(N-1) + ( floor[ (N-1)/2 ] + 1 ) * 2
typedef long long llong;
//vector<llong> peg[52];
llong peg[52];
llong ans;
int N;

bool check(llong x){
  llong hi = x, lo = 1, mid;
  while(lo <= hi){
    mid = (hi+lo)/2;
    if (mid * mid < x){
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }
  //printf("%lld %lld \n", lo*lo, x);
  return lo * lo == x;
}

void po(){
  //for(int i=0;i<N;++i) if (peg[i].empty()) printf("0 "); else printf("%lld ", peg[i].back());
  for(int i=0;i<N;++i) printf("%lld ", peg[i]);
  printf("\n");
}

void rec(llong k, int c){
  //if(k == 60) po();
  ans = max(ans, k);
  for(int i=0;i<c;++i){
    //if(check(peg[i].back() + k)){
      //peg[i].push_back(k);
    if(check(peg[i] + k)){
      llong temp = peg[i];
      peg[i] = k;
      rec(k+1, c);
      //peg[i].pop_back();
      peg[i] = temp;
    }
  }
  if(c < N){
    //peg[c].push_back(k);
    peg[c] = k;
    rec(k+1, c+1);
    //peg[c].pop_back();
    peg[c] = 0;
  }
}

void rec2(llong k, int c){
  //printf("%lld %d\n", k, c);
  ans = max(k, ans);
  bool found = false;
  for(int i=0;i<c;++i){
    if(check(k + peg[i])){
      peg[i] = k;
      rec2(k+1, c);
      found = true;
      break;
    }
  }
  if(!found && c < N){
    peg[c] = k;
    rec2(k+1,c+1);
  }
}

int main(){
  //for(int i=0;i<52;++i) peg[i].clear();
  for(int i=0;i<52;++i) peg[i] = 0;
  int TC;
  scanf("%d", &TC);
  while(TC--){
    scanf("%d", &N);
    ans = 0;
    rec2(1,0);
    printf("%lld\n", ans-1);
  }
  return 0;
}
  
  
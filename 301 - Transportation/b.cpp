#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long Long;
vector<pair<pair<int,int>, Long> > stack;
int C, N, S;
int a[10];
int b[10];
Long ans;
//FAIL FAIL FAIL

int main(){
  int u,v;
  Long w;
  for(int i=0;i<10;++i){
    a[i] = 0;
    b[i] = 0;
  }
  while(scanf("%d %d %d", &C, &N, &S), C+N+S != 0){
    ans = 0;
    stack.clear();
    for(int i=0;i<S;++i){
      scanf("%d %d %lld", &u, &v, &w);
      stack.push_back(make_pair(make_pair(u,v), w) );
    }
    sort(stack.begin(), stack.end());
    int Lim = 1 << S;
    for(int i=0;i<Lim;++i){
      for(int j=0;j<N;++j){a[j] = b[j] = 0;}
      Long sum = 0;
      for(int j=0;j<S;++j){
        if(i & (1<<j)){
          u = stack[j].first.first;
          v = stack[j].first.second;
          w = stack[j].second;
          
          a[u] += w;
          b[v] += w;
          sum += w * ((Long)(v - u));
        }
      }
      int cur = 0;
      for(int j=0;j<N;++j){
        cur += a[u] - b[v];
        if(cur > C){
          sum = -1;
          break;
        }
      }
      ans = max(ans, sum);
    }
    cout << ans << endl;
  }
  return 0;
}
        
      
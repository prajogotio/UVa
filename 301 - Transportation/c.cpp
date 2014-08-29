#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

/*
 * LEARNING PT:
 * Be careful with using global variables on recursion, especially those that
 * cannot be deduced from stack calls
 *
 * EG: 
 * v = adj[u][k].first
 * w = adj[u][k].second
 * a[v] += w
 * rec(.....) //recursive call
 * a[v] -= w //here w already refers to another value!!, v as well!!!!
 *
 */

typedef long long Long;
vector<vector<pair<int,Long> > > adj;
int sz[10];
Long C;
int N, S;
Long ans;
  
Long a[10];

void rec(Long cur, Long sum, int u, int k){
  //printf("%lld %lld %d %d %lld\n", cur, sum, u, k, a[u]);
  if(u == N){
    ans = max(ans, sum);
    return;
  }
  //if k == 0, let people out
  if(k == 0) cur -= a[u];
  if(k == sz[u]) {
    rec(cur, sum, u+1, 0);
    return;
  }
  int v = adj[u][k].first;
  Long w = adj[u][k].second;
  if( cur + w <= C ){
    a[v] += w;
    rec(cur + w, sum + w * ((Long) (v - u)), u, k+1);
    a[v] -= w;
  }
  rec(cur, sum, u, k+1);
}

int main(){
  int u,v;
  Long w;
  for(int i=0;i<10;++i){ a[i] = 0; }
  while(scanf("%lld %d %d", &C, &N, &S), N+C+S != 0){
    /*
    for(int i=0;i<10;++i){
      printf("%lld ", a[i]);
    }
    printf("\n");
    */
    adj = vector<vector<pair<int,Long> > >(N+3);
    for(int i=0;i<N;++i) sz[i] = 0;
    for(int i=0;i<S;++i){
      scanf("%d %d %lld", &u, &v, &w);
      adj[u].push_back(make_pair(v,w));
      ++sz[u];
    }
    ans = 0;
    rec(0, 0, 0, 0);
    cout << ans << endl;
  }
  return 0;
}
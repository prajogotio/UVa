#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int a[100000];
int M, N;
int sz;
map<long long, int> vis;

bool completed;

long long power(int m, int n){
  long long ret = 1;
  for(int i = 0;i<m;++i){
    ret *= n;
  }
  return ret;
}

void rec(int k, long long cur){
  if(completed) return;
  if(k == sz-M+1) {
    /*
    for(int i=0;i<sz;++i){
      printf("%d", a[i]);
    }
    
    printf("\n");
    */
    long long tot = 0;
    for(int i=sz-M+1;i<sz;++i){
      tot *= (long long) N;
      tot += (long long) a[i];
    }
    tot *= (long long) N;
    for(int i=sz-M+1;i<sz;++i){
      if(vis[tot]){
        return;
      }
      tot -= (long long) a[i] * power(M-1,N);
      tot *= (long long) N;
    }
    completed = true;
    return;
  }
  cur *= (long long) N;
  for(int i=0;i<N;++i){
    if(vis[cur+i]) continue;
    vis[cur+i] = 1;
    a[k+M-1] = (long long) i;
    rec(k+1, cur + (long long) i - power(M-1,N) * (long long) a[k] );
    if(completed) return;
    vis[cur+i] = 0;
  }
}

int main(){
  while(cin >> M >> N){
    sz = (int) power(M,N);
    for(int i=0;i<M;++i){
      a[i] = 0;
    }
    vis.clear();
    vis[0] = 1;
    completed = false;
    rec(1, 0);
    for(int i=0;i<sz;++i){
      printf("%d",a[i]);
    }
    printf("\n");
  }
  return 0;
}
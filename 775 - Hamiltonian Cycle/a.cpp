#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > adj;
int vis[260];
int par[260];
int N;
bool completed;

void printpath(int u){
  if(par[u] == -1){
    printf("%d", u);
    return;
  }
  printpath(par[u]);
  printf(" %d", u);
}

void dfs(int u, int k){
  if(completed) return;
  vis[u] = 1;
  for(int i=0;i<adj[u].size();++i){
    int v = adj[u][i];
    if(vis[v]){
      if(par[v] == -1 && k == N){
        printpath(u);
        printf(" %d\n", v);
        completed = true;
        return;
      }
    } else {
      par[v] = u;
      dfs(v,k+1);
      if(completed) return;
    }
  }
  vis[u] = 0;
}

int main(){
  int u,v;
  while(scanf(" %d", &N)!= EOF){
    adj = vector<vector<int> > (N+4);
    for(int i=0;i<=N;++i) vis[i] = 0;
    while(scanf("%d %d", &u, &v)){
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    completed = false;
    par[1] = -1;
    dfs(1,1);
    if(!completed) printf("N\n");
    getchar();
  }
  return 0;
}
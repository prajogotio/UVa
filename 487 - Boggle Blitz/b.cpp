#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <vector>
using namespace std;

set<pair<int,string> > dp[25][25];
int vis[25][25];
string m[25];
set<pair<int,string> > ans;
int N;

void check(int,int,int,int);
bool rec(int,int,char);

void check(int i, int j, int u, int v){
  if(rec(u,v,m[i][j])){
    for(set<pair<int,string> >::iterator it = dp[u][v].begin(); it != dp[u][v].end(); ++it){
      string temp = "";
      temp += m[i][j];
      temp += it -> second;
      dp[i][j].insert(make_pair((it->first)+1, temp));
    }
  }
}

bool rec(int i, int j, char c){
  if(i < 0 || j < 0 || i >= N || j >= N) return false;
  if(c >= m[i][j]) return false;
  if(vis[i][j]) return true;
  dp[i][j].clear();
  c = m[i][j];
  dp[i][j].insert(make_pair(1, string(1,c)));
  check(i,j,i-1,j);
  check(i,j,i,j-1);
  check(i,j,i-1,j-1);
  check(i,j,i+1,j+1);
  check(i,j,i+1,j);
  check(i,j,i,j+1);
  check(i,j,i-1,j+1);
  check(i,j,i+1,j-1);
  vis[i][j] = 1;
  return true;
}

int main(){
  int TC;
  scanf("%d", &TC);
  bool flag = false;
  while(TC--){
    if(flag) printf("\n");
    scanf("%d", &N);
    ans.clear();
    for(int i=0;i<N;++i)for(int j=0;j<N;++j){
      vis[i][j] = 0;
    }
    for(int i=0;i<N;++i) cin >> m[i];
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        if(vis[i][j]) continue;
        rec(i,j,0);
      }
    }
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        ans.insert(dp[i][j].begin(), dp[i][j].end());
      }
    }
    for(set<pair<int,string> > :: iterator it = ans.begin(); it != ans.end(); ++it){
      if(it->first < 3) continue;
      cout << it->second << endl;
    }
    flag = true;
  }
  return 0;
}
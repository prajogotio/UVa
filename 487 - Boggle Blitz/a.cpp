#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

set<pair<int,string> > ans;
char b[23][23];
int vis[23][23];
int comp[23][23];
int N;

//i suspect this wont cut it 
void rec(int i, int j, string str, char c){
  if(i < 0 || j < 0 || i >= N || j >= N) return;
  if(vis[i][j]) return;
  if(b[i][j] <= c) return;
  int sz = str.size();
  str += b[i][j];
  if(sz + 1 >= 3) {
    for(int k = 0; k+2 < sz+1; ++k){
      ans.insert(make_pair(sz+1-k, str.substr(k,sz + 1 - k)));
    }
  }
  vis[i][j] = 1;
  rec(i-1,j,str, b[i][j]);
  rec(i, j-1, str, b[i][j]);
  rec(i-1, j-1, str, b[i][j]);
  rec(i+1, j, str, b[i][j]);
  rec(i, j+1, str, b[i][j]);
  rec(i+1, j+1, str, b[i][j]);
  rec(i-1, j+1, str, b[i][j]);
  rec(i+1, j-1, str, b[i][j]);
  vis[i][j] = 0;
  str.resize ( sz );
  comp[i][j] = 1;
}

int main(){
  int TC;
  scanf("%d", &TC);
  bool flag = false;
  for(int i=0;i<23;++i){
    for(int j=0;j<23;++j){
      vis[i][j] = 0;
    }
  }
  while(TC--){
    if(flag) printf("\n");
    scanf("%d", &N);
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        scanf(" %c", &b[i][j]);
        comp[i][j] = 0;
      }
    }
    ans.clear();
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        if(comp[i][j]) continue;
        rec(i,j,"", 0);
      }
    }
    for(set<pair<int,string> >::iterator it = ans.begin(); it != ans.end(); ++it){
      cout << it->second << endl;
    }
    flag = true;
  }
  return 0;
}
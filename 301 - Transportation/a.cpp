#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef long long Long;

//TLE :(

int Cap, Num, Ord;
Long Ans;

vector<vector<pair<int, Long> > > Adj;
int Out[20];

void Rec(int Cur, Long Sum, int k){
  if(k == Num){
    Ans = max(Ans, Sum);
    return;
  }
  int sz = Adj[k].size();
  int Lim = 1 << sz;
  int Temp;
  Long Add;
  for(int i = 0; i < Lim; ++i){
    Temp = 0;
    Add = 0;
    for(int j = 0; j < sz; ++j){
      if( i & (1 << j) ){
        Temp += Adj[k][j].second;
        Add += Adj[k][j].second * ((Long) (Adj[k][j].first - k));
        Out[ Adj[k][j].first ] += Adj[k][j].second;
      }
    }
    if( Cur + Temp - Out[k] <= Cap){
      Rec( Cur + Temp - Out[k], Sum + Add, k+1);
    }
    for(int j=0; j<sz;++j){
      if(i & (1<<j)){
        Out[Adj[k][j].first] -= Adj[k][j].second;
      }
    }
  }
  
}

int main(){
  int u,v,w;
  for(int i=0;i<10;++i) Out[i] = 0;
  
  while(scanf("%d %d %d", &Cap, &Num, &Ord), Cap+Num+Ord != 0){
    Adj = vector<vector<pair<int, Long> > >(Num+3);
    for(int i=0;i<Ord;++i){
      scanf("%d %d %d", &u, &v, &w);
      Adj[u].push_back(make_pair(v, w));
    }
    Ans = 0;
    Rec(0, 0, 0);
    cout << Ans << endl;
  }
  return 0;
}
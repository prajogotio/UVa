#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, P;
vector<int> a;

int main(){
  int hi,lo,mid;
  int nmax;
  int Hi,Lo;
  int u;
  while(scanf(" %d", &P) != EOF){
    scanf(" %d", &N);
    a.clear();
    for(int i=0;i<N;++i){
      scanf(" %d", &u);
      a.push_back(u);
    }
    nmax = 0;
    for(int i=0;i<N;++i){
      lo = i;
      hi = N-1;
      while(lo <= hi){
        //printf("%d %d\n", lo, hi);
        mid = (lo+hi)/2;
        if(a[mid] - a[i] + 1 <= P){
          lo = mid+1;
        } else {
          hi = mid-1;
        }
      }
      if(nmax < hi - i + 1){
        nmax = hi - i + 1;
        Lo = i;
        Hi = hi;
      }
    }
    //printf("%d %d %d\n", nmax, Lo, Hi);
    printf("%d %d %d\n", nmax, a[Lo], a[Hi]);
  }
  return 0;
}
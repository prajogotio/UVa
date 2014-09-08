#include <iostream>
#include <cstdio>
using namespace std;

int H[50003];
int N;

int lobound(int h){
  int lo=0, hi = N-1, mid;
  while(lo <= hi){
    mid = (lo + hi)/2;
    if(H[mid] < h){
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }
  return lo;
}

int upbound(int h){
  int lo = 0, hi = N-1, mid;
  while(lo <= hi){
    mid = (lo+hi)/2;
    if(H[mid] <= h){
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }
  return lo;
}


int main(){
  int Q, q, r_lo, r_hi;
  while(cin >> N){
    for(int i=0;i<N;++i){
      cin >> H[i];
    }
    cin >> Q;
    for(int qq=0;qq<Q;++qq){
      cin >> q;
      r_lo = lobound(q);
      r_hi = upbound(q);
      if(r_lo > 0) printf("%d ", H[r_lo-1]);
      else printf("X ");
      if(r_hi < N) printf("%d\n", H[r_hi]);
      else printf("X\n");
    }
  }
  return 0;
}
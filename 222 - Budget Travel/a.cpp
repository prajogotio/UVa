#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long llong;
double full, mpf, ocost, dest;
int S;
double station[55];
double price[55];
llong ans;

llong cnv(double x){
  llong temp = (llong) x;
  if( x - temp < 0.5){
    return x;
  } else {
    return x+1;
  }
}

void rec(double fuel, llong spend, int state){
  if( state == S ){
    ans = min(spend, ans);
    //printf("last: %lld\n", spend);
    return;
  }
  //printf("fuel:%lf spend:%lld station:%d\n", fuel, spend, state);
  if( state+1 < S && station[state+1] - station[state] < fuel*mpf){
    rec( fuel - ( (station[state+1] - station[state]) / mpf ), spend, state+1);
    if( fuel > full / 2 ) return;
  } else if (state+1 == S && dest - station[state] < fuel*mpf){
    rec( fuel - ( (dest - station[state]) / mpf ), spend, state+1);
    if( fuel > full / 2 ) return;
  }
  //printf("refill at %d\n", state);
  double cost = (full - fuel)*price[state];
  double dist = -station[state];
  if( state == S-1) dist += dest;
  else if (state < S) dist += station[state+1];
  rec( full - dist/mpf, spend + cnv(cost) + 200, state+1);
}

int main(){
  int T = 1;
  while(scanf("%lf", &dest) != EOF){
    if( dest < 0 ) break;
    scanf("%lf %lf %lf %d", &full, &mpf, &ocost, &S);
    ocost *= 100;
    for(int i=0;i<S;++i){
      scanf("%lf %lf", &station[i], &price[i]);
    }
    ans = (llong) 1e18;
    rec(full - (station[0]/mpf) , cnv(ocost), 0);
    printf("Data Set #%d\nminimum cost = $%lld.%02lld\n", T++, ans/100, ans%100);
  }
  return 0;
}
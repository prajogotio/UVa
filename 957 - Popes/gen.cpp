#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int a[5003];
int N;
int main(){
  N=0;
  while(N<5000){
    a[N++] = (int) (rand()%1000000);
  }
  sort(a,a+N);
  for(int i=0;i<N;++i){
    printf("%d\n", a[i]);
  }
  return 0;
}
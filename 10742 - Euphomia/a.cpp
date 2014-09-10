#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long Long;
int p[1000003], a[1000003];
int P, N;
void sieve(){
    P = 0;
    for(int i=0;i<=1000000;++i) a[i] = 1;
    for(int i=2;i*i<=1000000;++i){
        for(int j=i;j*i<=1000000;++j){
            a[i*j] = 0;
        }
    }
    for(int i=2;i<=1000000;++i){
        if(a[i]){
            p[P++] = i;
        }
    }
}

Long solve(){
    Long ans = 0;
    int X,hi,lo,mid;
    for(int i=0;i<P;++i){
        X = N - p[i];
        if(X <= 1) break;
        lo = 0; hi = P-1;
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(p[mid] <= X){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        //printf("%d %d\n", p[i], p[lo-1]);
        if(lo <= i+1) break;  //not proven yet
        ans += (lo - i - 1);
    }
    return ans;
}

int main(){
    sieve();
    int T = 1;
    while( cin >> N, N!=0 ){
        printf("Case %d: ", T++);
        cout << solve() << endl;
    }
    return 0;
}
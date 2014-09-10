#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long Long;

Long s[100003];
Long sum[100003];
int upp;

int ndig(int n){
    int ret = 0;
    while(n){
        ++ret;
        n/=10;
    }
    return ret;
}

int main(){
    s[0] = 0;
    sum[0] = 0;
    int ctr, n;
    for(int i=1;i<100003;++i){
        n = i; ctr = 0;
        while(n){
            ++ctr;
            n/=10;
        }
        s[i] = s[i-1] + ctr;
        sum[i] = s[i] + sum[i-1];
        upp = i;
        if(sum[i] > 2147483647) break;
    }
    int TC;
    cin >> TC;
    Long N, lo, hi, mid, tmp;
    while(TC--){
        cin >> N;
        //printf("for N = %lld\n", N);
        
        lo = 0, hi = upp;
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(sum[mid] >= N){
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        //printf("hi terminates at %lld\n", hi);
        //printf("sum up to hi is %lld\n", sum[hi]);
        tmp = N - sum[hi];
        lo = 0; hi = upp;
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(s[mid] >= tmp){
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        //printf("hi is %lld where s[hi] is %lld\n", hi, s[hi]);
        tmp = tmp - s[hi];
        ++hi;
        ctr = ndig(hi);
        tmp = ctr - tmp;
        //printf("it is %lld digit of %lld\n", tmp, hi);
        for(int i=0;i<tmp;++i){
            hi /= 10;
        }
        cout << hi%10 << endl;
    }
    return 0;
}
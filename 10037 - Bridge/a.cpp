#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/* 
Suggested Greedy algo: Incremental construction:
The idea is to always bring the first and second slowest to the other side
with the help of the first and second fastest 
say the fastests are A<B
and the slowest are X>Y
then we have 2 cases:
1. M = (A,X) + (A,0) + (A,Y) + (A,0)
   M = 2*A + X + Y
2. M' = (A,B) + (A,0) + (X,Y) + (B,0)
   M' = 2*B + A + X
And incrementally choosing the minimum of M and M' at each step.
Proof? I dont know
*/

int a[1003];
int s[10003];
int K, N;
int main(){
    int TC;
    cin >> TC;
    bool flag = false;
    while(TC--){
        if(flag) printf("\n");
        flag = true;
        cin >> N;
        for(int i=0;i<N;++i){
            cin >> a[i];
        }
        if(N == 0){
            cout << 0 << endl;
            continue;
        }
        if(N == 1){
            cout << a[0] << endl;
            cout << a[0] << endl;
            continue;
        }
        K = 0;
        sort(a, a+N);
        int ans = 0;
        int last = N-1;
        for(;last-1>1;last-=2){
            int M = 2*a[0] + a[last] + a[last-1];
            int MM = 2*a[1] + a[0] + a[last];
            if(M < MM){
                ans += M;
                s[K++] = 0;
            } else {
                ans += MM;
                s[K++] = 1;
            }
        }
        int state = (last == 2)?0:1;
        if(state == 0){
            ans += a[last] + a[0] + a[1];
        } else {
            ans += a[1];
        }
        cout << ans << endl;
        for(int i=0;i<K;++i){
            if(s[i] == 0){
                printf("%d %d\n",a[0], a[N-1-2*i]);
                printf("%d\n", a[0]);
                printf("%d %d\n", a[0], a[N-1-2*i-1]);
                printf("%d\n", a[0]);
            } else {
                printf("%d %d\n", a[0], a[1]);
                printf("%d\n", a[0]);
                printf("%d %d\n", a[N-1-2*i-1],a[N-1-2*i]);
                printf("%d\n", a[1]);
            }
        }
        if(state == 0){
            printf("%d %d\n", a[0], a[last]);
            printf("%d\n%d %d\n", a[0], a[0], a[1]);
        } else {
            printf("%d %d\n", a[0], a[1]);
        }
    }
    return 0;
}
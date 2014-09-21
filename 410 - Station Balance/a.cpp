#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[12];
int b[12];
int main(){
    int C,N;
    int T=1;
    while(cin >> C >> N){
        printf("Set #%d\n", T++);
        int sum = 0;
        for(int i=0;i<N;++i){
            cin >> a[i];
            sum += a[i];
        }
        
        sort(a, a+N);
        for(int i=0;i<C;++i){
            b[i] = a[N-i-1];
            if(i >= 2*C-N) b[i] += a[i-2*C+N];
        }
        double ave = (double) sum / (double) C;
        double ans = 0;
        for(int i=0;i<C;++i){
            double temp = (double) b[i] - ave;
            if(temp < 0) temp = -temp;
            ans += temp;
        }
        for(int i=0;i<C;++i){
            printf(" %d:", i);
            if(N-i-1 >= 0) printf(" %d", a[N-i-1]);
            if(i-2*C+N >= 0) printf(" %d", a[i-2*C+N]);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n", ans);
        printf("\n");
    }
    return 0;
}
        
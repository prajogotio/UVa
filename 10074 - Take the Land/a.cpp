#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[103][103];
int a[103][103];

int main(){
    int R,C;
    while(cin >> R >> C, R+C!=0){
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                cin >> a[i][j];
            }
        }
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                dp[i][j] = a[i][j];
                if(i>0) dp[i][j] += dp[i-1][j];
                if(j>0) dp[i][j] += dp[i][j-1];
                if(i>0 && j>0) dp[i][j] -= dp[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i=0;i<R;++i){
            for(int j=i;j<R;++j){
                for(int ii=0;ii<C;++ii){
                    for(int jj=ii;jj<C;++jj){
                        int tmp = dp[j][jj];
                        if(i>0) tmp -= dp[i-1][jj];
                        if(ii>0) tmp -= dp[j][ii-1];
                        if(i>0 && ii>0) tmp += dp[i-1][ii-1];
                        if(tmp == 0) ans = max(ans, (j-i+1)*(jj-ii+1));
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
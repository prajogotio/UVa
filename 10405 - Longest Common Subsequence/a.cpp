#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a,b;
int dp[1003][1003];

int main(){
    while(getline(cin, a)){
        getline(cin,b);
        int A=a.size(), B=b.size();
        for(int i=0;i<=A;++i){
            dp[i][0] = 0;
        }
        for(int j=0;j<=B;++j){
            dp[0][j] = 0;
        }
        for(int i=1;i<=A;++i){
            for(int j=1;j<=B;++j){
                dp[i][j] = (a[i-1] == b[j-1])? 1+dp[i-1][j-1] : 0;
                dp[i][j] = max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
            }
        }
        cout << dp[A][B] << endl;
    }
    return 0;
}
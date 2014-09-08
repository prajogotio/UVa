#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int> > S;
int MAXINT = (int) 1e9;
int dp[1005][105];
int N;

int rec(int G, int W, int k){
    if(W > G) return -MAXINT;
    if(W >= G || k == N) return 0;
    if(W + S[k].first > G) return 0;
    if(dp[W][k] != -1) return dp[W][k];
    int ret1 = S[k].second + rec(G, W+S[k].first, k+1);
    int ret2 = rec(G, W, k+1);
    dp[W][k] = max(ret1, ret2);
    return dp[W][k];
}

int main(){
    int TC, Q, G, p, w;
    cin >> TC;
    while(TC--){
        cin >> N;
        S.clear();
        for(int i=0;i<N;++i){
            scanf("%d %d", &p, &w);
            S.push_back(make_pair(w,p));
        }
        sort(S.begin(), S.end());
        cin >> Q;
        int res = 0;
        for(int nq=0;nq<Q;++nq){
            cin >> G;
            for(int i=0;i<1005;++i)
                for(int j=0;j<105;++j)
                    dp[i][j] = -1;
            res += rec(G, 0, 0);
        }
        cout << res << endl;
    }
    return 0;
}
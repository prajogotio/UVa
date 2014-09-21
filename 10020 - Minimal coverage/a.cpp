#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
int maxint = (int) 1e9;
pair<int,int> itv[100003];
int seg[100003];
int p[100003];
int N,M,K;

int main(){
    int TC;
    bool flag = false;
    cin >> TC;
    while(TC--){
        if(flag) printf("\n");
        cin >> M;
        N = K = 0;
        int u,v;
        for(int i=0;i<100003;++i) {seg[i] = -maxint;}
        while(cin >> u >> v){
            if(u==0&&v==0)break;
            seg[u+50000] = max(v, seg[u+50000]);
        }
        for(int i=0;i<100003;++i){
            if(seg[i] == -maxint) continue;
            itv[N] = make_pair(i-50000, seg[i]);
            ++N;
        }
        int i=0;
        int mr = -maxint, imr;
        bool ok = false;
        for(int j=0;j<N;++j){
            if(itv[j].first > i){
                if(!ok) break;
                ok = false;
                i = mr+1;
                p[K] = imr;
                printf("%d %d %d\n", mr, itv[imr].first, itv[imr].second);
                ++K;
                if( mr >= M ) break;
            }
            if(itv[j].first <= i < itv[j].second){
                if(mr < itv[j].second){
                    mr = itv[j].second;
                    imr = j;
                    ok = true;
                }
            }
        }
        if(i < mr){
            i = mr;
            p[K] = imr;
            ++K;
        }
        if(i < M) {
            printf("0\n");
        } else {
            printf("%d\n", K);
            for(int i=0;i<K;++i){
                printf("%d %d\n", itv[p[i]].first, itv[p[i]].second);
            }
        }
        flag = true;
    }
    return 0;
}
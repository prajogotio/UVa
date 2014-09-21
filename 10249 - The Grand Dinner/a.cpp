#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

/* First IDEA:
sort by no of ppl, sort by table
for each group, go through table in sorted order assign what is available
if possible, print arragement, otherwise no arrangement is possible
proof: dunno yet
*/

vector<pair<int,int> > ppl, tbl;
int pp[73] /*, tt[53]*/;
int ppp[73][103], ttt[73];
int main(){
    int N,M;
    while( cin >> M >> N ){
        if(N+M==0) break;
        ppl.clear();
        tbl.clear();
        for(int i=0;i<M;++i){
            int u;
            cin >> u;
            ppl.push_back(make_pair(u,i));
        }
        for(int i=0;i<N;++i){
            int u;
            cin >> u;
            tbl.push_back(make_pair(u,i));
        }
        sort(ppl.begin(), ppl.end());
        sort(tbl.begin(), tbl.end());
        reverse(ppl.begin(), ppl.end());
        reverse(tbl.begin(), tbl.end());
        for(int i=0;i<M;++i){
            pp[ppl[i].second] = i;
        }
        for(int i=0;i<N;++i){
            //tt[tbl[i].second] = i;
            ttt[i] = tbl[i].first;
        }
        bool ok = true;
        for(int i=0;i<M;++i){
            int sz = ppl[i].first;
            int k = 0;
            for(int j=0;j<sz;++j){
                bool found = false;
                for(;k<N;++k){
                    if(ttt[k] > 0){
                        found = true;
                        ppp[i][j] = tbl[k].second;
                        --ttt[k];
                        break;
                    }
                }
                if(!found){
                    ok = false;
                    break;
                }
                ++k;
            }
            if(!ok) break;
        }
        if(!ok) printf("0\n");
        else {
            printf("1\n");
            for(int i=0;i<M;++i){
                int sz = ppl[pp[i]].first;
                for(int j=0;j<sz;++j){
                    if(j != 0) printf(" ");
                    printf("%d", ppp[pp[i]][j]+1);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
                    
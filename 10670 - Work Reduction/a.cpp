#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int M, N, L;
char name[103][20];
int cost[103][2];
vector<pair<int, string> > vec;

int main(){
    int TC, T=1;
    cin >> TC;
    while(TC--){
        cin >> M >> N >> L;
        for(int i=0;i<L;++i){
            int j=0;
            char c;
            while(cin >> c, c!=':'){
                name[i][j++] = c;
            }
            name[i][j] = 0;
            scanf("%d,%d", &cost[i][0], &cost[i][1]);
        }
        vec.clear();
        for(int i=0;i<L;++i){
            int cur = M;
            int ans = 0;
            while(cur != N){
                if(cur/2 >= N){
                    int dif = cur - cur/2;
                    int temp = min(dif*cost[i][0], cost[i][1]);
                    ans += temp;
                    cur /= 2;
                } else {
                    int dif = cur - N;
                    ans += dif*cost[i][0];
                    break;
                }
            }
            string str = name[i];
            vec.push_back(make_pair(ans, str));
        }
        sort(vec.begin(), vec.end());
        printf("Case %d\n", T++);
        for(int i=0;i<L;++i){
            printf("%s %d\n", vec[i].second.c_str(), vec[i].first);
        }
    }
    return 0;
}

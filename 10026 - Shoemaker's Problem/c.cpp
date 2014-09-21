#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/* 
The correct greedy algo and its proof: sort by fine/time
Proof:
s is fine, t is days
Suppose that (s_1,t_1), (s_2,t_2), ..., (s_n,t_n) is the optimal
arrangement such that the total fine is the lowest. Hence we have
O = s_1 (0) + s_2 (t_1) + s_3 (t_1 + t_2) + ...
    + s_i (t_1 + t_2 + ... + t_{i-1})
    + s_{i+1} (t_1 + t_2 + ... + t_{i-1} + t_i) 
    + ...
Since O is optimal, by exchange argument, if we exchange the position of
s_i,t_i and s_{i+1},t_{i+1}, we will have total fine O' which will cannot be lower
than O:
O' = ... + s_{i+1} (t_1 + t_2 + ... + t_{i-1})
         + s_i (t_1 + t_2 + ... + t_{i-1} + t_{i+1})
         + ...
         
hence O' - O >= 0 
<=>
s_{i+1} (-t_i) + s_i (t_{i+1}) >= 0
<=>
s_i/t_i >= s_{i+1}/t_{i+1}

Hence in the optimal arrangement, s_i comes before s_{i+1} iff s_i/t_i >= s_{i+1}/t_{i+1}
*/

vector<int> arr, s, t;

bool comp(const int& L, const int& R){
    if(s[L] * t[R] == s[R] * t[L]) return L < R;
    return s[L] * t[R] < s[R] * t[L];
}

int main(){
    int TC;
    cin >> TC;
    bool flag = false;
    while(TC--){
        if(flag) printf("\n");
        flag = true;
        int N;
        cin >> N;
        arr.clear();
        s.clear();
        t.clear();
        for(int i=0;i<N;++i){
            int u,v;
            cin >> u >> v;
            s.push_back(u);
            t.push_back(v);
            arr.push_back(i);
        }
        sort(arr.begin(), arr.end(), comp);
        for(int i=0;i<N;++i){
            if(i != 0) printf(" ");
            printf("%d", arr[i]+1);
        }
        printf("\n");
    }
    return 0;
}
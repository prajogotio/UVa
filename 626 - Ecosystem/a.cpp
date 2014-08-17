#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int a[103][103];
int N;

vector<pair<int, pair<int, int> > > ans;

int main(){
	int tot;
	while(cin >> N){
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				scanf("%d", &a[i][j]);

		tot = 0;
		ans.clear();
		for(int i=0;i<N;++i)
			for(int j=i+1;j<N;++j)
				for(int k=j+1;k<N;++k)
				{
					//if(i == j || j==k || i == k) continue;
					if(a[i][j] && a[j][k] && a[k][i]) {
						ans.push_back(make_pair(i, make_pair(j, k) ) );
						++tot;
					}
					if(a[i][k] && a[k][j] && a[j][i]){
						ans.push_back(make_pair(k, make_pair(j, i) ) );
						++tot;
					}

				}
		sort(ans.begin(), ans.end());
		for(int i=0;i<tot;++i)
			printf("%d %d %d\n", ans[i].first+1, ans[i].second.first+1, ans[i].second.second+1);
		printf("total:%d\n\n", tot);
	}
	return 0;

}
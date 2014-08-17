#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int a[103][103];
int N;
vector<pair<int, pair<int,int> > > ans;
int main(){
	int tot;
	while( cin >> N){
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				scanf("%d", &a[i][j]);
		ans.clear();
		tot = 0;
		for(int i=0;i<N;++i)
			for(int j=i+1;j<N;++j)
				for(int k=j+1;k<N;++k)
				{
					if(!a[i][j] && !a[j][i] && !a[i][k] && !a[k][i] && !a[j][k] && !a[k][j]){
						++tot;
						ans.push_back(make_pair(i, make_pair(j, k)));
					}
					if(a[i][j] && a[j][k] && a[k][i]){
						++tot;
						ans.push_back(make_pair(i, make_pair(j, k)));
					}
					if(a[i][k] && a[k][j] && a[j][i]){
						++tot;
						ans.push_back(make_pair(k, make_pair(j,i)));
					}

				}

		sort(ans.begin(), ans.end());
		printf("%d\n", tot);
		for(int i=0;i<tot;++i){
			printf("%d %d %d\n", ans[i].first + 1, ans[i].second.first+1, ans[i].second.second + 1);
		}

	}
	return 0;

}
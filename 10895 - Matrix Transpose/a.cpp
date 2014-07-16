#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<vector<int> > adj;
vector<vector<int> > val;

int main()
{
	int M,N,r,u,v;
	while (scanf("%d %d", &M,&N) != EOF )
	{
		adj = vector<vector<int> >(N+1);
		val = vector<vector<int> >(N+1);
		for(int i = 1; i <= M;++i)
		{
			scanf("%d",&r);
			if( r == 0 )
			{
				continue;
			}
			vector<int> p,q;
			for(int j=0;j<r;++j)
			{
				scanf("%d",&u);
				p.push_back(u);
			}
			for(int j=0;j<r;++j)
			{
				scanf("%d", &v);
				q.push_back(v);
			}
			for(int j=0;j<r;++j)
			{
				adj[p[j]].push_back(i);
				val[p[j]].push_back(q[j]);
			}
		}
		printf("%d %d\n", N, M);
		for(int i = 1; i<= N;++i)
		{
			printf("%d", (int) val[i].size());
			if(val[i].size() == 0)
			{
				printf("\n\n");
				continue;
			}
			for(int j=0;j<adj[i].size(); ++j)
			{
				printf(" %d", adj[i][j]);
			}
			printf("\n");
			for(int j=0;j<val[i].size(); ++j)
			{
				if(j != 0) printf(" ");
				printf("%d", val[i][j]);
			}
			printf("\n");
		}

	}
	return 0;
}
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
vector<int> vis;
vector<vector<int> > adj;
vector<int> s;
int ff;
//hash 0 -> A

void dfs(int u)
{
	vis[u] = ff;
	for(int i=0;i < adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if(vis[v] == 0)
			dfs(v);
	}
}

int main()
{
	int TC;
	string str;
	scanf("%d", &TC);
	while(TC--)
	{
		ff = 0;
		vis.assign(53,0);
		adj = vector<vector<int> >(53);
		s.clear();
		while(cin>>str && str[0] != '*')
		{
			int a = str[1] - 'A';
			int b = str[3] - 'A';
			if(str[1] - 'a' >= 0) a = str[1] - 'a' + 26;
			if(str[3] - 'a' >= 0) b = str[3] - 'a' + 26;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cin>>str;
		int sz = str.size();
		for(int i=0;i<sz;i += 2)
		{
			int k = str[i] - 'A';
			if(str[i] - 'a' >= 0) k = str[i] - 'a' + 26;
			s.push_back(k);
		}
		for(int i=0;i<s.size();++i)
		{
			int k = s[i];
			if( vis[k] == 0 )
			{
				++ff;
				dfs(k);
			}
		}
		int acorn = 0, tree = 0;
		for(int i=1;i<=ff;++i)
		{
			int k = 0;
			for(int j=0;j<53;++j)
			{
				if(vis[j] == i)
				{
					++k;
				}
			}
			if(k == 1) ++acorn;
			else if (k > 1) ++tree;
		}
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}
}
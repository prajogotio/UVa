#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int awake[27];
vector<vector<int> > adj;
vector<int> stack;

int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M) != EOF)
	{
		//printf("%d %d\n", N, M);
		adj = vector<vector<int> >(27);
		stack.clear();
		int years = -1;
		int awaken = 3;
		for(int i=0;i<27;++i) awake[i] = 0;
		char a,b,c;
		scanf(" %c%c%c", &a,&b,&c);
		//printf("%c %c %c\n", a, b, c);
		
		awake[a-'A'] = 1; awake[b-'A'] = 1; awake[c-'A'] = 1;
		
		for(int i=0;i<M;++i)
		{
			scanf(" %c%c", &a,&b);
			//printf("%c %c\n", a, b);
			
			adj[a-'A'].push_back(b-'A');
			adj[b-'A'].push_back(a-'A');
			
		}
		
		for(int k=0;k<26; ++k)
		{
			//MUST CHECK INDEX CAREFULLY!!!!
			for(int i=0;i<=25;++i)
			{
				if(awake[i] == 0)
				{
					int neigh = 0;
					for(int j=0;j<adj[i].size(); ++j)
					{
						if(awake[adj[i][j]] == 1)
							++neigh;
					}
					if(neigh >= 3)
					{
						stack.push_back(i);
						++awaken;
					}
				}
			}
			if(awaken >= N)
			{
				years = k+1;
				break;
			} 
			else 
			{
				while(!stack.empty())
				{
					awake[stack.back()] = 1;
					stack.pop_back();
				}
			}
		}
		if (N == 3) printf("WAKE UP IN, 0, YEARS\n");
		else if(years == -1) printf("THIS BRAIN NEVER WAKES UP\n");
		else printf("WAKE UP IN, %d, YEARS\n", years);
	}
	return 0;
}

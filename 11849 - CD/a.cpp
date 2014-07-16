#include <set>
#include <cstdio>
#include <iostream>
using namespace std;
set<int> s;

int main()
{
	int N,M;
	while(scanf("%d %d",&N,&M), N != 0 || M != 0)
	{
		s.clear();
		int j;
		while(N--)
		{
			scanf("%d", &j);
			s.insert(j);
		}
		int k=0;
		while(M--)
		{
			scanf("%d",&j);
			if(s.find(j) != s.end() )
			{
				++k;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
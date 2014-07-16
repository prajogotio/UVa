#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int N;
	while(scanf("%d",&N), N!=0)
	{
		while(1)
		{
			vector<int> v,p;
			int k=N,w;
			while(k--)
			{
				scanf("%d",&w);
				if(w==0)break;
				v.push_back(w);
			}

			if(v.empty())break;

			k=N;
			while(k && !v.empty())
			{
				p.push_back(v.back());
				v.pop_back();
				while(p.back() == k && !p.empty())
				{
					p.pop_back();
					--k;
				}
			}
			if (p.empty() && v.empty())
				printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
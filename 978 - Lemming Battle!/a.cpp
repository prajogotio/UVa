#include <set>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
multiset<int> green;
multiset<int> blue;
multiset<int>::iterator it;
multiset<int>::reverse_iterator rit;
vector<int> sgreen;
vector<int> sblue;

int main()
{
	int TC;
	cin>>TC;
	for(int T=1;T<=TC; ++T)
	{
		if(T!= 1) printf("\n");
		green.clear(); blue.clear(); sgreen.clear(); sblue.clear();

		int B,SG,SB;
		scanf("%d %d %d",&B,&SG,&SB);
		for(int i=0;i<SG;++i)
		{
			int nG;
			scanf("%d",&nG);
			green.insert(nG);
		}
		for(int i=0;i<SB;++i)
		{
			int nB;
			scanf("%d",&nB);
			blue.insert(nB);
		}
		while(!green.empty() || !blue.empty())
		{
			if(green.empty())
			{
				printf("blue wins\n");
				for(rit = blue.rbegin(); rit != blue.rend(); ++rit)
				{
					printf("%d\n", *rit);
				}
				break;
			} 
			if(blue.empty())
			{
				printf("green wins\n");
				for(rit = green.rbegin(); rit != green.rend(); ++rit)
				{
					printf("%d\n", *rit);
				}
				break;
			}
			for(int i=0;i<B;++i)
			{
				if(!green.empty())
				{
					rit = green.rbegin();
					sgreen.push_back(*rit);
					green.erase(--rit.base());
				}
				if(!blue.empty())
				{
					rit = blue.rbegin();
					sblue.push_back(*rit);
					blue.erase(--rit.base());
				}
			}
			for(int i=0;i<B;++i)
			{
				int nG=0,nB=0;
				if(!sgreen.empty())
				{
					nG = sgreen.front();
					sgreen.erase(sgreen.begin());
				}
				if(!sblue.empty())
				{
					nB = sblue.front();
					sblue.erase(sblue.begin());
				}
				if(nG==nB) continue;
				if(nG > nB) green.insert(nG-nB);
				else blue.insert(nB-nG);
			}
		}
		if(green.empty() && blue.empty())
			printf("green and blue died\n");
	}
	return 0;
}
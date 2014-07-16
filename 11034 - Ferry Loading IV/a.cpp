#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<int> q[2];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int L,M;
		scanf("%d%d",&L,&M);
		L=L*100;
		for(int i=0;i<M;++i)
		{
			int B;
			string str;
			scanf("%d",&B);
			cin>>str;
			if(str == "left")
			{
				q[0].push(B);
			} else {
				q[1].push(B);
			}
		}

		int s = 0;
		int onship=0;
		int cross=0;
		while(!q[0].empty() || !q[1].empty())
		{
			onship = 0;
			while(!q[s].empty() && onship<=L)
			{
				if(q[s].front() + onship <=L)
				{
					onship+=q[s].front();
					q[s].pop();
				} else {
					break;
				}
			}
			s = (s+1)%2;
			++cross;
		}
		printf("%d\n",cross);
	}
	return 0;
}
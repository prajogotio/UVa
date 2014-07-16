#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> mp;
map<int,int>::iterator it;

int main()
{
	int TC;
	scanf("%d",&TC);
	while(TC--)
	{
		mp.clear();
		int N;
		scanf("%d",&N);
		//printf("new test : %d\n",N);
		int pos = 0;
		int lastpos=0;
		int max = 0;
		while(pos <= N)
		{
			if(pos == N)
			{
				//printf("%d %d\n",pos,lastpos);
				int temp = pos - lastpos;
				if(temp > max) max = temp;
				break;
			}
			int key;
			scanf("%d",&key);
			if((it = mp.find(key)) != mp.end())
			{
				//printf("%d %d\n",pos,lastpos);
				if(it -> second < lastpos){
					mp[key] = pos;
					++pos;
					continue;
				}
				int temp = pos - lastpos;
				if(temp>max) max = temp;
				lastpos = it->second + 1;
				mp[key] = pos;
			}
			else
				mp[key] = pos;
			++pos;
		}
		printf("%d\n",max);
	}
	return 0;
}
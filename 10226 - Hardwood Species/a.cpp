#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string,int> mp;

int main()
{
	int TC;
	scanf("%d",&TC);
	getchar(); getchar();
	bool flag=false;
	while(TC--)
	{
		if(flag) printf("\n");
		mp.clear();
		string str;
		int tot=0;
		while(getline(cin,str))
		{
			if(str.size() == 0)break;
			++mp[str];
			++tot;
		}
		map<string,int>::iterator it;
		for(it=mp.begin();it!=mp.end();++it)
		{
			cout<<it->first;
			printf(" %.4lf", double(it->second) / double(tot) * 100L );
			printf("\n");
		}
		flag = true;
	}
	return 0;
}
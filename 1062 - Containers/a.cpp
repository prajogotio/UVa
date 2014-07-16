#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	int T=1;
	while(cin>>str, str!="end")
	{
		int a[27] = {0};
		int v[27] = {0};
		int w[27] = {0}, st=0;
		int p[1009] = {0};
		int lim = str.size();
		for(int i=0;i<lim;++i)
		{
			//1 indexed
			int k = str[i] - 'A' + 1;
			++a[k];
			p[i] = k;
		}
		for(int i=0;i<lim;++i)
		{
			int k = p[i];
			//can p[i] put it on top?
			bool old_stack=false;
			bool on_stack = false;
			for(int j=1;j<=st;++j)
			{
				if(w[j] >= k)
				{
					w[j] = k;
					on_stack = true;
					break;
				}
			}
			for(int j=k+1;j<=26;++j)
			{
				if( v[j] >= k && a[j] == 0)
				{
					v[j] = k;
					--a[k];
					old_stack =true;
					break;
				}
			}
			if(!on_stack)
			{
				w[++st] = k;
			}
			if(!old_stack)
			{
				v[k] = k;
				--a[k];
			}
		}
		int tot = 0;
		for(int i=1;i<=26;++i)
		{
			if(v[i] > 0)
				++tot;
		}

		tot = min(tot,st);
		printf("Case %d: %d\n", T++,tot);
	}
	return 0;
}
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

vector<int> p;
int findset(int i) { return (p[i] == i) ? i : (p[i] = findset(p[i])); }
int main()
{
	int TC;
	char str[1000];
	scanf("%d",&TC);
	bool flag = false;
	while(TC--)
	{
		if(flag) printf("\n");
		int C,a,b,N1 = 0, N2 = 0;
		scanf("%d", &C);
		getchar();
		p = vector<int>(C+1,0);
		for(int i=1;i<=C;++i)
		{
			p[i] = i;
		}
		while(fgets(str, 998, stdin))
		{
			if(strlen(str) == 1) break;
			if(str[0] == 'c')
			{
				sscanf(str, "c %d %d", &a, &b);
				p[findset(a)] = findset(b);
			}
			else
			{
				sscanf(str, "q %d %d", &a,&b);
				if(findset(a) == findset(b))
					++N1;
				else
					++N2;
			}
		}
		printf("%d,%d\n", N1,N2);
		flag = true;
	}
	return 0;
}
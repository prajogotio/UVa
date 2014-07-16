#include <cstdio>

int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while(a!=0 || b!=0 || c!=0 || d!=0){
		int R=1080;
		R+=(a-b)*9;
		if(a<b)R+=360;
		R+=(c-b)*9;
		if(c<b)R+=360;
		R+=(c-d)*9;
		if(c<d)R+=360;
		printf("%d\n",R);
		scanf("%d%d%d%d",&a,&b,&c,&d);
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define CASES 1000

int main(){
   int caseno;
   int n,p,w,g,mw;
   int i;
   
   printf("%d\n",CASES);
   for(caseno=1;caseno<=CASES;caseno++){
      n=1+rand()%10;
      printf("%d\n",n);
      for(i=0;i<n;i++){
         p=1+rand()%100;
         w=1+rand()%30;
         printf("%d %d\n",p,w);
         }
      g=1+rand()%5;
      printf("%d\n",g);
      for(i=0;i<g;i++){
         mw=1+rand()%30;
         printf("%d\n",mw);
         }
      }
   return 0;
   }
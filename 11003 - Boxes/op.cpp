#include <cstdio>
#include <cstdlib>

int main(){
    int a,b;
    for(int i=0;i<10;++i){
        printf("1000\n");
        for(int i=0;i<1000;++i){
            a = (rand())%2999 + 1;
            b = (rand())%2999 + 1;
            printf("%d %d\n", a,b);
        }
    }
    printf("0\n");
    return 0;
}
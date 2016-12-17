#include <stdio.h>
#include <string.h>
#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int z,i,m,l;
/**
Algorithme classique de detection de cycle
**/
int fonction(int x){
    return ((z*x+i)%m);
}

int main(){
    int cas=1;
    while(scanf("%d %d %d %d",&z,&i,&m,&l)==4 && (z || i || m || l )){
        int tortoise=fonction(l);
        int hare=fonction(fonction(l));
        while(tortoise != hare){
            tortoise=fonction(tortoise);
            hare=fonction(fonction(hare));
        }


        int mu=0;
        hare=tortoise;
        tortoise=l;
        while(tortoise!= hare){tortoise=fonction(tortoise);hare=fonction(hare); mu+=1;}
   int lambda=1;
   hare=fonction(tortoise);
   while(tortoise != hare){ hare=fonction(hare); lambda+=1;}
    printf("Case %d: %d\n",cas++,lambda);
    }

return 0;
}

#include<cstdio>
#include<iostream>
/**
As Manuel wants to get rich fast and without too much work, he decided to make a career in gambling.
Initially, he plans to study the gains and losses of players, so that, he can identify patterns of consecutive
wins and elaborate a win-win strategy. But Manuel, as smart as he thinks he is, does not know how to
program computers. So he hired you to write programs that will assist him in elaborating his strategy.
Your first task is to write a program that identifies the maximum possible gain out of a sequence of
bets. A bet is an amount of money and is either winning (and this is recorded as a positive value), or
losing (and this is recorded as a negative value)

Maximal Sous-Chaine
Pareil que jill Rides Again en plus simple
Les constantes ne sont pas explicites, elle sont issues de Jill Rides Again
**/
int main(){
    int s,maximum,n;
    int route,routecompteur(1),nbstop,i;
    while(scanf("%d",&route)==1 && route){
        i=0;
        int arrai[route+1];
        n=route;
        while(route--)
            scanf("%d",&arrai[i++]);

        s=maximum=arrai[0];
        for(int i(1);i<n;i++){
            if(s>=0) s+=arrai[i];
            else
                s=arrai[i];

            if(s>maximum)
                maximum=s;

        }
        if(maximum<=0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",maximum);
        }

}

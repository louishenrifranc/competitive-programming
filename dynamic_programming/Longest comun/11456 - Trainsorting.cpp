#include<stdio.h>
#include<string.h>
int max(int a,int b){
return (a>b)? a:b;

}
/**
Erin is an engineer.  She drives trains.  She also arranges the cars within each train.  She prefers to
put the cars in decreasing order of weight, with the heaviest car at the front of the train.
Unfortunately, sorting train cars is not easy. One cannot simply pick up a car and place it somewhere
else.  It is impractical to insert a car within an existing train.  A car may only be added to the beginning
and end of the train.
Cars arrive at the train station in a predetermined order.  When each car arrives, Erin can add it
to the beginning or end of her train, or refuse to add it at all.  The resulting train should be as long as
possible, but the cars within it must be ordered by weight.
Given the weights of the cars in the order in which they arrive, what is the longest train that Erin
can make?

Longest Increasing Sorting + Longest Decreasing Sort -1
Voir que pour un indice i si l'on somme LIS + LDS -1 on obtient le nombre de voitures qui ont pu etre ajoutés
Il suffit de chercher le maximum parmi tous les indices
5 20 25 4 7 8 3 10

3  3  3 2 2 2 1  1 LIS
4  2  1 4 3 2 2  1 LDS
**/



int LIS[2002];
int LDS[2002];

int main(){
    register int n,car;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&car);
        int t[car+2];
        t[0]=0;
        for(int i(1);i<=car;i++) scanf("%d",&t[i]);

        LDS[0]=LIS[0]=0;
        LIS[car]=LDS[car]=1;
        int maxIncrease,maxDecrease;
        for(int i(car-1);i>0;i--){
            maxIncrease=maxDecrease=1;
            for(int j(car);j>i;j--){
                if(t[j]<t[i])
            maxIncrease=max(maxIncrease,1+LIS[j]);
                if(t[j]>t[i])
            maxDecrease=max(maxDecrease,1+LDS[j]);
            }
            LIS[i]=maxIncrease; LDS[i]=maxDecrease;
-+        }
        maxIncrease=1;
        for(int i(1);i<=car;i++){
            if(maxIncrease< LIS[i] + LDS[i] ) maxIncrease=LIS[i]+LDS[i];

        }
        printf("%d\n",maxIncrease-1);
    }
return 0;
}


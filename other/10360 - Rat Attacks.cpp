#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
/**

Baaaam! Another deadly gas bomb explodes in Manhattan's underworld. Rats have taken over the
sewerage and the city council is doing everything to get the rat population under control.
As you know, Manhattan is organized in a regular fashion with streets and avenues arranged like
a rectangular grid. Waste water drains run beneath the streets in the same arrangement and the rats
have always set up their nests below street intersections. The only viable method to extinguish them
is to use gas bombs like the one which has just exploded. However, gas bombs are not only dangerous
for rats. The skyscrapers above the explosion point have to be evacuated in advance and so the point
of rat attack must be chosen very carefully.
The gas bombs used are built by a company called American Catastrophe Management (ACM) and
they are sold under the heading of smart rat gas".

Pensez autrement
Plutot que d'essayer tous les points du tableau et de calculer les distance à toutes les colonies de rat
On part des colonies de rat !!
200x plus rapide

**/
int memo[1025][1025];   // memo[i][j] : taille des colonies de rats elimines si on met une bombe a cette place



int main(){
int cas,d,n,maxi,x1,y1;
scanf("%d",&cas);
while(cas--){
    scanf("%d %d",&d,&n);
    int x[n],y[n],taille[n];

    for(int i(0);i<n;i++) cin>> x[i]>>y[i]>>taille[i];
    memset(memo,0,sizeof (memo));   // Initialise le tapleau

    for(int u(0);u<n;u++){
        for(int i(0);i<=d;i++){
                for(int j(0);j<=d;j++){
                    /**
                    Les conditions permettent d'eviter de compter double
                    &
                    De sortir du tableau
                    **/
                    if(i==0 && j== 0) memo[x[u]][y[u]]+=taille[u];

                    else{
                    if(!(x[u]+i>1024|| y[u]+j>1024) && i!=0  && j!=0 ) memo[x[u]+i][y[u]+j]+=taille[u];
                    if(!(x[u]+i>1024|| y[u]-j<0) && i!=0  )    memo[x[u]+i][y[u]-j]+=taille[u];
                    if(!(x[u]-i<0|| y[u]+j>1024) && j!=0 )memo[x[u]-i][y[u]+j]+=taille[u];
                    if(!(x[u]-i<0|| y[u]-j<0)  )memo[x[u]-i][y[u]-j]+=taille[u];
                    }
                    }

            }
        }
        /**
        On recherche le maxi qui possede les plus petites coordonnes
        **/
        maxi=-1000;
        for(int i(1024);i>=0;i--){
            for(int j(1024);j>=0;j--){
            if(maxi<=memo[i][j]){
                    maxi=memo[i][j];
                    x1=i;
                    y1=j;
            }
            }
        }
        printf("%d %d %d\n",x1,y1,maxi);
    }
    return 0;
}



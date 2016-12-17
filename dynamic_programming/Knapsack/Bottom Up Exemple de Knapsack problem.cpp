#include<cstdio>
#include<sstream>
#include<string>
#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

/**
Algorithme naif recursif est en 2^n avec n le nombre d'elements
Algorithme dp bottom up en n*w avec w le poids max

utilise le naif pour des petites valeurs de n et grande de w



      V  60      100         120
      W  30      20          30

                poids W=50          Pour le resultat 50(poids)-3(indice) on choisit entre 160 et 100+120 ce qui correspond
                                    a la ligne  max (valeur[i-1]+memo[i-1][w-valeur[i-1]],memo[i-1][w])

                   50 -3               ( Soit on prend le nombre soit on le prend pas )
                /         \
               /           \
    100 == 20 - 2        50 - 2  160 si w > 20
          /     \           /    \
         /       \         /      \
     0 - 1    0==20 -1   30 - 1  50- 1  si w <30 ==0 sinon =60
                  /\        /\       / \
                 /  \      /  \     /   \
               0-0 20-0   0-0 30-0 20-0  50-0 == 0 tous
**



Pour retrouver les elements on renverse l'equation:  memo[i][w]=max(valeur[i-1]+memo[i-1][w-wt[i-1]],memo[i-1][w]);

Si memo[i][w]-memo[i-1][w-wt[i-1]]== valeur[i-1] alors i--, w-=wt[i-1] sinon i--;

/**
Dynamic One
**/
int knapsackDP(int n,const int wt[],const int valeur[],int W)
{

    int memo[n+1][W+1];
    for(int i(0); i<=n; i++)
    {
        for(int w(0); w<=W; w++)
        {
            if(w==0 || i==0)
                memo[i][w]=0;
            else if(wt[i-1]<=w)
                memo[i][w]=max(valeur[i-1]+memo[i-1][w-wt[i-1]],memo[i-1][w]);
            else
                memo[i][w]=memo[i-1][w];

        }
    }
    return memo[n][W];
}

/**
* Recursif
**/
int knapsackRecursif(int n,int wt[],int valeur[],int W)
{

    int resultat;
    if(n==0 || W == 0) return 0;
    else if(wt[n-1]>W) return knapsackRecursif(n-1,wt,valeur,W);
    else return max(valeur[n-1]+knapsackRecursif(n-1,wt,valeur,W-wt[n-1]),knapsackRecursif(n-1,wt,valeur,W));


}


int main()
{
    int poids[]= {20,20,30};
    int valeur[]= {60,100,40};
    int sacados=50;
    int n=sizeof(valeur)/sizeof(valeur[0]);
    cout <<knapsackDP(n,poids,valeur,sacados);
    cout <<knapsackRecursif(n,poids,valeur,sacados);

}

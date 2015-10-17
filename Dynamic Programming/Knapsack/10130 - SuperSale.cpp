#include<cstdio>
#include<sstream>
#include<string>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

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




int main()
{
    int cas,objet,personne;

    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&objet);
        int prix[objet];
        int poids[objet];
        for(int i(0); i<objet; i++)
        {
            scanf("%d %d",&prix[i],&poids[i]);
        }
        scanf("%d",&personne);
        int capacite(0),buffer;
        for(int i(0); i<personne; i++)
        {
            scanf("%d",&buffer);
            capacite+=knapsackDP(objet,poids,prix,buffer);

        }
        printf("%d\n",capacite);
    }

    return 0;
}

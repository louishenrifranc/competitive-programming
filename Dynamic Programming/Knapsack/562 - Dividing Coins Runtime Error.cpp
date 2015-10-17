#include<cstdio>
#include<sstream>
#include<string>
#include<iostream>
#include<cstdlib>
using namespace std;
/**
Not commonly known is that the fighting started, after the two Dutch tried to divide a bag with coins between
the two of them. The contents of the bag appeared not to be equally divisible. The Dutch of the past couldn't
stand the fact that a division should favour one of them and they always wanted a fair share to the very last
cent. Nowadays fighting over a single cent will not be seen anymore, but being capable of making an equal division
 as fair as possible is something that will remain important forever...
That's what this whole problem is about. Not everyone is capable of seeing instantly what's the most fair division
of a bag of coins between two persons. Your help is asked to solve this problem.
Given a bag with a maximum of 100 coins, determine the most fair division between two persons.
This means that the difference between the amount each person obtains should be minimised.
The value of a coin varies from 1 cent to 500 cents. It's not allowed to split a single coin.


Get Runtime Error J'ai utilise l'algo de Knapsack en passant comme poids et comme valeur la valeur des coins
**/

int knapsackDP(int n, int wt[], int valeur[],int W)
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
   int cas,piece,n;
   int i,resultat;
   scanf("%d",&cas);
   while(cas--){
    scanf("%d",&piece);
    n=piece;
    i=resultat=0;
    int tableau[piece]; /**!!!**/
    for(int j(0);j<piece;j++){
        scanf("%d",&tableau[i++]);
        resultat+=tableau[i-1];
    }
    int milieu=resultat/2;
    printf("%d\n", resultat-2*knapsackDP(n,tableau,tableau,milieu));    /** Retourne  somme - 2*valeurmax trouve par knapsack **/
   }
   return 0;
}

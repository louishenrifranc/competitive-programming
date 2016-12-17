#include<cstdio>
#include<sstream>
#include<string>
#include<iostream>
#include<cstdlib>
#include<cstring>
/**
Plongeur va cherché plusieurs tresors , avec une bombonne d'air limité

Knapsack variante ou il faut retourner aussi les elements que l'on a choisit parmi la liste
Pour un element i donne je met dans un tableau de bool a la place [valeur de l'element i][choix i]= true
    Sachant que [][1] veut donc que l'on s'occupe de savoir si l'on prend l'element 2 de la liste

        si on a decide de le prendre (voir la ligne de comparaions ***

Algorithme de Knapsack + recherche des elements choisis

**/
using namespace std;
int main()
{
    int air,w,piece,n;
    int q=0;
    while(scanf("%d %d",&air,&w) == 2)
    {   if(q) putchar('\n');
        q=1;
        scanf("%d",&n);
        int profondeur[n+1];
        int valeur[n+1];
        for(int i(0); i<n; i++)
        {
            scanf("%d %d",&profondeur[i],&valeur[i]);
        }

        // VOir enoncé
        int wt[n+1];
        for(int i(0); i<n; i++) wt[i]=profondeur[i]*3*w; // 2w pour la descente et 1 w pour la remontée ou l'inverse

        int memo[n+1][air+1];
        // Algo de Knapsack
        for(int i(0); i<=n; i++)        // Pour tous les elements dans le tableau
        {
            for(int w(0); w<=air; w++)        // Pour tous les poids possibles
            {
                if(w==0 || i==0)            // On initialise memo a 0

                    memo[i][w]=0;
                else if(wt[i-1]<=w)
                {

                    memo[i][w]=max(valeur[i-1]+memo[i-1][w-wt[i-1]],memo[i-1][w]);

                }
                else
                    memo[i][w]=memo[i-1][w];

            }
        }


        int kapa=memo[n][air]; // Nombre de gold ramassé

        if(kapa>0)                      // SI on a pu remonté au moins un tresor
        {
            printf("%d\n",kapa);
            int i=n;
            int tresors[n];
            int nbtresor(0);
            while(i>0)
            {       /** Recherche des elements choisis **/
                if(air-wt[i-1]>=0 && memo[i][air]-memo[i-1][air-wt[i-1]] == valeur[i-1])
                {
                    tresors[nbtresor++]=i-1;
                    air-=wt[i-1];
                    i--;
                }
                else i--;
            }
            printf("%d\n",nbtresor);
            for(int i(nbtresor-1); i>=0; i--)
            {
                printf("%d %d\n",profondeur[tresors[i]],valeur[tresors[i]]);


            }
        }
        else printf("0\n0\n");

    }


    return 0;
}

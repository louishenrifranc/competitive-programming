#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#include<string.h>
int INF =100;
/**
Classic Bellman Ford Algorithm
Sommer tous les chemins possibles depuis tous les noeuds

Graphe direct,connecte,sans poids

De la forme :
 1 2   3 4  4 1   3 2  0 0
 0 0
**/

int min(int a,int b){return(a<b) ? a: b;}
using namespace std;

int tableau[101][101];
map<int,int> noeud;
int main()
{
    int a,b,paire,n,cas(0);
    while(true)
    {   noeud.clear();
        paire=n=0;

        for(int i(0);i<101;i++) for(int j(0);j<101;j++) tableau[i][j]=100000; // J'ai eu une etrange surprise avec les memset
        // Lit les deux nombres
        scanf("%d %d",&a,&b);

        if(!a && !b) break; // Pour arreter l'algo
        // Les noeuds ne sont numerotés de 1 à n
        if(! noeud.count(a))
        {
            noeud[a]=n++;;
        }


        if(! noeud.count(b))
        {
            noeud[b]=n++;
        }

        tableau[noeud[a]][ noeud[b] ]=1; paire++;


        while(true)
        {
            scanf("%d %d",&a,&b);
            if( !a && !b ) break;   // Pour arreter la lecture du cas
            if(! noeud.count(a))
            {
                noeud[a]=n++;;
            }
            if(! noeud.count(b))
            {
                noeud[b]=n++;
            }

            tableau[noeud[a]][ noeud[b] ]=1; paire++;
        }
        // Bellman Ford
        int res(0);
        for(int k(0);k<n;k++){
            for(int i(0);i<n;i++){
                for(int j(0);j<n;j++){
                    tableau[i][j]=min(tableau[i][j],tableau[i][k]+tableau[k][j]);
                }
            }
        }
        // SOmme des differentes longueurs
       for(int i(0);i<n;i++){
            for(int j(0);j<n;j++)  if(i!=j) res+=tableau[i][j];
        }
        // Division par le nombre de lien possible
        printf("Case %d: average length between pages = %.3f clicks\n",++cas,(double) res/ (n*(n-1)) );
        }

}

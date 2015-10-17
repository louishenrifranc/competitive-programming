#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#include<string.h>
/**
Bellman Ford Algorithm ( All-Pairs Shortest Path )

Etant donner un graphe indirect,sans poids trouve le temps qu'il faut a PLUSIEURS EQUIPE qui peuvent se séparer, pour parcourir tous les noeuds du
graphe d'un point de départ à un point d'arrivée donnée

On réalise Bellman Ford puis on recherche la distance max dans la matrice : distance a à i + distance de i a b pour tous les i
**/

int max(int a,int b){return(a>b) ? a: b;}
using namespace std;

int tableau[101][101];
map<int,int> noeud;
int main()
{
    int a,b,paire,m,n,cas(0);
    scanf("%d",&cas);
    for(int y(0);y<cas;y++){
        scanf("%d\n%d",&n,&m);

        for(int i(0);i<n;i++) for(int j(0);j<n;j++) tableau[i][j]=1000000;

        for(int i(0);i<m;i++){scanf("%d %d",&a,&b);

        tableau[a][b]=1;tableau[b][a]=1;}
        scanf("%d %d",&a,&b);

        // Bellman Ford
        int res(0);
        for(int k(0);k<n;k++){
            for(int i(0);i<n;i++){
                for(int j(0);j<n;j++){
                    tableau[i][j]=min(tableau[i][j],tableau[i][k]+tableau[k][j]);
                }
            }
        }
        for(int i(0);i<n;i++){
            tableau[i][i]=0;
            res=max(tableau[a][i]+tableau[i][b],res);
        }
        // SOmme des differentes longueurs

            printf("Case %d: %d\n",y+1,res);

}
}

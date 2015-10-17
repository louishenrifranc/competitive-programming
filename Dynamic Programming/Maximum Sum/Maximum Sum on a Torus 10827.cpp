#include <cstdio>
#include <vector>
#include<algorithm>
#include<cstdlib>
#include<string.h>
#define for(i,a,b) for(int i(a);i<b;i++)
using namespace std;
/**
A grid that wraps both horizontally and vertically is called a torus.
Given a torus where each cell contains an integer, determine the
sub-rectangle with the largest sum. The sum of a sub-rectangle is
the sum of all the elements in that rectangle. The grid below shows
a torus where the maximum sub-rectangle has been shaded.

Probleme de Somme Maximal sur une matrice qui est comme une boule
Si ca taille est N*N On la copie dans une matrice 2N*2N comme ca on a tous les contacts possibles(haut, bas gauche,droite)
Ensuite quand on recherche le maximum sous rectangle, on fait attention a ne pas dépasser une dimension de n*n
O(n*4)
**/
int main() {
   int n,maxi,buffer,sum;
   int times;
   scanf("%d",&times);
   while(times--){
   scanf("%d",&n);

   int arrai[2*n+1][2*n+1];
        memset(arrai,0,sizeof(arrai));

        for(i,0,n){
            for(j,0,n){
                scanf("%d",&arrai[i][j]);
                arrai[i+n][j]=arrai[i][j+n]=arrai[i+n][j+n]=arrai[i][j];    // Copie dans la matrice 2n*2n
   }     }


   for(i,0,2*n){
    for(j,0,2*n){
        if(j>0) arrai[i][j]+=arrai[i][j-1];                         // On effectue la somme depuis le debut
                if(i>0) arrai[i][j]+=arrai[i-1][j];                 // pour l'algorithme en O(n*4)

                if(i>0 && j>0) arrai[i][j]-=arrai[i-1][j-1];        //
    }
   }
           maxi=-75*75*100;                                         // 75 lignes avant -100 comme plus petite valeur

    for(i,0,2*n){   /** i et j coordonnees de depart **/
            for(j,0,2*n) {
                for(k,i,min(2*n,i+n)){              /** k et l coordonnees d'arrivees a une distance n*n max de  (i,j) **/
                    for(l,j,min(2*n,j+n)){
                        sum=arrai[k][l];            // L'algo
                        if(i>0) sum-=arrai[i-1][l];
                        if(j>0) sum-=arrai[k][j-1];
                        if(i>0 && j>0) sum+=arrai[i-1][j-1];
                        if(maxi<sum) maxi=sum;
                    }
                }
            }
    }


    printf("%d\n",maxi);
   }
   return 0;
}

#include <cstdio>
#include <vector>
#include<algorithm>
#include<cstdlib>
#include<string.h>
#define for(i,a,b) for(int i(a);i<b;i++)
using namespace std;
/**
Given a 2-dimensional array of positive and negative integers, find the sub-rectangle with the largest sum.
The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle
with the largest sum is referred to as the maximal sub-rectangle. A sub-rectangle is any contiguous sub-array
of size  or greater located within the whole array. As an example, the maximal sub-rectangle
 of the array:

 Maximal Sum ( Competitive Programming 3)
 Algorithme O(n^4)
**/


int main() {
   int n,maxi,buffer,sum;
   scanf("%d",&n);

   int arrai[n+1][n+1];
        memset(arrai,0,sizeof(arrai));
        /** On enregistre les elements lu dans une matrice qui stocke la somme des elements avant celui lu
        Exemple si i=3 j=3 , a cette position sera la somme de tous les elements dans le rectangle superieur gauche
        Pour cela On lit de gauche a droite, de haut en bas
        Et si i>0 et j>0 , le chiffre correspondant a a cette position est la somme de celui d'au dessus
                                                                                    +
                                                                        celui a gauche
                                                                        -celui dans la diagonale au dessus a gauche
                                    **/
        for(i,0,n){
            for(j,0,n){
                scanf("%d",&arrai[i][j]);
                if(j>0) arrai[i][j]+=arrai[i][j-1];
                if(i>0) arrai[i][j]+=arrai[i-1][j];
                if(i>0 && j>0) arrai[i][j]-=arrai[i-1][j-1];
   }     }
           maxi=-127*100*100; /** 127 valeur minimal possible * nc * nl**/
           /** Recherche du maximum possible **/
           /** Algorithme en O(n^4)**/
    for(i,0,n){
            for(j,0,n) {
                for(k,i,n){
                    for(l,j,n){
                        sum=arrai[k][l]; /** Processus inverse de la lecture **/
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

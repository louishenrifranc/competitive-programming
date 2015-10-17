#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define INT_MAX 2147483647
#define INT_MIN -2147483647

using namespace std;
/**
The poor man went to the King and said, \Lord, I cannot maintain my family. Please give me some
wealth so that I can survive with my wife and children." The King replied, \I shall grant you a piece
of land so that you can cultivate and grow food for your family. In the southern part of the Kingdom
there is a rectangular forest. Trees have been planted there at regular intervals. Some of the trees have
been cut for use. You are allowed to take any rectangular piece of land that does not contain any tree.
You need not go to the forest to select the piece of land. I have a map containing 1's at places where
there is a tree and 0s at points where the tree has been cut."
Help the poor man to find out the largest piece of land. Area of the land is measured in units of
number of trees that were there. Your program should take a matrix of 1 and 0as input and output
the area of the largest rectangular piece of land that contain no tree. Be careful about the efficiency of
your program

O(n^3)

1 0 0 0                 1 0 0 0
0 1 1 1                 0 1 1 1
1 0 1 1                 1 0 2 2
1 0 0 0 transforme en   1 0 0 0 puis avec l'algo on recherche par ligne
**/
int main ()
{

    int a,b;
    int n,index;
    while(scanf("%d %d",&a,&b)==2 && a &&b){
     int arrai[a+1][b+1];

     for(int i(0);i<a;i++){
        for(int j(0);j<b;j++){
           scanf("%d",&index);

           index == 0? arrai[i][j]=1:arrai[i][j]=0; /** on recherche ici le plus grand sous rectangle compose de 0
                                                    Pour se conformer a l'algo, si l'on recoit 0 on met 1 et vice versa **/

            if(i>0)arrai[i][j]= arrai[i][j]==1 ? arrai[i-1][j]+1: 0;    /** Transformation**/


            **/
        }
     }
    int maxi = INT_MIN;
    for ( int i = 0; i < a; i++ ) {
         for ( int j = 0; j < b; j++ ) {
             int cnt = 1;                                                                   /**count demarre a 1   **/
             for ( int k = j - 1; k >= 0 && arrai [i] [k] >= arrai [i] [j]; k-- ) cnt++;    /** A gauche de la case tant que c'est superieur ou egale
             **/
             for ( int k = j + 1; k < b && arrai [i] [k] >= arrai [i] [j]; k++ ) cnt++;     /** a droite **/
                 cnt *= arrai [i] [j];                               /** On multiplie par la position de la case ( a essayer ca fonctionne **/
                if ( maxi < cnt ) maxi = cnt;
             }
        }

        printf ("%d\n", maxi);
    }

    return 0;
}

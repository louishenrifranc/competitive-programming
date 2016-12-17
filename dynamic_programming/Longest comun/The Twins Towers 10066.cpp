#include<iostream>
#include<stdio.h>
#include<math.h>
/**
Once upon a time, in an ancient Empire, there were two towers of dissimilar shapes in two different
cities. The towers were built by putting circular tiles one upon another. Each of the tiles was of the
same height and had integral radius. It is no wonder that though the two towers were of dissimilar
shape, they had many tiles in common.
However, more than thousand years after they were built, the Emperor ordered his architects to
remove some of the tiles from the two towers so that they have exactly the same shape and size, and
at the same time remain as high as possible. The order of the tiles in the new towers must remain the
same as they were in the original towers. The Emperor thought that, in this way the two towers might
be able to stand as the symbol of harmony and equality between the two cities. He decided to name
them the
Twin Towers
.
Now, about two thousand years later, you are challenged with an even simpler problem: given the
descriptions of two dissimilar towers you are asked only to nd out the number of tiles in the highest
twin towers that can be built from them.

PLus longue chaine commune LFS
**/

using namespace std;
int n1,n2,n(0);
int lcs( int *X, int *Y, int m, int n );

int main(){

    while(scanf("%d %d",&n1,&n2)==2 && n1 && n2){   // Size of the tower

    int tab1[n1+1],tab2[n2+1];
    for(int i(0);i<n1;i++) scanf("%d",&tab1[i]);    // Radius of the the tiles of tower 1
    for(int i(0);i<n2;i++) scanf("%d",&tab2[i]);    // ..
    n++;
    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",n,lcs(tab1,tab2,n1,n2));

}
}
/**
Longest commun string(or int or etc...)
**/
int lcs( int *X, int *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)

     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

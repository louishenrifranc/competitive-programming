#include<stdio.h>
#include<math.h>
#include<string>
#include<cstring>
using namespace  std;
/**
You have to cut a wood stick into pieces. The most affordable company, The Analog Cutting Machinery,
Inc. (ACM), charges money according to the length of the stick being cut. Their procedure of work
requires that they only make one cut at a time.
It is easy to notice that different selections in the order of cutting can led to different prices. For
example, consider a stick of length 10 meters that has to be cut at 2, 4 and 7 meters from one end.
There are several choices. One can be cutting first at 2, then at 4, then at 7. This leads to a price
of 10 + 8 + 6 = 24 because the first stick was of 10 meters, the resulting of 8 and the last one of 6.
Another choice could be cutting at 4, then at 2, then at 7. This would lead to a price of 10 + 4 + 6 =
20, which is a better price.
Your boss trusts your computer abilities to find out the minimum cost for cutting a given stick.

Optimal Cutting Trees
Bottom Up
*/
int arrai[53]={0};
int memo[53][53];
/**
left =index dans le tableau
right=index dans le tableau
**/
int cuttingstick(int left,int right)
{
    int coutt;
    if(left+1==right) return memo[left][right]=0;   // Si on a plus qu'un segment (un indice et celui au dessus
                                                       // alors le cout de coupe est nul

    if(memo[left][right]!=-1) return memo[left][right]; // Si on l'a déja calcule, on retourne sa valeur

    else
    {
        coutt=10000;                                // On definit un max

        for(int i(left+1); i<right; i++)
        {
            coutt=min(coutt,cuttingstick(left,i)+cuttingstick(i,right)+arrai[right]-arrai[left]); /** Essayer ca marche !! **/
        }               // 0 25 50 75 100  left=1 right=3 coutt : coup de 25/50 +coup de 50/75 + 75-25 a minimiser si left-right>3
            }
    return (memo[left][right]=coutt);   // Enregistre la valeur
}

int main()
{
    int l,cut;
    while(scanf("%d",&l)==1 && l)           // L taille du segment
    {   memset(memo,-1,sizeof(memo));       // Initialise le memo a -1
        scanf("%d",&cut);
        arrai[0]=0; // Met a 0 la premiere valeur du tableau
        for(int i(0); i<cut; i++)
        {
            scanf("%d",&arrai[i+1]);
        }

        arrai[cut+1]=l; // Met a L la derniere valeur du tableau
        printf("The minimum cutting is %d.\n",cuttingstick(0,cut+1));

    }


}

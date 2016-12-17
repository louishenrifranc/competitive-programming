#include<stdio.h>
/**
Given a range [a;b], you are to find the summation of all the odd integers in this range. For example,
the summation of all the odd integers in the range [3;9] is 3 + 5 + 7 + 9 = 24

Somme des termes d'une suite arithmetique
(n-p+1)*(u_p+u_n)/2

**/
int main()
{
    register int n,a,b;
    scanf("%d",&n);
    for(int i(0); i<n; i++)
    {
        scanf("%d %d",&a,&b);

        if(a!=b)                /** Si a != b **/
        {
            if(a%2==0) a++;     /** Si a est paire on incremente au nombre impaire superieur **/
            if(b%2==0) b--;     /** Si b est paire on ** inferieure **/

            int r1=   (a==b)? 1  :  (b-a)-( (b-a)>2 ? (b-a)/2 -1 :0);  /** Calcul loofoque qui marche pour trouver n-p+1**/
            printf("Case %d: %d\n",i+1,r1*(a+b)/2);                    /** (u_p+u_n)/2 * r1 **/
        }

        else{  if(a%2==0)                    /** Si a==b et a paire alors resultat =0 **/
                printf("Case %d: 0\n",i+1);
            else printf("Case %d: %d\n",i+1,a); /** Sinon egale a a **/
    }
    }
}

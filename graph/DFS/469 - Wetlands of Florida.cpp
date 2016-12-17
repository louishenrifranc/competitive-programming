#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iostream>
using namespace std;
/**
1

LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLWLWLLLL
LLLLLLLLL
3 2
 Trouver la largeur des lacs marques par un W

**/


bool t[105][105];
string s[105];
char input[100];
/** Variables globales **/
int n,m;
int resultat;

/**
Basic DFS avec enregistrement du nombre de W voisins**/
int dfs(int a,int b)
{

    t[a][b]=true;
    for(int i(-1); i<2; i++)
    {
        for(int j(-1); j<2; j++)
        {
            if( a+i>=0 &&  b+j>=0 && a+i<n && b+j<m && !t[a+i][b+j]  && !(j==0 && i==0)  )
                if(s[a+i][b+j]=='W')
                {
                    resultat++;
                    dfs(a+i,b+j);
                }
        }
    }
    return resultat;
}


int main()
{

    int n1,compt;
    string buffer;
    scanf("%d",&n1);
    getchar();
    getchar();
    /* Saisie compliquée de la forme:
                Nombre de cas
                Espace
                Matrice (dont on ne connait pas les dimensions
                Positions initiale du W appartenant au lac dont on recherche la dimension
                Espace
                Nouvelle matrice ...
                **/
    while(n1--)
    {


        compt=n=m=0;

        while(gets(input) && strlen(input)  >0) // Tant qu'on croise pas un espace
        {
            if(input[0]== 'L' || input[0] == 'W')   // Si on lit la matrice
            {

                s[compt++]=input;
                m=strlen(input);
                n++;

            }
            else                                    // Si on lit les positions
            {
                int a,b;
                resultat=0;
                for(int i(0); i<=n; i++) for(int j(0); j<=m; j++) t[i][j]=false;

                sscanf(input,"%d %d",&a,&b);        // Lit les coordonnees depuis la l'input
                printf("%d\n",dfs(a-1,b-1)+1);

            }

        }

    if(n1) putchar('\n');
    }
    return 0;
}

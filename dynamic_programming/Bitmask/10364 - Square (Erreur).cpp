#include <stdio.h>
#include <math.h>
#include<string.h>
#include<algorithm>
#include <functional>
using namespace std;

int t[21];
int memo[1<<20][2];
int bit_max;
int n;
int cote;
/**
Donner une suite de nombre, trouvez si il est possible de faire un carre en sommant les differents nombres de differentes
manieres
Mon programme fonctionne pour la majorite des cas, il cherche a former un carre, et des qu'il a reussi
        il appelle une fonction qui recherche un carre dans les elements restants

        NE marche pas pour ce cas la : 3 3 3 9 9 9 10 17 17 17 18 18 18 19 19 19 20 20
        Le probleme est qu'il est possible qu'avec l'arrangement des nombres,je n'arrive pas a trouver la longueur d'un carre
**/

bool fonction(int bitmask)
{
    if(bitmask == bit_max) return true;     // SI tous les elements on reussit a etre mis

    int sum,buffer(bitmask);
    for(int i(0); i<n; i++)
    {   sum=0;
        bitmask=buffer;                     //
        if(!(bitmask & (1<<i)))             // Si l'element n'est pas deja selectionne
        {
            if(sum+t[i]>cote){
                 i++;          //si i est superieur incremente
                continue;
            }
            if(sum+t[i] == cote )           // si on a reussit a trouver un carre
            {
                sum+=t[i];                  // Si j'ai trouve un element qui vaut exactement longueur carre
                                            // On recherche dans les elements restants a former un carre
                return  fonction(bitmask | (1<<i));

            }
            if(sum+t[i]<cote)
            {sum+=t[i];
             bitmask |=(1<<i);      // Si < a somme d'un carre, j'ajoute ce nombre
                 }                   /**
                                    Peut etre que l'ajout d'un mauvais nombre a chaque fois fait beuger
                                    **/
            for(int j(i+1); j<n; j++)
            {                           // Ensuite de i a n tant que je somme des nombres inferieur a longueur d'un cote
                                            // J'ajoute j

                if(!(bitmask & (1<<j)))
                {
                    if(sum+t[j]>cote){
                        j++;
                        continue;
                    }
                    if(sum+t[j] == cote )
                    {
                        sum+=t[j];
                        return fonction(bitmask  | 1<<j);       // Pareil que pour i
                    }
                    if(sum+t[j]<cote){

                     sum+=t[j];bitmask |= 1<<j;

                    }
                }

            }

        }
    }
    return false;   // Si j'ai pas reussi, je retourne false
}

int main()
{

    int cas;
    scanf("%d",&cas);

    while(cas--)
    {   memset(memo,false,sizeof(memo));
        cote=0;
        scanf("%d",&n);
        for(int i(0); i<n; i++)
        {
            scanf("%d",&t[i]);
            cote+=t[i];
        }
        if(cote %4 != 0) printf("no\n");
        else
        {
            cote/=4;
            bit_max=(1<<n)-1;
            sort(t,t+n);

            sort(t,t+n/2+1,greater<int>());
            if( fonction(0) ) printf("yes\n");
            else printf("no\n");
        }
    }
}

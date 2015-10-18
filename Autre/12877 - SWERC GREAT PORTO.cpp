#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
/**
    SWERC + GREAT + PORTO : Backtracking Problem
**/
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> iii;


pair<char,int> t[11];                       // Autant de paire que de lettres differentes, char est la lettre, et int est la valeur donné a
                                            // la lettre (celle qu'on fait varier)
                                            // L'indice du tableau n correspond a la nième lettre differentes dans les mots (jusqua 10 lettres /= )

int nombredelettrediff;                     // Le nombre lettre differente
int Equivalent[11][11];                     // Un tableau qui enregistre les equivalent en indice de chaque mot
int TailleMot[11];                          // La taille de chaque mot
int pris[11];                               // Pour le backtracking
int n;


int verification(){

    int resultat;
    for(int i(0);i<n;i++)
        if( t[Equivalent[i][TailleMot[i]-1]].second == 0) return 0;     // Le dernier chiffre equivalent de tous les mots ne doit pas etre 0 (
                                                                                                                    // le plus a gauche

    int retenu=0;

    for(int i(0);i<TailleMot[n-1];i++){                                  // Car c'est le plus grand
    resultat=retenu;
    for(int j(0);j<n-1;j++){                                            // Aditionne colonne par colonne
        resultat+=t[Equivalent[j][i]].second;                           // On ajoute les elements
    }
    if(resultat % 10 != t[Equivalent[n-1][i]].second) return 0;         // Si jamais la somme de colonne != colonne resultat exit
    retenu=resultat/10;                                                 // Sinon si il ya retenu, la rajoute pour la prochaine somme
    }

    if(retenu  == 0)    return 1;

return 0;
}


// Classic Backtracking
int backtracking(int nbrelettre){
int res=0;
if(nbrelettre == nombredelettrediff) return res+=verification();    // Renvoit 1 si le calcul est bon

for(int i(0);i<10;i++){
    if(pris[i] == 0){
    t[nbrelettre].second=i;                                         // La lettre d'indice nbrelettre vaut desormais i
    pris[i]=1;
    res+=backtracking(nbrelettre+1);
    pris[i]=0;

 }
}
return res;
}




int main(){
string buffer;
int maxlength;
while(scanf("%d",&n)==1){

    nombredelettrediff=maxlength=0;

    for(int i(0);i<11;i++){                         // Initialise le tableau avec des valeurs nulles (Mettre a 0 meme le 10 car dans les calculs de
                                                    // verification ca peut foirer
        t[i]=ii('.',0);
    }
    getchar();

    for(int i(0);i<n;i++){                             // Pour chaque mot

        getline(cin,buffer);

        TailleMot[i]=buffer.size();                     // Copie la taille du mot

        if(maxlength < TailleMot[i] )                   // Longueur max parmi les mots
            maxlength=TailleMot[i];

        int j;
        for(j=0;j<buffer.size();j++){                   // Remplit les tables d'equivalence char ->indice et le tableau Equivalent

            bool y=true;
            for(int k(0);k<nombredelettrediff;k++){
                if(t[k].first == buffer[j]){

                        Equivalent[i][TailleMot[i]-1-j]= k; /** Inverser l'ordre des mots (Premier caractere recu,dernier dans le calcul !!!!!!!!! **/
                        y=false;
                        break;
                }
               }

                if(y){
                    Equivalent[i][TailleMot[i]-1-j]=nombredelettrediff;

                    t[nombredelettrediff++].first=buffer[j];
                }
            }

            for(;j < 11;j++) Equivalent[i][j]=10;   // Remplit avec un 10 tout le reste
    }

 /*   for(int i(0);i<n;i++){
        for(int j(0);j<11;j++){
            printf("%d ",Equivalent[i][j]);
        }
        printf("\n");
    }
*/

       printf("%d\n",backtracking(0));





}
}

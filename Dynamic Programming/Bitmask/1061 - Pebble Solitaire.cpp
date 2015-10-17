#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int memo[1 << 12];

int resultat(int bimask){

if( memo[bimask]!=-1)
        return memo[bimask];

int r=0;
for(int i(2);i<12;i++){ /**
        Si on a 110 ou 001 alors on recherche le max entre r initialement a 0
            et 1 (1perle en moins) et la ligne avec les valeurs modifies
            **/
    if( (bimask & (1<< i-2))  && (bimask & (1<< i-1)) && !(bimask & (1<<i) )) r=max(r,1+resultat(bimask ^ 1<<i ^ 1<<i-1 ^ 1<<i-2));
    if( !(bimask & (1<< i-2))  && (bimask & (1<< i-1)) && (bimask & (1<<i)))  r=max(r,1+resultat(bimask ^ 1<<i ^ 1<<i-1 ^ 1<<i-2));
}

return memo[bimask]=r;      // Enregistre que pour ce nombre on a pu retirer au max r elements
}
int main(){

    int cas;

    int n,boule;
    char t[13];
    scanf("%d",&cas);
    getchar();
    memset(memo,-1,sizeof memo);
    while(cas--){
        n=boule=0;

        string buffer;
        getline(cin,buffer);    // Pour gerer des posssibles problemes avec les caracteres de retour a la ligne

        for(int i(0);i<12;i++){

           if( buffer[i] == 'o'){
                    n |= ( 1 << (11-i));
                    boule++;
           }

        }

           printf("%d\n",boule-resultat(n));    // Nombre de rond - nombre de rond retire


}
}

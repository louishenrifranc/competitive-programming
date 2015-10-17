#include<iostream>
#include<stdio.h>
/**
Calcul d'une somme de long chiffre
De la forme 4 5
            2 9 => Affiché 101
**/
int main(){

int nombre,n,a,b,j;
scanf("%d",&nombre);
while(nombre--){
    scanf("%d",&n);
    int tab[n+2];
    for(int i(1);i<=n;i++){
        scanf("%d %d",&a,&b);
        tab[i]=a+b;

    }
    for(int i(n);i>=1;i--){
        if(tab[i]>=10 ) {
                tab[i-1]+=tab[i]/10;
                tab[i]%=10;
        }
    }


    for(int i(1);i<=n;i++) printf("%d",tab[i]);
    putchar('\n');

    if(nombre!=0) putchar('\n');
}
}


#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


/**
LCM+ GCD ( dans le pacquet algorithm)
+Complete Search du LCM
Exemple pris :
4 2
50
100
200
400
1000
2000
4 : nombre de monnaies differentes,2 nombre de cas differents
On effectue un Complete Search sur toutes les valeurs, puis on calcule le plus grand commun multiple.
Pour trouver la taille minimale, on divise (division entiere) la hauteur voulue de la table par le LCM et l'on remultiplie
    par ce coefficient ENTIER trouvé
Pour trouver le maximum, on ajoute le LCM a la hauteur de la table -1 ( pour gerer les cas limites), et on effectue le meme calcul
    que au dessus
**/


int lcm(int a, int b){
    return a *( b/ __gcd(a,b) );
}

int main(){
    int n,t,coin[50],leg[10];

    while(true){
        scanf("%d %d",&n,&t);
        if(n == 0) break;

        for(int i = 0;i < n;++i) scanf("%d",&coin[i]);
        for(int i = 0;i < t;++i) scanf("%d",&leg[i]);

        int L[t],U[t];
        memset(L,-1,sizeof(L));
        memset(U,-1,sizeof(U));

        for(int i1 = 0;i1 < n;++i1){
            for(int i2 = i1 + 1;i2 < n;++i2){
                for(int i3 = i2 + 1;i3 < n;++i3){
                    for(int i4 = i3 + 1;i4 < n;++i4){
                        int x = lcm(coin[i1],lcm(coin[i2],lcm(coin[i3],coin[i4])));
                        // On recherche le LCM
                        for(int j = 0;j < t;++j){
                            // Par exemple dans notre exemple,le LCM est 400:
                            // et 1000 vaut 2.5 fois 400
                            // donc on divise (d'entier) 1000 par 400 : on obtient 2: on multiplie ensuite ce nombre par 400
                            int L2 = leg[j] / x * x;

                            int U2 = (leg[j] + x -1) / x * x;
                            // Par exemple dans notare cas le LCM est toujours 400
                            // et on prend comme hauteur 2000 :
                            //2399 /400 =5 alors que 2400 / 400 = 6 d'ou le -1
                            if(L[j] == -1 || L2 > L[j])
                                L[j] = L2;

                            if(U[j] == -1 || U2 < U[j])
                                U[j] = U2;
                        }
                    }
                }
            }
        }

        for(int i = 0;i < t;++i)
            printf("%d %d\n",L[i],U[i]);
    }

    return 0;
}





}

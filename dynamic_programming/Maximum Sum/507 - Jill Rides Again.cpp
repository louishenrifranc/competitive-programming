#include<cstdio>
#include<iostream>
/**

Probleme  Jill Rides Again 507

Recherche de la chaine maximale la plus longue consecutive
Utilisation de l'algorithme de recherche de la plus longue chaine consecutive (DP)
        Aucun tableau memo necessaire a chaque incrementation, seulement le dernier element calcule est interessant

Difficulte de l'algorithme : Il faut que le maximum soit le plus long possible,
Si l'on a deux chaines maximales de longueur égale, il faut vérifier laquelle  s'étend sur la plus longue distance
            s==maximum && i-t> max_end-max_start

     Sinon si elles sont strictement egales en tout point, on prend la premiere (d'ou l'inégalite stricte)

**/




int main(){
    int n,max_start,max_end, maximum,s,t;
    int route,routecompteur(1),nbstop,i;
    scanf("%d",&route);
    while(route--){     // Tant que il ya des routes
        scanf("%d",&nbstop);
        int arrai[nbstop];
        i=0;
        n=nbstop;
        while(--nbstop){
            scanf("%d",&arrai[i++]);

        }
        // Debut de l'algo de la chaine maximale

        s=maximum=arrai[0];
        t=max_start=max_end=0;
        for(int i(1);i<n-1;i++){

            if(s>=0) s+=arrai[i];  // Inegalite large: tant que la somme des elements n'est pas strictement negative !
            else{
                s=arrai[i];
                t=i;
            }
            if(s>maximum || (s==maximum && i-t> max_end-max_start) ){       /** Voir au debut (difficulté) **/
                max_start=t;
                max_end=i;
                maximum=s;
            }
        }
        if(maximum<=0) printf("Route %d has no nice parts\n",routecompteur++);
        else printf("The nicest part of route %d is between stops %d and %d\n",routecompteur++,max_start+1,max_end+2);
                                                            /** +1 et +2 : voir enoncé **/
        }

}

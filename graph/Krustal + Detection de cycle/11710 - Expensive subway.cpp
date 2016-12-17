#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<math.h>

/**
Arbre non oriente,avec poids,pas forcement complet

Classic Minimal Spanning Tree avec Krustal
Arret de l'algo quand on a N-1 liens (il y a N noeuds )
Affichage de impossible si l'on a pas réussi a arriver a N-1

Astuce : Donne un point de départ pour l'arbre mais en fait c'est inutile car ce qui nous interesse uniquement c'est de former l'arbre
            de N-1 Liens , dans ce cas la on relira forcemement le point de depart
**/
using namespace std;
priority_queue<pair<int, pair<int,int>   > > EdgeList;
int N,K,M,j;
int t[401];
map<string,int> W;

int findSet(int a)
{
    return ( t[a] ==a) ? a: findSet(t[a]);
}
void initSet(int X)
{
    for(int i(0); i<X; i++) t[i]=i;
}
bool sameSet(int a,int b)
{
    return findSet(a) == findSet(b);
}
void unionSet(int a,int b)
{
    t[findSet(a)] =  findSet(b);
}
int Kruskal()
{   j=0;
    int cost=0;
    initSet(N+1);

    while(!EdgeList.empty())
    {
        pair<int,pair<int,int> > fron = EdgeList.top();
        EdgeList.pop();
        if(!sameSet( fron.second.first,fron.second.second  ))
        {
            unionSet(fron.second.first,fron.second.second);
            cost+= -(fron.first) ;
            j++;
            if(j == N-1) break;
        }
    }

    return cost;

}

int main()
{

    int n(0),res;
    char buffer[11],buffer2[11];
    while(scanf("%d %d",&N,&M)==2 && (N || M )){
        n=0; W.clear();while(!EdgeList.empty()) EdgeList.pop();
        for(int i(0);i<N;i++){
            scanf("%s",buffer);
            W[buffer]=n++;
    }


    for(int i(0);i<M;i++){
        scanf("%s %s %d",buffer2,buffer,&n);
        EdgeList.push(pair<int,pair<int,int> >(-n,pair<int,int>(W[buffer2],W[buffer])));
    }
    scanf("%s",buffer2);
    res=Kruskal();

    if( j == N-1 ) printf("%d\n",res);
    else printf("Impossible\n");

}
return 0;
}

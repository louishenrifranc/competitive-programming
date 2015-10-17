#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
/**
Classic Krustal Minimum Spanning Tree
Detection de Cycle avec l'algo d'Union Set


Premierement on a deja un MST et il faut juste calculer son cout

Deuxiemement on a plein de liens et il faut calculer le cout du nouveau MST
**/
using namespace std;
priority_queue<pair<int, pair<int,int>   > > EdgeList;
int N,K,M;
int t[1000100];
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
{
    int nombreLiens(0);
    int cost=0;
    initSet(N+1);
    while(!EdgeList.empty())
    {
        pair<int, pair<int,int> > fron = EdgeList.top();
        EdgeList.pop();
        if(!sameSet( fron.second.first,fron.second.second  ))
        {
            unionSet(fron.second.first,fron.second.second);
            ++nombreLiens;
            if(nombreLiens == N-1) break ; // COndition de formation de l'arbre
            cost+= -(fron.first) ;

        }
    }
    return cost;

}

int main()
{
    int a,b,c;
    bool debut(false);
    while(scanf("%d",&N) == 1){
    while(!EdgeList.empty()) EdgeList.pop();

    if(debut) putchar('\n');
    debut=true;

    for(int i(0); i<N-1; i++)
    {

        scanf("%d %d %d",&a,&b,&c);
        EdgeList.push( make_pair(-c,make_pair(a-1,b-1) ) );
    }
    printf("%d\n",Kruskal());       /** Premier Cas **/
    while(!EdgeList.empty()) EdgeList.pop();

    scanf("%d", &K);
    for(int i(0); i<K; i++)
    {
        scanf("%d %d %d\n", &a, &b, &c);
        EdgeList.push(make_pair(-c, pair<int,int>(a-1, b-1)));
    }
    scanf("%d", &M);
    for(int i(0); i<M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        EdgeList.push(make_pair(-c, pair<int,int>(a-1, b-1)));
    }

    printf("%d\n", Kruskal());      /** Deuxieme Cas **/
    }
    return 0;
}

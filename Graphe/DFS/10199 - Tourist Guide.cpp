#include<stdio.h>
#include <string>
#include <algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<string.h>
#define MAX 105
using namespace std;
int G[MAX][MAX], V[MAX], L[MAX], n, m, gpe;
vector<int> vv;
int dfsRoot,rootChildren;


void dfs(int u, int v)
{
    V[v] = L[v] = ++gpe;
    for(int i = 0; i < n; i++)
    {

        if(G[v][i])     // SI il existe un lien
        {

            if(!V[i])   // SI on l'a pas encore visité i
            {
                if(v == dfsRoot) rootChildren++;
                dfs(v, i);
                L[v] = min(L[v], L[i]);

                 // Pour l'algo de recherche des bridges
                if(L[i] >= V[v])
                {
                    vv.push_back(v);
                }
                L[v] = min(L[v], L[i]);
            }
            else if(i != u)             // Cas particulier voir "deuxieme condition dan l'exemple ci dessus.
            {
                // L'idee est des qu'il tombe sur une boucle, un noeud deja visite alors il supprime la liasion

                L[v] = min(L[v], V[i]);
            }
        }
    }
}



int main()
{
    int cas(0);
    while(scanf("%d",&n)==1 && n )
    {
        getchar();
        map<string, int> mapp;
        map<int,string> mapp2;
        string villeA,villeB;
        for(int i(0); i<n; i++)
        {
            cin >> villeA;
            mapp[villeA]=i;
            mapp2[i]=villeA;
        }

        scanf("%d",&m);
        memset(G,0,sizeof(G));
        for(int i(0); i<m; i++)
        {
            cin >> villeA>> villeB;
            G[mapp[villeA]][ mapp[villeB] ] =G[mapp[villeB]][mapp[villeA]]= 1;
        }


        vv.clear();
        gpe=0;
        memset(V,0,sizeof(V));
        memset(L,0,sizeof(L));
        for(int i(0); i<n; i++)
        {
            if(!V[i]){
                dfsRoot=i,rootChildren=0;
                dfs(i,i);

            }
        }

        /**
        Pour supprimer les doublons
        **/
        sort(vv.begin(),vv.end());
        vv.erase( unique( vv.begin(), vv.end() ), vv.end() );


        /**
        Pour les trier alphabetiquement
        **/


        printf("City map #%d: %d camera(s) found\n",++cas,vv.size());
        map<string,int> mappend;

        for(int i(0);i<vv.size();i++) mappend[mapp2[vv[i]]] = i ;
        for(map<string,int>::iterator it=mappend.begin();it != mappend.end() ;it++) cout << it->first <<endl;

        }

    }



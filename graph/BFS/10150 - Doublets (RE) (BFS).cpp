#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<map>
using namespace std;

/** On nous donne tout d'abord une liste de mots, puis un mot de départ et un mot de fin, le but étant d'arrivee au mot de fin en
changeant a chaque fois uniquement une lettre du mot courant

bateau -> buteau -> bureau -> ...
et de les afficher les uns a la suite des autres
**/
string listeMot[25145]; // Dictionnnaire

map<string,int> wordtoInt;
/** Pour le BFS */
map<int,int> dist;
queue<int> q;
map<int,int> parents;
bool estAdjacents[25145];
map<int,vector<int> > t;
/** Fonction qui verifie si deux mots sont des doublets **/
bool doublet(int a,int b)
{
    int u(0);
    if( listeMot[a].size() != listeMot[b].size()) return false;
    for(int i(0); i<listeMot[a].size(); i++)
    {
        if(listeMot[a][i] != listeMot[b][i]) u++;
    }
    return (u==1); // Si il y a une variation dans les deux mots
}

int bfs(int x,int v)
{   int d;
    dist[x]=0;
    parents[x]=-9;
    q.push(x);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u == v) return v;

        if(!estAdjacents[u])    // Si on a pas
            for(int i(0); i<wordtoInt.size(); i++)
            {
                if(doublet(u,i)) t[u].push_back(i);
            }
            estAdjacents[u]=true;

        for(int i(0);i<t[u].size();i++){
            if(!dist.count(d=t[u][i])){

                dist[d]=dist[u]+1;
                parents[d]=u;
                q.push(d);
            }

        }
    }



    return -1;
}


int main()
{
    char buffer[50],mot1[20],mot2[20],n(0),d;
    while(gets(buffer) && strlen(buffer))
    {   sscanf(buffer,"%s",mot1);// Lit les mots a mettre dans le dictionnaire

        listeMot[n]=mot1;

        wordtoInt[mot1]=n;

        n++;
    }

    bool b=false;
    while(gets(buffer) && sscanf(buffer,"%s %s",mot1,mot2) == 2)
    {
        if(b) putchar('\n');
        b=true;

        memset(estAdjacents,false,sizeof(estAdjacents));
        while(!q.empty()) q.pop();
        parents.clear();
        dist.clear();

    if( mot1 == mot2 ) cout << mot1 <<endl<<endl; // Si les mots sont les memes

    else if(strlen(mot1) == strlen(mot2) && wordtoInt.count(mot1) && wordtoInt.count(mot2) && (d= bfs(wordtoInt[mot2],wordtoInt[mot1]) ) != -1)
    {   // meme longueur                    le mot 1 existe           le mot 2 existe           si on est pas arrive a -1
        do{
        cout <<listeMot[d]<<endl;    }while( (d=parents[d]) != -9 );    // Affichage des mots

    }
    else
    {
            printf("No solution.\n");
    }

    }

    return 0;

}

#include<stdio.h>
#include<string.h>
#include<sstream>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<map>

/**
Idee originale est de trouver le plus court chemin entre deux cases d'une grille de taille définie

On a aussi des lignes entre les cases( au nombre de 3) qui empeche de passer d'une case a l'autre

A la fin il faut afficher le chemin avec des directions pour revenir au point initial
Attention le grillage est comme ca :

----->
|
|
v

**/
using namespace std;
map<pair<int,int> ,vector<pair<int,int> > > t,nouvelle;
map<pair<int,int> , int> dist;
queue<pair<int,int> > q;
map<pair<int,int>,pair<int,int> > parents;
int x1,y1,x2,y2;
/**
Suppression des connexions possibles lorsque une ligne de mur est indiqué

**/
void SuppressionMur(int x1,int y1,int x2,int y2)
{

    if(x1 == x2 ) // Si on est sur une ligne
    {
        if(x1 != 0 && x1 != 6 ) // et pas sur le bord (sinon la ligne ne compte pas)
        {
            x1--;// Ca demarre a 0...
            for(int i(y1); i<y2; i++)
            {   /** Pour supprimer dans une map **/

                for(int j(0); j< t[pair<int,int>(x1,i)].size() ; j++)
                    if( t[pair<int,int>(x1,i)][j] == pair<int,int> (x1+1,i))
                    {
                        t[pair<int,int>(x1,i)].erase( t[pair<int,int>(x1,i)].begin()+j  );
                    }
                for(int j(0); j< t[pair<int,int>(x1+1,i)].size() ; j++)
                    if( t[pair<int,int>(x1+1,i)][j] == pair<int,int> (x1,i))
                    {
                        t[pair<int,int>(x1+1,i)].erase( t[pair<int,int>(x1+1,i)].begin()+j  );
                    }


            }
        }
    } // Pareil que x1 et x2
    else if(y1 == y2)
    {
        if( y1 !=0 && y1 !=6 )
        {
            y1--;

            for(int i(x1); i<x2; i++)
            {
                for(int j(0); j< t[pair<int,int>(i,y1)].size() ; j++)
                    if( t[pair<int,int>(i,y1)][j] == pair<int,int> (i,y1+1))
                    {
                        t[pair<int,int>(i,y1)].erase( t[pair<int,int>(i,y1)].begin() + j  );

                    }
                for(int j(0); j< t[pair<int,int>(i,y1+1)].size() ; j++)

                    if( t[pair<int,int>(i,y1+1)][j] == pair<int,int> (i,y1) )
                    {

                        t[pair<int,int>(i,y1+1)].erase( t[pair<int,int>(i,y1+1)].begin()+j  );
                    }
            }
        }
    }



}
/**
Remplir initialement la map
**/
void remplir_map(int a,int b)
{

     if(a+1 <6 )           nouvelle[pair<int,int>(a,b)].push_back(pair<int,int>(a+1,b));
    if(a-1 >=0)           nouvelle[pair<int,int>(a,b)].push_back(pair<int,int>(a-1,b));
         if(b+1 <6 )           nouvelle[pair<int,int>(a,b)].push_back(pair<int,int>(a,b+1));
              if(b-1 >=0 )           nouvelle[pair<int,int>(a,b)].push_back(pair<int,int>(a,b-1));




}
/**
Affichage des directions
**/
void affichage()
{

    pair<int,int> d;
    while( (d=parents[pair<int,int>(x1,y1)]) != pair<int,int>(-9,-9) )
    {
        if( d.first < x1 && d.second == y1) printf("W");
        else if( d.first > x1 && d.second == y1) printf("E");
        else if(d.first == x1 && d.second < y1) printf("N");
        else if(d.first == x1 && d.second > y1) printf("S");
        x1 =d.first;
        y1 =d.second;

    }
}

int main()
{
    int a,b,c,d;
    // Remplissage de la map
    for(int i(0); i<6; i++)
    {
        for(int j(0); j<6; j++)
        {
            remplir_map(i,j);
        }
    }

    while(scanf("%d %d",&x1,&y1)==2 && (x1 || y1) )
    {
        parents.clear();
        t=nouvelle;
        scanf("%d %d",&x2,&y2);
        /** Diminuer les elements **/
        x1--;
        y1--;
        y2--;
        x2--;

        for(int i(0); i<3; i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if(a>c) swap(a,c);
            if(b>d) swap(b,d);

            SuppressionMur(a,b,c,d);

        }
        // Classic BFS
        dist.clear();
        while(!q.empty()) q.pop();

        q.push(make_pair(x2,y2));
        dist[make_pair(x2,y2)]=0;
        parents[make_pair(x2,y2)]=pair<int,int>(-9,-9);
        while(!q.empty())
        {
            pair<int,int> u=q.front();
            q.pop();
            for(int i(0); i<t[u].size(); i++)
            {
                pair<int,int> l=t[u][i];
                if(!dist.count(l))
                {
                    dist[l]=dist[u]+1;
                    parents[l]=u;
                    q.push(l);
                }

            }

        }

        affichage();


        putchar('\n');
    }
    return 0;
}

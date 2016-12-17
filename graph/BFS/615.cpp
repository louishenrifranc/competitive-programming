#include <stdio.h>
#include <string.h>
#include <map>
#include<stdlib.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;
/**  Runtime Error **/
map<int,vector<int> > EdgeList;
map<int,int> quiestRoot;
int parent[100000];
map<int,int> dist;
map<pair<int,int>, int> longeur;
queue<int> pq;
int t[100000][2];




int main()
{
    int n,cas(1),a,b,c,estUnTree,noeud,u,l;
    while(scanf("%d %d",&a,&b)==2 )
    {
        if(a<0 && b<0) break;
        // Initialisation
        for(int i(0);i<100007;i++){
            parent[i]=0;
            for(int j(0);j<2;j++) t[i][j]=-1;
        }
        noeud = -1;
        EdgeList.clear();

        t[a][0]=1;
        t[b][1]=1;
        EdgeList[a].push_back(b);

        while(scanf("%d %d",&a,&b) == 2 && (a || b))
        {
            EdgeList[a].push_back(b);
            t[a][0]=1;
            t[b][1]=1;
        }

        for(int i(0); i<100007 ; i++)
        {
            if(t[i][0]==1 && t[i][1] == -1 )
            {
                noeud=i ;    /** Premiere propriete d'un Tree **/
                break;
            }
        }
        if(noeud == -1 )  printf("Case %d is not a tree.\n",cas++);
        else
        {
            pq.push(noeud);
            estUnTree=1;
            while(!pq.empty())
            {
                int u=pq.front();
                pq.pop();
                for(int i(0); i<EdgeList[u].size(); i++)
                {
                    int l=EdgeList[u][i];
                    parent[l]++;
                    pq.push(l);
                    if(parent[l]>1)  /** Deuxieme propriete d'un Tree **/
                    {
                        estUnTree=0;
                        while(!pq.empty()) pq.pop();
                        break;
                    }


            }
        }
        for(int i(0); i<100007; i++) /** Troisieme propriete **/
        {
            if(t[i][1] == 1 && parent[i] == 0)
            {
                estUnTree=0;
                break;
            }
        }

        if(estUnTree) printf("Case %d is a tree.\n",cas++);
        else  printf("Case %d is not a tree.\n",cas++);
    }
}
return 0;
}

#include <stdio.h>
#include <string.h>
#include <map>
#include<stdlib.h>
#include<queue>
#include<string>
#include<vector>
using namespace std;

map<int,vector<int> > EdgeList;
map<int,int> parent;
map<int,int> dist;
map<pair<int,int>, int> longeur;
queue<int> pq;
/**
 Runtime Error
**/
int main(){
int n,cas,a,b,c,extrem,noeud,u,l;
char t[200];
for(;;){
        while(gets(t) && strlen(t) >0){


        sscanf(t,"%d %d %d",&a,&b,&c); a--; b--;
        EdgeList[a].push_back(b);
        EdgeList[b].push_back(a);
        if(a<b) swap(a,b);
        longeur[pair<int,int>(a,b)]=c;
}

    while(!pq.empty()) pq.pop();
    dist.clear();
    parent.clear();
    dist[0]=extrem=0;
    pq.push(0);

   while(!pq.empty()){
            int u=pq.front();pq.pop();
            for(int i(0);i<EdgeList[u].size();i++){
                int l=EdgeList[u][i];
                if(!dist.count(l)){
                    dist[l]=dist[u]+1;
                    if(extrem<dist[l]){
                        extrem=dist[l];
                        noeud=l;
                    }
                    parent[l]=u;
                    pq.push(l);
                }
            }
        }

        dist.clear();parent.clear();
        dist[noeud]=0;
        parent[noeud]=-9;
        pq.push(noeud);

        while(!pq.empty()){
                 int u=pq.front();pq.pop();
            for(int i(0);i<EdgeList[u].size();i++){
                int l=EdgeList[u][i];
                if(!dist.count(l)){
                    dist[l]=dist[u]+1;
                    if(extrem<dist[l]){
                        extrem=dist[l];
                        noeud=l;
                    }
                    parent[l]=u;
                    pq.push(l);
                }
            }
        }
        extrem=0;
        l=noeud;
        for(u=parent[l];u != -9;u=parent[l]){
            a=u;b=l;
            if(a<b) swap(a,b);
            extrem+=longeur[pair<int,int>(a,b)];
            l=u;
        }
        printf("%d\n",extrem);




}
}

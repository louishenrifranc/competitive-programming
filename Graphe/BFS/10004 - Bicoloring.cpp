#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
vector<int> EdgeList[200+5];
queue<int> q;
map<int,int> dist;
map<int,int> color;
int n;
int bfs(){
q.push(0);
dist[0]=0;
color[0]=0;
while(!q.empty()){
   int u=q.front();
        q.pop();
        for(int i(0); i<EdgeList[u].size(); i++)
        {
        int l=EdgeList[u][i];
         if(color[u] == 0){
            if(color.count(l)){
                if(color[l] == 0) return 0;
            }
            else color[l]=1;
        }
        if(color[u] == 1){
            if(color.count(l)){
                if(color[l] == 1) return 0;
            }
            else color[l]=0;
        }
        if(!dist.count(l))
        {
        dist[l]=dist[u]+1;

        q.push(l);
        }
}
}
return 1;
}


int main(){
int m,a,b;

while(scanf("%d",&n)==1 && n){
            for(int i(0);i<204;i++)
            EdgeList[i].clear();
color.clear();
dist.clear();
    scanf("%d",&m);
    for(int i(0);i<m;i++){
        scanf("%d %d",&a,&b);
        EdgeList[a].push_back(b);
    EdgeList[b].push_back(a);
    }
    if(bfs())   printf("BICOLORABLE.\n");
    else printf("NOT BICOLORABLE.\n");
}
}

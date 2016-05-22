#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;
map<int,set<int> > EdgeList;
map<int,int> parent;
int n,m;
int t[20000+5][20000+5];

bool bfs(){
    for(int i(0);i< (2*n+2);i++) parent[i]=-2;
    queue <int> q;
    q.push(2*n);
    parent[2*n]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u == 2*n+1) return true;
        for(set<int>::iterator it=EdgeList[u].begin();it != EdgeList[u].end();it++){
            int v=*it;
            if(parent[v] == -2 && t[u][v] > 0){
            //   printf("Noeud %d a comme parents %d\n",v,u);
                q.push(v);
                parent[v]=u;
            }
        }
    }

return false;

}


int ford(){
    int u,v;
    int maxflow=0;
    while(bfs()){
        int pathflow=10000;
        for(v=2*n+1;v!=2*n;v=parent[v]){
            u=parent[v];
            pathflow=min(pathflow,t[u][v]);
        }
        maxflow+=pathflow;
        if(maxflow == n) break;

        for(v=2*n+1;v!=2*n;v=parent[v]){
            u=parent[v];
           t[u][v]-=pathflow;
          t[v][u]+=pathflow;

        }

    }
return maxflow;
}


int main(){
int a,b;
while(scanf("%d %d",&n,&m)==2){
        memset(t,0,sizeof(t));
        EdgeList.clear();
      /**  for(int i(0);i<n;i++){
            EdgeList[2*n].push_back(i);
            EdgeList[i].push_back(2*n+1);
            t[2*n][i]=t[i][2*n+1]=1;
        }**/
        for(int i(0);i<m;i++){
            scanf("%d %d",&a,&b);
         EdgeList[2*n].insert(a);
         EdgeList[b+n].insert(2*n+1);
         EdgeList[a].insert(2*n);
         EdgeList[2*n+1].insert(b+n);
            t[2*n][a]=t[b+n][2*n+1]=1;
            EdgeList[a].insert(b+n);
             EdgeList[b+n].insert(a);
         t[a][b+n]=1;

        }

        if((a=ford())>=n) printf("YES \n",a);
        else printf("NO \n",a);

}

return 0;
}


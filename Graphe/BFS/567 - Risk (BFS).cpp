#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<map>
using namespace std;
map<int,vector<int> > t;
map<int,int> dist;
queue<int> q;

int main(){
int n,m,cas,testset(0);
int i(1);
while(scanf("%d",&n)==1){
    t.clear();
    i=1;
    for(int j(0);j<n;j++){
        scanf("%d",&m);
        t[i].push_back(m);
        t[m].push_back(i);
    }

    for(int j(0);j<18;j++){
        scanf("%d",&n);
        i++;
        for(int k(0) ; k<n ; k++){
            scanf("%d",&m);
            t[i].push_back(m);
            t[m].push_back(i);
        }
    }

    scanf("%d",&cas);
    printf("Test Set #%d\n",++testset);
    for(int i(0);i<cas;i++){
        scanf("%d %d",&n,&m);

        dist.clear();
        while(!q.empty()) q.pop();

        dist[n]=0;
        q.push(n);

        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i(0);i<t[u].size();i++){
                int l=t[u][i];
                if(!dist.count(l)){
                    dist[l]=dist[u]+1;
                    q.push(l);
                }
                if(m == l) {
                        while(!q.empty() ) q.pop();     /** Permet d'accelerer de moitie (0.500 to 0.200 la vitesse de l'algo **/
                        break;
                }
            }

        }

        printf("%2d to %2d:%2d\n",n,m,dist[m]);


    }
    putchar('\n');

}
}



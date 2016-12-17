#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<sstream>
#define MAX 105
using namespace std;
int L[MAX],V[MAX],P[MAX],G[MAX][MAX];
int n,gpe;
/**
Algorithme pour la recherche des articulation Point
**/

void dfs(int a,int b){
    L[b]=V[b]= ++gpe;

    for(int i(0);i<n;i++){
        if(G[b][i]){
            if(!V[i]){
                dfs(b,i);
                if(L[b] <= L[i]){
                 P[b]++;
            }
            L[b]=min(L[b],L[i]);


            }
            else if(i != a){
                L[b]=min(L[b],L[i]);
            }
        }
    }




}


int main(){
    string buffer;
    int res;
    while(scanf("%d",&n)==1 && n){
        memset(G,0,sizeof(G));
        memset(L,0,sizeof(G));
        memset(V,0,sizeof(G));
        memset(P,0,sizeof(G));
        res=gpe=0;

        getchar();
        while(1){
        getline(cin,buffer);
        istringstream is(buffer);
        int a,b;
        is >> a;
        if(a==0) break;
        else{
            while(is >> b){
                G[a-1][b-1]=G[b-1][a-1]=1;

            }
        }
        }

        for(int i(0);i<n;i++){
            if(! V[i]){
                dfs(i,i);
                P[i]--;
            }
        }

        for(int i(0);i<n;i++){
            if(P[i]>0) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iostream>
using namespace std;


bool t[105][105];
string s[105];
/** Variables globales **/
int n,m;
int resultat;

/**
Basic DFS avec enregistrement du nombre de W voisins**/
int dfs(int a,int b)
{

    t[a][b]=true;
    for(int i(-1); i<2; i++)
    {
        for(int j(-1); j<2; j++)
        {
            if( a+i>=0 &&  b+j>=0 && a+i<n && b+j<m && !t[a+i][b+j]  && !(j==0 && i==0)  )
                if(s[a+i][b+j]=='@')
                {
                    dfs(a+i,b+j);
                }
        }
    }
}


int main()
{

    while(scanf("%d %d",&n,&m)==2 && n!=0 && m!=0){
        getchar();
        for(int i(0);i<n;i++){
                getline(cin,s[i]);
            }
        resultat=0;
        memset(t,false,sizeof(t));
        for(int i(0);i<n;i++){
            for(int j(0);j<m;j++){
                if( !t[i][j] && s[i][j] == '@' ){
                   resultat++;
                   dfs(i,j);
                }
            }

        }
        printf("%d\n",resultat);
        }

    return 0;
}

#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int N,nbtrack;
    while(scanf("%d",&N)==1 )
    {
        scanf("%d",&nbtrack);
        int valeur[nbtrack];
        for(int i(0); i<nbtrack; i++)
            scanf("%d",&valeur[i]);

        bool t[N+1][nbtrack+1];
        memset(t,false,sizeof(t));

        int memo[nbtrack+1][N+1];

        for(int i(0); i<=nbtrack; i++)
        {
            for(int w(0); w<=N; w++)
            {
                if(w==0 || i==0)
                    memo[i][w]=0;
                else if(valeur[i-1]<=w)
                {
                    memo[i][w]=max(valeur[i-1]+memo[i-1][w-valeur[i-1]],memo[i-1][w]);
                }

                else
                    memo[i][w]=memo[i-1][w];

            }
        }
        int i=nbtrack;
        int N1=N;
        int tt[nbtrack];
        int  j(0);
        while(i>0){
            if(N-valeur[i-1]>=0 && memo[i][N] - memo[i-1][N-valeur[i-1]] == valeur[i-1]){
                tt[j]=valeur[i-1];j++;
                N-=valeur[i-1];
                i--;
            }
            else i--;
        }

        for(int i(0);i<j;i++) printf("%d ",tt[i]);
        printf("sum:%d\n",memo[nbtrack][N1]);
    }
}

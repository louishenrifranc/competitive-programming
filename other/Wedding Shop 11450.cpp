#include<iostream>
#include<cstdio>
#include<string.h>
#include<stdio.h>
/**
DP Bottom Up Facile
**/
bool can_reach[210][25];
int prix[22][22];
using namespace std;
int main()
{
    int times,M,C,i,j;
    int maximum;
    scanf("%d",&times);
    while(times--)
    {
        cin>>M>>C;
        for(i=0; i<C; i++)
        {
            scanf("%d",&j);
            prix[i][0]=j;
            for(int u(1); u<=j; u++)
            {
                scanf("%d",&prix[i][u]);
            }
        }

        memset(can_reach,false,sizeof(can_reach));
        for(int i(1); i<=prix[0][0]; i++)
            can_reach[M-prix[0][i]][0]=true;

        for(int j(1); j<C; j++)
        {

            for(int i(1); i<M; i++)
            {

                if(can_reach[i][j-1])
                {
                    for(int x(1); x<=prix[j][0]; x++)
                    {
                        if(i-prix[j][x]>=0)
                        {
                            can_reach[i-prix[j][x]][j]=true;
                        }
                    }
                }
            }
        }
        maximum=-1;
        for(int i(M-1); i>=0; i--)
        {
            if(can_reach[i][C-1])
            {
                maximum=M-i;

            }
        }
        if(maximum==-1) cout <<"no solution"<<endl;
        else cout<< maximum<<endl;
    }


    return 0;

}


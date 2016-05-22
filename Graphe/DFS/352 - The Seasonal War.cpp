#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
bool t[27][27];
string s[27];
int n;

void dfs(int a,int b)
{
    t[a][b]=true;
    for(int i(-1); i<2; i++)
    {
        for(int j(-1); j<2; j++)
        {
            if( a+i>=0 &&  b+j>=0 && a+i<n && b+j<n && !t[a+i][b+j]  && !(j==0 && i==0)  )
                if(s[a+i][b+j]=='1')
                    dfs(a+i,b+j);
        }
    }

}


int main()
{

    int compteur(0),cas(0);
    while(scanf("%d",&n)==1)
    {
        for(int i(0); i<n; i++)
            cin >> s[i];
        compteur=0;
        memset(t,false,sizeof(t));
        for(int i(0); i<n; i++)
        {
            for(int j(0); j<n; j++)
            {
                if(  !t[i][j] && s[i][j]=='1' )
                {

                    compteur++;
                    dfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++cas,compteur);
    }
}

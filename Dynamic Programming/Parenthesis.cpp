#include<cstdio>
#include<sstream>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int n,n1,a,b,cas(1);
    int i(0),j,q(0);
    ostringstream ss;

    while(scanf("%d",&n) ==1 && n!=0 )
    {

        i=0;
        int arrai[n+2];

        n1=n;
        while(n1--)
        {
            scanf("%d %d",&a,&b);
            arrai[i++]=a;
        }
        if(n==1) printf("Case %d: A1\n",cas++);
        else{
        long long memo[n+2][n+2];
        string resultat[n+2][n+2];

        arrai[i++]=b;
        for(int i(1); i<=n; i++){
                memo[i][i]=0;

                 ss<<"A"<<i;
                resultat[i][i]=ss.str();
                ss.str("");

            }
        ss.clear();

        for(int L=2; L<=n; L++)
        {
            for(int i(1); i<=n-L+1; i++)
            {
                j=i+L-1;
                memo[i][j]=10000000;
                for(int k=i; k<=j-1; k++)
                {
                    q=memo[i][k]+memo[k+1][j]+arrai[i-1]*arrai[k]*arrai[j];
                    if(q<memo[i][j]){
                        memo[i][j]=q;
                        ss<< "(" <<resultat[i][k]<<" x "<<resultat[k+1][j]<<")";
                        resultat[i][j]=ss.str();
                        ss.str("");
                    }
                    ss.clear();

                }
            }
        }
        ss.str("");
        ss.clear();
        cout <<"Case "<<cas++<<": "<< resultat[1][n]<<endl;
        delete memo,resultat;
    }
    }

    return 0;
}

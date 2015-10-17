#include<stdio.h>
#include<string.h>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<stack>

#include<bitset>
/**
Trouver des paires de prime qui sont séparé que de 2
Utilisation de la librairie bitset
**/
using namespace std;
long long t[801];
/**
**/
bitset<20000010> bs;

map<int,pair<long long,long long> > paireprime;
void primenumber(int borne)
{
    long long j(0),a,b;
    int taille=borne+1;
    bs.reset();
    bs.flip();
    bs.set(0,false);
    bs.set(1,false);
    a=2;
    for(long long j=4; j<=taille; j+=2) bs.set((size_t)j,false);
    for(long long i(3); i<=taille; i++)
        if(bs.test((size_t)i))
        {
            for(long long j=i*i; j<=taille; j+=i) bs.set((size_t)j,false);

            b=i;

            if( b-a == 2){
                    paireprime[j]=pair<long long ,long long>(a,b);
            j++;

            }
            a=b;

        }
}


    int main()
    {   int a;
        primenumber(20000001);
        while(scanf("%d",&a)==1) printf("(%lld, %lld)\n",paireprime[a-1].first,paireprime[a-1].second);
    return 0;
    }


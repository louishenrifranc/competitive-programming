#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;
priority_queue<pair<double, pair<int,int>   > > EdgeList;
int N,K,M;
int t[101];
map<pair<double,double>, int> doubleTotint;
map<int, pair<double,double> > W;

int findSet(int a)
{
    return ( t[a] ==a) ? a: findSet(t[a]);
}
void initSet(int X)
{
    for(int i(0); i<X; i++) t[i]=i;
}
bool sameSet(int a,int b)
{
    return findSet(a) == findSet(b);
}
void unionSet(int a,int b)
{
    t[findSet(a)] =  findSet(b);
}
double Kruskal()
{
    double cost=0;
    initSet(N+1);
    while(!EdgeList.empty())
    {
        pair<double, pair<int,int> > fron = EdgeList.top();
        EdgeList.pop();
        if(!sameSet( fron.second.first,fron.second.second  ))
        {
            unionSet(fron.second.first,fron.second.second);
            cost+= -(fron.first) ;

        }
    }
    return cost;

}

double distance(double a,double b,double c,double d){
return -sqrt(  pow((c-a),2) +pow( (d-b),2)     );
}

int main()
{

    int cas,n;
    double a,b;
    pair<double,double> buffer;
    scanf("%d", &cas);
    while(cas--){
        n=0;
        W.clear(); doubleTotint.clear();
        scanf("%d",&N);
        if( N > 1){
        scanf("%lf %lf",&a,&b);

        W[n] = pair<double,double>(a,b);

        doubleTotint[pair<double,double>(a,b)]=n++;

        for(int i(0);i<N-1;i++){
            scanf("%lf %lf",&a,&b);
            if(!doubleTotint.count(pair<double,double>(a,b))){
                for(int j(0); j< doubleTotint.size() ; j++){
                    buffer = W[j];
                    EdgeList.push( pair<double, pair<int,int> >(distance(a,b,buffer.first,buffer.second),pair<int,int>(j,n)) );
                }
                W[n]=pair<double,double>(a,b);
                doubleTotint[pair<double,double>(a,b)] =n++;
            }
        }
        printf("%.2f\n",Kruskal());
        }
        else if( N == 1){
            scanf("%lf %lf",&a,&b);
            printf("0.00\n");
        }
     if(cas)    printf("\n");
    }
    return 0;
}

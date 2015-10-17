#include <stdio.h>
#include <string.h>
#include <map>
#include<stdlib.h>
#include<math.h>
#define INF 1<<29
using namespace std;
/**
A completer Floyd Warshall
**/
typedef pair<int,int> ii;

map<int,ii> inttoPair;
map<ii,int> pairToInt;
double tab[201][201];
double distance(int a,int b,int c,int d){
return   sqrt(pow(abs(c-a),2) + pow(abs(d-b),2) );
}


int main(){
int n,cas(0),a,b,m(0);



while(scanf("%d",&n)==1 && n){
    for(int i(0);i<n;i++) for(int j(0);j<n;j++) tab[i][j]=10000;
    m=0;
    inttotPair.clear();
    scanf("%d %d",&a,&b);
    inttoPair[m++]=ii(a,b);
   for(int i(0);i<n-1;i++){
    scanf("%d %d",&a,&b);

    for(int j(0);j< inttoPair.size() ;j++){
        tab[  m ][j] =tab[j][m] = distance(a,b,inttoPair[j].first,inttoPair[j].second);
    }
    inttoPair[m++]=ii(a,b);

   }


   for(int k(0);k<n;k++){
    for(int i(0);i<n;i++){
        for(int j(0);j<n;j++) tab[i][j] = min( tab[i][j],max(tab[i][k],tab[k][j]));
    }
   }
   printf("Scenario #%d\nFrog Distance = %.3f\n\n",++cas,tab[0][1]);

}



}

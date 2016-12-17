#include<stdio.h>
#include<map>
#include<queue>
#include<algorithm>
#define INF 1000000000
using namespace std;
int N,M;
/** Enregistrer les donnees **/
int t[1000][1000];
map<pair<int,int>,int > coordtoInt;
map<int,vector<pair<int,int> > > EdgeList;

/** Propre a Dijkstra **/

int main(){

int cas,n(0);

scanf("%d",&cas);
while(cas--){
        n=0;
        coordtoInt.clear();EdgeList.clear();
    scanf("%d\n%d",&N,&M);
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            scanf("%d",&t[i][j]);
            coordtoInt[pair<int,int>(i,j)] = n++;
        }
    }
int xx;

for(int i(0);i<N;i++){
    for(int j(0);j<M;j++){
        if( i+1 < N ) EdgeList[ coordtoInt[pair<int,int>(i,j)] ].push_back(pair<int,int>( t[i+1][j], coordtoInt[pair<int,int>(i+1,j)] ));
        if( i-1 > -1 ) EdgeList[ coordtoInt[pair<int,int>(i,j)] ].push_back(pair<int,int>( t[i-1][j], coordtoInt[pair<int,int>(i-1,j)] ));
        if( j+1 < M ) EdgeList[ coordtoInt[pair<int,int>(i,j)] ].push_back(pair<int,int>( t[i][j+1], coordtoInt[pair<int,int>(i,j+1)] ));
        if( j-1 > -1 ) EdgeList[ coordtoInt[pair<int,int>(i,j)] ].push_back(pair<int,int>( t[i][j-1], coordtoInt[pair<int,int>(i,j-1)] ));

    }

}

   vector<int> dist( N*M, INF); dist[coordtoInt[pair<int,int>(0,0)] ]=0;
   priority_queue<pair<int,int>,vector<pair<int,int > >,greater<pair<int,int > > > pq; pq.push(pair<int,int>( 0,coordtoInt[pair<int,int>(0,0)]) );

    while(!pq.empty()){
        pair<int,int> u = pq.top();pq.pop();
        int poids= u.first; int noeud = u.second;
        if( dist[noeud]  == poids)
        for(int i(0);i< EdgeList[noeud].size() ; i++ ){
            pair<int,int> v =EdgeList[noeud][i];
            if( dist[noeud] + v.first < dist[v.second] ){
                dist[v.second]= dist[noeud]+v.first;
                pq.push(pair<int,int> (dist[v.second],v.second) );
            }
        }
        }
        printf("%d\n",dist[coordtoInt[ pair<int,int>(N-1 , M-1) ]] + t[ 0][0] );

}
return 0;

}

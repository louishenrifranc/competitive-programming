#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef pair<int,int> ii;
int t[100+5][100+5];
int n,m,s;
map<char,int> directions;
ii nextmove[4]={ii(-1,0),ii(0,1),ii(1,0),ii(0,-1)};
ii bouger;
int indice;
ii positionActuelle;
int score;

void tourner(char d){
    if(d=='D'){
        indice++;
        if(indice==4 ) indice=0;
    }
    else if(d=='E'){
        indice--;
        if(indice==-1) indice=3;
    }
    bouger=nextmove[indice];

}
int collision(int x,int y){
    if(x+bouger.first >= n || x+bouger.first <0 || y+bouger.second >= m || y+bouger.second < 0) return 0;
        if(t[x+bouger.first][y+bouger.second] == -1) return 0;
    if(t[x+bouger.first][y+bouger.second] == 1 ){
            score++;
            t[x+bouger.first][y+bouger.second]=0;
    }
return true;
}

int main(){
string buffer;
directions['N']=0;
directions['S']=2;
directions['L']=1;
directions['O']=3;
while(scanf("%d %d %d",&n,&m,&s)==3 && n+m+s != 0){
        score=0;
        getchar();

    for(int i(0);i<n;i++){
        getline(cin,buffer);
        for(int j(0);j<m;j++){
            if(buffer[j] =='*') t[i][j]=1;
            else if(buffer[j]=='.') t[i][j]=0;
            else if(buffer[j] =='#') t[i][j]=-1;
            else if(directions.count(buffer[j])){
                    bouger=nextmove[directions[buffer[j]]];
                    indice=directions[buffer[j]];
                    positionActuelle=ii(i,j);
        }
    }
    }
    getline(cin,buffer);
    for(int i(0);i<s;i++){
        if(buffer[i]=='F'){
            if(collision(positionActuelle.first,positionActuelle.second))
                positionActuelle=ii(positionActuelle.first+bouger.first,positionActuelle.second+bouger.second);

        }
        else{
            tourner(buffer[i]);
        }
    }
printf("%d\n",score);
}
}

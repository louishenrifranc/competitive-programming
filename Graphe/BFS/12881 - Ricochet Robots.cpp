#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> iii;
int n,w,h,l;
string grid[10+5];  // Contient la grille
map<iii,int> cas;   // Map qui donne a chaque schema possible de positionnement des robots une valeur correspondant au nombre de deplacement
                    // Est utilisé dans la methode Push pour eviter de remettre deux fois un meme schema
int dirx[4]={1,0,0,-1};
int diry[4]={0,1,-1,0};
vector<pair<int,int> > robots;  // Position initiale des robots


/**
Fonction qui redefinit la fonction push de la queue.
Permet d'eviter d'ajouter un schema de positions de robots deja ajoute a la pile
**/
inline void Push(queue<iii> &q,iii &vecteur,int nombre){
    sort(vecteur.begin()+1,vecteur.end());
    if(!cas.count(vecteur)){
        cas[vecteur]=nombre;
        q.push(vecteur);
    }

}

/**
Fonction qui se charge de deplacer le robot i du schema robots dans la direction (dx,dy) tant qu'il n'y a pas d'obstacles (autre robot,mur,map)
**/
inline void Deplace(iii &robots,int i,int dx,int dy){
bool encoreDeplace=true;
int x=robots[i].first+dx;
int y=robots[i].second+dy;

while(encoreDeplace){
    if(x < 0 || x > h-1 || y < 0 || y > w-1) break;
    for(int j(0);j<robots.size();j++){
        if(j != i && robots[j].first == x && robots[j].second == y ){
                encoreDeplace=false;
                break;
        }
    }
    if(grid[x][y] == 'W') break;
    if(encoreDeplace){
                    x+=dx;
                    y+=dy;
    }

}
robots[i] =ii(x-dx,y-dy);
// printf("Robot %d est maintenant en %d-%d\n",i,x-dx,y-dy);
}

/**
BFS classique ou on empile dans une queue (ajouté à la fin) tous les schéma possible de position de robot**/
int bfs(){
queue<iii> q;
Push(q,robots,0);
while(!q.empty()){
    iii u=q.front();
    q.pop();
    int nombre=cas[u];
    if(grid[u[0].first][u[0].second] == 'X') return nombre;     // Si le robot  est sur X

    if(nombre == l) continue; // Si on recoit un schema mais que l'on a plus de droit de bouger

    for(int i(0);i<u.size();i++){                       // toujours = au nombre de robots sur la map
        for(int dir(0);dir<4;dir++){                    // Pour toutes les directions possibles
                iii nouvelle_position_robot=u;           // Effectue une copie du schéma actuel
                Deplace(nouvelle_position_robot,i,dirx[dir],diry[dir]); // Modifie la position du robot i dans le schema
                Push(q,nouvelle_position_robot,nombre+1);       // L'ajoute a la pile
        }
    }


}
return 0;
}


int main(){
string buffer;
while(scanf("%d %d %d %d",&n,&w,&h,&l)==4){
    getchar();
    robots.clear();
    cas.clear();
    for(int i(0);i<h;i++){
        getline(cin,buffer);
        grid[i]=buffer;
        for(int j(0);j<buffer.size();j++){
            if(buffer[j]>='1' && buffer[j]<='4'){
                if(buffer[j] == '1')
                    robots.insert(robots.begin(),ii(i,j));
                else robots.push_back(ii(i,j));
            }
        }
    }
 /**   for(int i(0);i<robots.size();i++){
    printf("Position des robots: %d %d\n",robots[i].first,robots[i].second);
    }
 **/
    int resultat=bfs();
    if(resultat) printf("%d\n",resultat);
    else printf("NO SOLUTION\n");
}


}

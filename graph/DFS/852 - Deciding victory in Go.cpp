#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iostream>
using namespace std;
bool t[10][10];
string s[10];
int blanc,noir;
int buffer=0;
bool premierefois=false;
int couleur=2;
bool ferme=true;
/**
Basic DFS avec enregistrement du nombre de W voisins
noir=1
blanc=0
**/
void dfs(int a,int b)
{

    t[a][b]=true;


    for(int i(-1);i<=1;i+=2){
        for(int j(0);j<=1;j++){
            if(j%2==0){
                if( !t[a][b+i] && b+i < 9   && b+i >=0 ){

                    if(s[a][b+i] == '.'){
                        t[a][b+i]=true;
                        buffer++;
                        dfs(a,b+i);
                    }
                    else if(s[a][b+i] == 'X' ){
                        if(!premierefois){
                            premierefois=true;
                            couleur=1;
                        }
                        else if(couleur == 0) ferme=false;
                    }
                    else if(s[a][b+i] == 'O'){
                        if(!premierefois) {
                                couleur=0;
                                premierefois=true;
                        }
                        else if(couleur==1) ferme=false;
                    }

                }



            }
            else{
                if( !t[a+i][b] && a+i <9 && a+i >=0){
                    if(s[a+i][b] == '.'){
                        t[a+i][b]=true;
                        buffer++;
                        dfs(a+i,b);
                    }
                    else if(s[a+i][b] == 'X' ){
                        if(!premierefois){
                            premierefois=true;
                            couleur=1;
                        }
                        else if(couleur == 0) ferme=false;
                    }
                    else if(s[a+i][b] == 'O'){
                        if(!premierefois){
                                couleur=0;
                                premierefois=true;
                        }
                        else if(couleur==1) ferme=false;
                    }


                }


            }


        }
    }


}


int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        memset(t,false,sizeof (t));
        for(int i(0);i<9;i++) getline(cin,s[i]);

        noir=blanc=0;
        buffer=1;
        premierefois=false;
        ferme=true;
        couleur=2;

        for(int i(0);i<9;i++){
            for(int j(0);j<9;j++){
                if(!t[i][j]){
                if(s[i][j] == 'X'){
                    noir++;
                }

                if(s[i][j] == 'O'){
                    blanc++;
                }

                if(s[i][j] == '.'){
                    buffer=1;
                    premierefois=false;
                    ferme=true;
                    couleur=2;

                    dfs(i,j);
                    if(ferme){
                        if(couleur==1) noir+=buffer;
                        else if(couleur==0) blanc+=buffer;
    }
                }
                }
            }
        }
        printf("Black %d White %d\n",noir,blanc);
    }


    return 0;
}

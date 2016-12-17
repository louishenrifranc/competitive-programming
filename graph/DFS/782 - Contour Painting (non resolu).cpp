#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
char s[35][85];
char caractere;
bool t[35][85];
int taillemax(0),iii(0);

void dfs(int a,int b)
{
    t[a][b]=true;
    for(int i(-1);i<2;i+=2){
        for(int j(0);j<=1;j++){
            if(j%2==0){
                 if( !t[a][b+i] && b+i < taillemax   && b+i >=0 ){
                        if(s[a][b+i] == ' '){
                            dfs(a,b+i);
                        }
                        else if(s[a][b+i] == caractere){
                            s[a][b]='#';
                        }
                 }

            }
            else{
                if( !t[a+i][b] && a+i < iii && a+i >=0){
                         if(s[a+i][b] == ' '){
                            dfs(a+i,b);
                        }
                        else if(s[a+i][b] == caractere){
                            s[a][b]='#';
                        }
                }



            }
        }
    }



}


int main()
{
    int n,a,b;
    string buffer;
    scanf("%d",&n);
    getchar();
    while(n--){
        bool ttt=true;
        memset(s,' ',sizeof(s));
        memset(t,false,sizeof(t));
        iii=taillemax=0;

        while(ttt){

           getline(cin,buffer);

           if(buffer[0] == '-') ttt=false;

           else{

            strcpy(s[iii++],buffer.c_str());
            if(taillemax <  buffer.length() ) taillemax = buffer.length();
            for(int j(0);j<buffer.length();j++) if(s[iii-1][j] == '*'){
                a=iii-1;b=j;
            }
           }
        }
        s[a][b]=' ';
        bool buff=true;
        for(int i(0);i<iii && buff ;i++){
            for(int j(0);j<taillemax && buff;j++){
                if(s[i][j] != ' ' ) {
                        caractere=s[i][j];
                        buff = false;
                }
            }
        }
        for(int i(0);i<iii+1;i++){
            for(int j(0);j<taillemax+1;j++){

                if(s[i][j] != caractere) s[i][j]=' ';
            }
        }


        dfs(a,b);
        for(int j(0);j<iii;j++) cout << s[j]<<endl;


        }






    return 0;
}

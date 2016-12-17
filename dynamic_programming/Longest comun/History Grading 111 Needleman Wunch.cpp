#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>

#include <math.h>
using namespace std;

/**
 Many problems in Computer Science involve maximizing some measure according to constraints.

Consider a history exam in which students are asked to put several historical events into chronological order. Students who order all the events correctly will receive full credit, but how should partial credit be awarded to students who incorrectly rank one or more of the historical events?

Some possibilities for partial credit include:

    1 point for each event whose rank matches its correct rank
    1 point for each event in the longest (not necessarily contiguous) sequence of events which are in the correct order relative to each other.

For example, if four events are correctly ordered 1 2 3 4 then the order 1 3 2 4 would receive a score of 2 using the first method (events 1 and 4 are correctly ranked) and a score of 3 using the second method (event sequences 1 2 4 and 1 3 4 are both in the correct order relative to each other).

In this problem you are asked to write a program to score such questions using the second method.

Plus longue chaine commune Needleman Wunch
**/
int verification();

int correct_answer[21];
int student_answer[21];
int mem[21][21];
int n;
int main(){

int temp;
scanf("%d",&n);
for(int i(0);i<=n;i++){
        mem[0][i]=0;     // Initialise ligne et colonne 0
        mem[i][0]=0;
        }
for(int i(1);i<=n;i++){
    scanf("%d",&temp);
    correct_answer[temp]=i;     // recupere la bonne chaine
                                // On enregistre les elements par leur position dans la liste
                                // EX: La valeur 3 est la premiere de la liste c[3]=1
}


    while(scanf("%d",&temp)!= EOF){ // Tant que l'on a plus de chaine eleve
        student_answer[temp]=1;      //
        for(int i(2);i<=n;i++){
            scanf("%d",&temp);
        student_answer[temp]=i;
    }
   printf("%d\n",verification());


}
}


int verification(){
    int eg,choix1;


    for(int i(1);i<=n;i++){
        for(int j(1);j<=n;j++){
            eg=0;
        if(correct_answer[i]==student_answer[j]) eg++;
        choix1=max(mem[i-1][j],mem[i][j-1]); // Choix du max entre troix valeurs
                                             // Dans la matrice pour l'element i,j
                                            // Soit i-1,j soit i-1,j-1 soit i,j-1
        mem[i][j]=max(choix1,mem[i-1][j-1]+eg);
        }
    }
    return(mem[n][n]);                      // On retourne le dernier element

}

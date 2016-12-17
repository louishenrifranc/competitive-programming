/**
* Recherche du sous chaine maximal dans une chaine de nombre (exemple de la bourse
* ou l'on connait à l'avance les variations d'un cours une seule fois dans la journée
* le but etant de trouver l'endroit ou c'est le plus bas et l'endroit ou c'est le plus haut
*
**/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;
int N;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


#define Repp(i,a,b) \
    for(i=(int)a;i<=(int)b;i++)
#define Repm(i,a,b) \
    for(i=(int) a;i>=(int)b;i--)
#define LONGUEUR_LIGNE 100

/**
* Fonction qui retourne la valeur maximale sommant les elements du tableau passant par le mid
*
* \par deb,fin,mid position dans le vecteur A
* Renvoit la position de debut et de fin de la chaine qui donne le maximum passant par min, renvoit aussi la valeur de ce maximum
**/

vi maxCross(const int deb,const int fin,const int mid,vi & A)
{

    int sumL(A[mid]);

    int sumR(A[mid+1]);
    vi resultat(3,0);
    int i,right,left;
    Repm(i,mid-1,deb)
    {
        if( sumL+A[i]>sumL)
        {
            sumL=sumL+A[i];
            left=i;
        }
    }

    Repp(i,mid+2,fin)
    {
        if(sumR +A[i]>sumR)
        {
            sumR=sumR+A[i];
            right=i;
        }
    }
    resultat[0]=left;
    resultat[1]=right;
    resultat[2]=sumL+sumR;
    return(resultat);
}

/**
* Fonction recursive qui s'appelle elle même et qui tant que le tableau passé en parametre ne contient plus qu'un élément
* Compare la partie gauche, la partie droite, puis les deux parties en meme temps car la chaine qui donne la valeur maximale est forcément
* comprise soit avant la moitie, soit après,soit sur passant par le milieu
* Renvoit un tableau contenant la position minimale, la position maximale et la valeur du max
**/
vi maxSide(const int deb,const int fin,vi &A)
{
    int mid;
    vi rS(3,0),lS(3,0),mS(3,0),os(3,0);
    if(deb==fin)
    {
        os[0]=deb;
        os[1]=fin;
        os[2]=A[deb];
        return(os);
    }
    mid=(int) ((deb+fin)/2);
    lS=maxSide(deb,mid,A);
    rS=maxSide(mid+1,fin,A);
    mS=maxCross(deb,fin,mid,A);
    if(lS[2]>rS[2] && lS[2]> mS[2]) return (lS);
    if(rS[2]>lS[2] && rS[2]> mS[2]) return (rS);
    else return(mS);
}

int main()
{
    vi test;
    vi resultat;
    test.push_back(15);
    test.push_back(16);
    test.push_back(-32);
    test.push_back(5);
    resultat=maxSide(0,3,test);
    cout << resultat[2];
    return 0;
}

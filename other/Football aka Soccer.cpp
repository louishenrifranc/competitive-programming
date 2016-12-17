#include <iostream>
#include <cstdio>
#include <algorithm>
#include<cstdlib>
#include <vector>
#include <map>
const int VICTOIRE=3;
const int  DEFAITE=0;
const int  NUL=1;

using namespace std;

struct equipe
{

    equipe()=default;
    equipe(string name)
    {
        nom=name;
        nombreDePoints=0;
    matchJoues=0;
    victoire=0;
    nul=0;
    defaite=0;
    diffdeBut=butM-butP;
    butM=0;
    butP=0;
    };

    string nom;
    int nombreDePoints;
    int matchJoues;
    int victoire;
    int nul;
    int defaite;
    int diffdeBut=butM-butP;
    int butM;
    int butP;
    friend ostream& operator<<(ostream& os, const equipe& e)
    {
        os <<") "<< e.nom<<" "<<e.nombreDePoints<<"p, "<<e.matchJoues<<"g ("<<e.victoire<<"-"<<e.nul<<"-"<<e.defaite<<"), "<<e.diffdeBut<<"gd ("<<e.butM<<"-"<<e.butP<<")"<<endl;
        return os;
    }

} Equipe [30];
class Tri
{
public:
    bool operator()(const pair<string,equipe>& Aa,const pair<string,equipe>& Bb)
    {
        equipe a=Aa.second;
        equipe b=Bb.second;
        if(a.nombreDePoints>b.nombreDePoints) return true;
        else if(b.nombreDePoints>a.nombreDePoints) return false;
        else
        {
            if(a.victoire>b.victoire) return true;
            else if(b.victoire>a.victoire) return false;
            else
            {
                if(a.diffdeBut> b.diffdeBut) return true;
                else if(a.diffdeBut<b.diffdeBut) return false;
                else
                {
                    if(a.butM>b.butM) return true;
                    else if(a.butM<b.butM) return false;
                    else
                    {
                        if(a.matchJoues<b.matchJoues) return true;
                        else if (a.matchJoues> b.matchJoues) return false;
                        else
                        {
                            if(a.nom<b.nom) return true;
                            else if(a.nom>b.nom) return false;
                        }
                    }
                }
            }
        }
    return false;
    }
};

map<string,equipe,Tri> tournament;


void affectationpoints(const char *points)
{
    int i = 0, j = 0;
    string nomA,nomB;
    int scoreA(0),scoreB(0);

    while(points[i]!='#'){nomA[j++] = points[i++];}
     j = 0; i++;

            // Number of goals characters
    char ngc_a[16], ngc_b[16];


    while(points[i]!='@'){ngc_a[j++] = points[i++];}
     scoreA = atoi(ngc_a); j = 0; i++;
    while(points[i]!='#'){ngc_b[j++] = points[i++];}
     scoreB = atoi(ngc_b); j = 0; i++;

    while(points[i]!='\0'){nomB[j++] = points[i++];}
    j = 0; i++;
    // Concernant l'equipe A
    tournament[nomA].butM+=scoreA;
    tournament[nomA].butP-=scoreB;
    tournament[nomA].matchJoues++;

    tournament[nomB].butM+=scoreB;
    tournament[nomB].butP-=scoreA;
    tournament[nomB].matchJoues++;

    if(scoreA> scoreB)
    {
        tournament[nomA].victoire++;
        tournament[nomA].nombreDePoints+=VICTOIRE;
        tournament[nomB].defaite++;

    }
    else if(scoreA == scoreB)
    {
        tournament[nomB].nombreDePoints+=NUL;
        tournament[nomB].nombreDePoints+=NUL;
        tournament[nomA].nul++;
        tournament[nomA].nul++;
    }
    else
    {
        tournament[nomB].victoire++;
        tournament[nomB].nombreDePoints+=VICTOIRE;
        tournament[nomB].defaite++;
    }


}




int main ()
{   vector<string> nomEquipe;
    int nombredeTournois(0),nombredequipe(0),nombredematch(0);
    string nomduTournois,nomdelequipe,points;
    scanf("%d\n",&nombredeTournois);
    while(nombredeTournois--)
    {
        getline(cin,nomduTournois);
        scanf("%d\n",&nombredequipe);
        while(nombredequipe--)
        {
            getline(cin,nomdelequipe);
            tournament.insert(make_pair(nomdelequipe.c_str(),equipe(nomdelequipe.c_str())));
            nomEquipe.push_back(nomdelequipe);

        }
        scanf("%d\n",&nombredematch);
        while(nombredematch--)
        {
            getline(cin,points);
            affectationpoints(points.c_str());
        }
         cout <<nomduTournois<<endl;
        for(int i(0);i<nomEquipe.size();i++){
            cout << tournament[nomEquipe[i]]<<endl;
        }


    }
    tournament.clear();

}

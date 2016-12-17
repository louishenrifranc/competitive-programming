#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<stack>
#include<iterator>
using namespace std;
typedef pair<int,int> paire;
stack<paire > pile;
/**
 Suppose you have to evaluate an expression like A*B*C*D*E where A,B,C,D and E are matrices. Since matrix multiplication is associative, the order in which multiplications are performed is arbitrary. However, the number of elementary multiplications needed strongly depends on the evaluation order you choose.

For example, let A be a 50*10 matrix, B a 10*20 matrix and C a 20*5 matrix. There are two different strategies to compute A*B*C, namely (A*B)*C and A*(B*C).

The first one takes 15000 elementary multiplications, but the second one only 3500.

Your job is to write a program that determines the number of elementary multiplications needed for a given evaluation strategy.


Programme non accepte

**/
/**
Vider la pile de parentheses a chaque iteration
**/
void viderPile()
{
    while(!pile.empty()) pile.pop();

}


int main()
{
    string s;
    map<char, paire> m;     // Map qui contiendra le nom de la matrice comme cle et une paire de int pour le nb de colonne et de ligne de la matrice
    int nbmatrices,ligne,colonne,compteur(0),resultat(0);
    char nom;
    scanf("%d",&nbmatrices);

    while(nbmatrices--)
    {
        cin >>nom>>ligne>>colonne;
        m[nom]=make_pair(ligne,colonne);
    }
    /**
    Recupere des lignes (A(BC)) retourner le nombre d'operations primaires ou erreur si impossible de mutliplier les matrices
    */
    while(getline(cin,s))
    {
        s=s.c_str();    // Ca fait plus propre
        resultat=compteur=0;

        for(int i(0); i<s.length(); i++)
        {

            if(s.length()==1) printf("0\n");    // Si on a juste une matrice sur la ligne du style A

            if(s[i]=='(') ++compteur;           // On a une parenthese, on empile

            else if(s[i] == ')')                // Sinon on dépile
            {
                paire b= pile.top();
                pile.pop();
                if(pile.size()==0)              // Cas qui ne devrait pas apparaitre si on a (A)
                {
                    printf("0\n");
                    viderPile();
                    break;
                }
                paire a= pile.top();
                pile.pop();
                if(b.first != a.second)             // Si la multiplication n'est pas possible
                {
                    printf("error\n");
                    viderPile();
                    break;
                }
                resultat+=a.first * a.second * b.second;        // Effectue le calcul du nombre d'operations
                a.second=b.second;
                pile.push(a);
                --compteur;
            }
            else if(isalpha(s[i]))
            {

                pile.push(m.find(s[i])->second);                // Si c'est un caractere on l'empile a la pile


            }

            if(i==s.length()-1) printf("%d",resultat);             // Si on arrive au bout de la ligne on affiche le resultat

        }
        viderPile();

    }

    return 0;
}

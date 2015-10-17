#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
using namespace std;
 /**
Let A be an N×N matrix of zeros and ones. A submatrix S of A is any group of contiguous entries that forms a square or a rectangle.

Write a program that determines the number of elements of the largest submatrix of ones in A. Largest here is measured by area.

Programme embetant parce que l'on nous donne les éléments d'une ligne de la matrice sans nous indiquer leur nombre


**/
int main ()
{
    //freopen ("input", "r", stdin);
    int testCase;
    scanf ("%d", &testCase);
    bool space = false;
    getchar ();

    char input [25 + 3] [25 + 3];
    gets (input [0]);

    while ( testCase-- ) {

        int index = 0;

        while ( gets (input [index]) && strlen (input [index]) ) index++; // Stocke la chaine
                                                                         // dans un tableau de chaine
                                                                        // Tant que on lit et que la chaine
                                                                        // n'est pas vide

        int a [25 + 3] [25 + 3];
        /**
        Recopiage des elements dans une matrice
        **/
        for ( int i = 0; i < index; i++ )
            for ( int j = 0; j < index; j++ ){
                a [i] [j] = input [i] [j] == '1' ? 1 : 0;
                if(i>1) a [i] [j] = a [i] [j] == 1 ? a [i - 1] [j] + 1 : 0;
            }




        int maxi = INT_MIN;
        // L'algo en 0(n^4)
        for ( int i = 0; i < index; i++ ) {
            for ( int j = 0; j < index; j++ ) {
                int cnt = 1;
                for ( int k = j - 1; k >= 0 && a [i] [k] >= a [i] [j]; k-- ) cnt++;
                for ( int k = j + 1; k < index && a [i] [k] >= a [i] [j]; k++ ) cnt++;
                cnt *= a [i] [j];
                if ( maxi < cnt ) maxi = cnt;
            }
        }

        if ( space ) printf ("\n"); space = true;
        printf ("%d\n", maxi);
    }

    return 0;
}

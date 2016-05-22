#include <iostream>
#include <cstdlib>
#include<time.h>
#include <vector>
#include <stdio.h>
using namespace std;
int N;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<int>::iterator it;
#define Repp(i,a,b) \
    for(i=(int)a;i<=(int)b;i++)
#define Repm(i,a,b) \
    for(i=(int) a;i>=(int)b;i--)
#define TAILLE_TABLEAU 100

void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                 i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
        }
      };
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
        quickSort(arr, i, right);

}
int main()
{
     int i,tab[TAILLE_TABLEAU];
     srand(time());
     Repp(i,0,TAILLE_TABLEAU-1)
        tab[i]=rand(%100)+1;

     quickSort(tab,0,5);

    return 0;
}

#include <cstdio>
#include <vector>
using namespace std;
/**
Conversion d'un nombre decimal en base 3
**/
void operatoin(long long n){
      if(n/3 != 0) operatoin(n/3);
      printf("%d",n%3);

}

int main() {
    long long n;

    while(scanf("%lli",&n) && n>=0){
    operatoin(n);
    putchar('\n');

}
}

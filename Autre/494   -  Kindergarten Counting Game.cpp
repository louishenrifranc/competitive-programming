
#include <iostream>
#include <string>
/**
 Everybody sit down in a circle. Ok. Listen to me carefully.

``Woooooo, you scwewy wabbit!''

Now, could someone tell me how many words I just said?
**/
using namespace std;


int main(){
    string line;
    int cont=0;

    while(getline (cin,line)) {
          int tam =line.size();
          for(int i=0;i<tam;i++){
                  if((line[i]>='A' && line[i]<='Z')||(line[i]>='a' && line[i]<='z')){
                              cont++;
                              for(;(line[i]>='A' && line[i]<='Z')||(line[i]>='a' && line[i]<='z') && i<tam;i++){}
                  }

          }
          cout<<cont<<endl;
          cont=0;
    }

 return 0;
}

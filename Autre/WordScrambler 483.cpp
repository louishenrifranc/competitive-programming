#include <sstream>
#include <string>
#include <iostream>
using namespace std;

string strrev(string s){
/**
Inverser tous les mots d'une phrase
**/

string t(s.rbegin(), s.rend());
return t;
}


int main() {
   string s, t;
   while(!cin.eof()){
      getline(cin, s);
      istringstream buffer(s);
      while(buffer >> t){

         cout << strrev(t);
         if(!buffer.eof()) { cout << " "; }
      }
      if(!cin.eof()) cout << "\n";
   }
   return 0;
}

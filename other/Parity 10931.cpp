#include <cstdio>
#include <vector>
/**
We define the parity of an integer n as the sum of the bits in binary representation computed modulo
two. As an example, the number 21 = 10101  has three 1s in its binary representation so it has parity
3(mod2), or 1.      ---------------------------------------------------------------------------------
--------------
In this problem you have to calculate the parity of an integer 1<=I<=2147483647.
*/
int main() {
    long long I;
    while (scanf("%lld", &I), I != 0) {
        int P = 0;
        std::vector<char> out;
        while(I != 0) {  // Tant que le nombre est different de 0
            if (I & 1) {                // Si le chiffre le plus a droite vaut 1 ! A revoir
                out.push_back('1');     //
                P++;
            } else out.push_back('0');
            I = I >> 1;
        }
        printf("The parity of ");
        for (int i = out.size() - 1; i >= 0; i--) printf("%c", out[i]);
        printf(" is %d (mod 2).\n", P);
    }
}

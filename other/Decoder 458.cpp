#include<stdio.h>

static char t[1024];

int main(){
    register unsigned i;
    while(gets(t)){
        for(i = 0; t[i]; t[i] -= 7, ++i);
        puts(t);
    }
    return 0;
}

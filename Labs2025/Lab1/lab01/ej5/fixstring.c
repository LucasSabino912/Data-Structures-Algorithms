#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    nat i = 0;
    while(s[i] != '\0'){
        i++;
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    nat i = 0, j = 0;

    while(s1[i] != '\0' || s2[j] != '\0'){
        if(s1[i] == s2[i]){
            i++;
        } else {
            return false;
        }
    }

    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    nat i = 0;

    while(s1[i] != '\0' || s2[i] != '\0'){
        if(s1[i] <= s2[i]){
            i++;
        } else {
            return false;
        }
    }

    return true;
}
void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}



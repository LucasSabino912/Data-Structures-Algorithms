#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i = 0u;
    while (s[i] != '\0'){
        i++;
    }

    return i; 
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    unsigned int lengths1 = 0, lengths2;

    lengths1 = fstring_length(s1);
    lengths2 = fstring_length(s2);

    if (lengths1 != lengths2){
        return false;
    }

    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] == s2[i]){
            i++;
        } else {
            return false;
        }
    }

    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;

    if(s1 == s2){
        return false;
    }

    while (s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] < s2[i]){
            i++;
        } else {
            return false;
        }
    }
    
    return true;
}


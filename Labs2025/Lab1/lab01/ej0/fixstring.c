#include <stdbool.h>
#include <assert.h>

// Compiling:
// gcc -Wall -Werror -Wextra -pedantic -std=c99

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    nat i = 0;
    while(s[i] != '\0'){
        i++;
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    nat i = 0;

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


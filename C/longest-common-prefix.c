// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/longest-common-prefix/

    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".
*/

#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = malloc(sizeof (strsSize));

    // If only have one string, return it
    if(strsSize == 1){
        return strs[0];
    } else if (strsSize == 0){
        // Return "" if the array is empty
        return "";
    }

    prefix = strs[0]; // Initialize prefix with the first word

    // This for iterates through the strings
    for(int i = 1; i < strsSize; i++){ // Initialize i = 1 because prefix already contains the first word
        int j = 0; // Counter for the characters of each strings
        // Checks if strs did not finish and if the first character of the first word is equal to the others
        while(strs[i][j] != '\0' && prefix[j] == strs[i][j]){
            j++;
        }

        prefix[j] = '\0';

        if (strlen(prefix) == 0){
            return "";
        }
    }

    return prefix;
}
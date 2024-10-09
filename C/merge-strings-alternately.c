// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/merge-strings-alternately/

    You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
    If a string is longer than the other, append the additional letters onto the end of the merged string.

    Return the merged string.
*/

char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1); // length of word1
    int len2 = strlen(word2); // length of word2

    // Memory assignation for merged
    char* merged = malloc(len1 + len2 + 1);

    if(merged == NULL){
        printf("Memory assignation failed\n");
        exit(EXIT_SUCCESS);
    }

    int i = 0, j = 0, k = 0; // indexes

    // Alternates de characters
    while(i < len1 && j < len2){
        merged[k++] = word1[i++];
        merged[k++] = word2[j++];
    }

    // Append the remaining characters of word1
    while(i < len1){
        merged[k++] = word1[i++];
    }

    // Append the remaining characters of word2
    while(j < len2){
        merged[k++] = word2[j++];
    }

    merged[k] = '\0';

    return merged;
}
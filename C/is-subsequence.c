// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/is-subsequence/

    Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the         characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int len1 = strlen(s);
    int len2 = strlen(t);

    int i = 0, j = 0;

    while(i < len1 && j < len2){
        if(s[i] == t[j]){
            i++; // Increments only if they are equal
        }
        j++;
    }

    return len1 == i;
}
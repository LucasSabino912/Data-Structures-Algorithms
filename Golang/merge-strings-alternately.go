// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/merge-strings-alternately/

    You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
    If a string is longer than the other, append the additional letters onto the end of the merged string.

    Return the merged string.
*/

func mergeAlternately(word1 string, word2 string) string {
    merged := ""
    i, j := 0, 0
    
    for i < len(word1) && j < len(word2){
        merged += string(word1[i]) + string(word2[j])
        i++
        j++
    }

    for i < len(word1){
        merged += string(word1[i])
        i++
    }

    for j < len(word2){
        merged += string(word2[j])
        j++
    }  

    return merged
}
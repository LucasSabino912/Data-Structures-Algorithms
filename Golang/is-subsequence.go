// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/is-subsequence/

    Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the         characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

func isSubsequence(s string, t string) bool {
    i, j := 0, 0

    for i < len(s) && j < len(t) {
        if s[i] == t[j] {
            i++ // Increments only if they are equal
        }
        j++
    }
    
    return len(s) == i
}
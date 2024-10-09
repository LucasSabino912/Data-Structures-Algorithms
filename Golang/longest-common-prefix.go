// https://github.com/LucasSabino912

/*
    https://leetcode.com/problems/longest-common-prefix/

    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".
*/

func longestCommonPrefix(strs []string) string {
    if len(strs) == 1 {
        return strs[0]
    }

    sort.Strings(strs)

	length := len(strs)
	for i := range(strs[0]) {
		if strs[0][i] != strs[length - 1][i] {
			return strs[0][:i]
		}
	}

	return strs[0]
}
/*
Longest Repeating Subsequence
Given a string, find length of the longest repeating subseequence
such that the two subsequence don’t have same string character at same position,
i.e., any i’th character in the two subsequences shouldn’t have
the same index in the original string.

Examples:
Input: str = "abc"
Output: 0
There is no repeating subsequence

Input: str = "aab"
Output: 1
The two subssequence are 'a'(first) and 'a'(second).
Note that 'b' cannot be considered as part of subsequence
as it would be at same index in both.

Input: str = "aabb"
Output: 2

Input: str = "axxxy"
Output: 2
*/

class Solution {
public:
    /**
     * @param str a string
     * @return the length of the longest repeating subsequence
     *
     * 思路：
     * 1. 转化给两个string的longest common sequence
     * 2. 在一般lcs算法上加一些限制：相同位置相同字符不算。
     * 3. 递推关系：
     *      LRS[i][j] = LRS[i-1][j-1] + 1, if: str[i] == str[j] && i!=j
     *      else: LRS[i][j] = max(LRS[i][j-1], LRS[i-1][j])
     *
     *      e.g LRC("aab","aab") = max {LRS("aab","aa"),LRS("aa","aab")}
     *          = max {max{LRS("aab","a"),LRS("aa","aa"},
     *                 max{LRS("a","aab"),LRS("aa","aa")}
     *                 =1
     *    对比（longest common subsequence)递推关系：
     *          lcs(i,j) = lcs(i,j)+1 , if a(i) = b(j)
     *          else lcs(i,j) = max{ lcs(i,j-1), lcs(i-1,j) }
     * 4. space还可以优化
     *
     */
    int longestRepeatingSubsequence(string& str) {
        vector<vector<int>> LRS(str.size()+1,vector<int>(str.size()+1,0));

        for (int i = 1; i <= str.size(); i++) {
            for (int j = 1; j <=str.size(); j++) {
                if (str[i-1] == str[j-1] && i!=j) {
                    LRS[i][j] = LRS[i-1][j-1] + 1;
                } else {
                    LRS[i][j] = max(LRS[i][j-1], LRS[i-1][j]);
                }
            }
        }
        return LRS[str.size()][str.size()];
    }
};
/*Longest Common Subsequence

Description

Given two strings, find the longest common subsequence (LCS).

Your code should return the length of LCS.

Clarification
What's the definition of Longest Common Subsequence?

https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
        http://baike.baidu.com/view/2020307.htm
Example
For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.

For "ABCD" and "EACB", the LCS is "AC", return 2.
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     *
     * 基本递推关系（注意和longest common substring的区别）
     *  lcs(i,j) = lcs(i,j)+1 , if a(i) = b(j)
     *   else lcs(i,j) = max{ lcs(i,j-1), lcs(i-1,j) }
     *
     * 注意：
     * 1. subsequence可以不连续
     * 2. 定义和解法longest common substring（下面是递推关系）
     * lcs(i,j) = lcs(i-1,j-1)+1    if A(i) = B(j)
     *             =0               if A(i) != B(j)
     */
    int longestCommonSubsequence(string A, string B) {

        // lcs(i,j) : longest common subsequence until (i,j)
        // all init to 0
        // 合理性判断（按照递推关系要求的初始化）
        // 1. LCS("a","a")= LCS("","")+1 = 1, 合理
        // 2. LCS("aaa","")= 0, 合理
        // 3. LCS("","aaa")= 0, 合理

        vector<vector<int>> LCS(A.size()+1, vector<int>(B.size()+1, 0));

        for ( int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i-1] == B[j-1]) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                } else {
                    LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
                }
            }
        }

        return LCS[A.size()][B.size()];
    }
};


class Solution_space_optimized {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     *
     * 空间优化：
     * 递推公式显示：lcs（i，j）依赖于 lcs(i-1,j-1), lcs(i,j-1), lcs(i-1,j)
     * 计算是逐行计算的，对于某一行而言，其计算依赖于上一行和本行，而且上一行计算完了后就可以丢弃
     * 所以，空间只需要两行即可。
     *
     */
    int longestCommonSubsequence(string A, string B) {
        // 只需要两行，以前是A.size()＋1行
        vector<vector<int>> LCS(2, vector<int>(B.size()+1, 0));

        for ( int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i-1] == B[j-1]) {
                    LCS[1][j] = LCS[0][j-1] + 1;
                } else {
                    LCS[1][j] = max(LCS[0][j],LCS[1][j-1]);
                }
            }
            copy(LCS[1].begin(), LCS[1].end(),LCS[0].begin());
        }

        return LCS[1][B.size()];
    }
};



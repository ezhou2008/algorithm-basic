/*Longest Common Substring

Description

Given two strings, find the longest common substring.

Return the length of it.

Notice

The characters in substring should occur continuously in original string.
This is different with subsequence.

Example
Given A = "ABCD", B = "CBCE", return 2.

Challenge
O(n x m) time and memory.*/

class Solution {
public:

    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     *
     * 1. 定义lcs(i,j)为**包括***（i,j)位置在内的longest common substring
     *    e.g. lcs("ab", "ab") = 2, lcs("abc", "abd") = 0
     *
     * 2. 递推关系
     * lcs(i,j) = lcs(i-1,j-1)+1    if A(i) = B(j)
     *             =0               if A(i) != B(j)
     *
     * 3. 最后的结果是 lcs(i,j)中最大者
     *
     * 4. 如果lcs(i,j)定义为题目要求的longest common substring的话，则不好递推
     *
     * 注意：
     * 1. substring需要连续
     * 2. 定义和解法longest common subsequnce的区别（下面是递推关系）
     *   lcs(i,j) = lcs(i,j)+1 , if a(i) = b(j)
     *   else lcs(i,j) = max{ lcs(i,j-1), lcs(i-1,j) }
     *
     */

    int longestCommonSubstring(string &A, string &B) {

        // LCS(i,j) = common substr including char at i and j
        // all init to 0 in the meantime
        vector<vector<int>> LCS(A.size()+1, vector<int>(B.size()+1,0));

        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i-1] == B[j-1]) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                } else {
                    LCS[i][j] = 0;
                }
            }
        }

        // find max of all LCS(i,j)
        int LCS_max = 0;
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                LCS_max = max(LCS_max, LCS[i][j]);
            }
        }
        return LCS_max;
    }
};


class Solution_space_optimized {
public:

    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     *
     * 在下面的solution上优化空间
     * 由于基本的递推关系为lcs(i,j) = lcs(i-1,j-1) +1, 也就是说lcs(i,j)仅仅依赖于lcs(i-1,j-1)
     *
     *                   j->
     *         | 0  | 1  | 2  | 3  | 4 |  5 |
     *   ------|----|----|----|----|---|----|--
     *      0  |  0 |  0 |  0 |  0 | 0 |  0 |
     * i ------|----|----|----|----|---|----|--
     *      1  |  0 |    |    |    |   |    |
     *   ------|----|----|----|----|---|----|---
     *      2  |  0 |    |    |    |   |    |
     *   ------|----|----|----|----|---|----|---
     *      3  |  0 |    |    |    |   |    |
     *   ------|----|----|----|----|---|----|---
     *      4  |  0 |    |    |    |   |    |
     *
     *
     *  如上图，计算是一行一行的进行，一行的每个元素仅仅取决于其左上角（上一行）元素，而且每一行计算完了之后就可以丢弃，
     *  所以空间可以优化为上面二维数组的一行。
     *
     */
    int longestCommonSubstring(string &A, string &B) {

        // LCS(i,j) = common substr including char at i and j
        vector<int> LCS(B.size()+1,0);

        // find max of all LCS(i,j)
        int LCS_max = 0;
        for (int i = 1; i <= A.size(); i++) {
/*
            注意j必须倒着计算
*/
            for (int j = B.size(); j >= 1; j--) {
                if (A[i-1] == B[j-1]) {
                    LCS[j] = LCS[j-1] + 1;
                } else {
                    LCS[j] = 0;
                }
                LCS_max = max(LCS_max, LCS[j]);
            }
        }

        return LCS_max;
    }
};




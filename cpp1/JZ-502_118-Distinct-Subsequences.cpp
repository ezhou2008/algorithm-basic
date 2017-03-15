/*Distinct Subsequences

Description
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string
by deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE"
while "AEC" is not).

Example
Given S = "rabbbit", T = "rabbit", return 3.

Challenge
Do it in O(n2) time and O(n) memory.

O(n2) memory is also acceptable if you do not know how to optimize memory.
*/

class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     *
     * 需要增加空子串
     *
     * */
    int numDistinct(string &S, string &T) {
/* Given a string S and a string T, count the number of distinct subsequences of T in S.
 * 简单翻译一下，给定两个字符串S和T，求S有多少个不同的子串与T相同。
        S的子串定义为在S中任意去掉0个或者多个字符形成的串。

        if source[i] == target[j]
            比如： s = rbb t = rb －> ND(rbb,rb) = ND(rb,r) + ND(rb,rb)
                  -> f(i,j) = f(i-1,j-1) + f(i-1,j)
        else:
            比如： s= rba t=rb, -> ND(rba,rb) = ND(rb,rb)
                  -> f(i,j) = f(i-1,j)
*/
        // 定义：ND(i,j) = number of distinct of source(0..i)/target(0...j)
        vector <vector<int>> ND(S.size() + 1, vector<int>(T.size() + 1, 0));

        // init: S = empty，t = empty
        // s="a", t="a" -> f("a","b)= f("","")+f("","b") = 1＋0 ＝ 1 合理
        ND[0][0] = 1;

        // for (int ti = 1; ti <= T.size(); ti++) {  //already initialized
        //     ND[0][ti] = 0;
        // }
        //init: T = empty, S has empty string as its subsequence which is equal to T
        // 同ND[0][0], 这么定义的也是合理
        for (int si = 1; si <= S.size(); si++) {
            ND[si][0] = 1;
        }

        // function
        for (int si = 1; si <= S.size(); si++) {
            for (int ti = 1; ti <= T.size(); ti++) {
                if (S[si - 1] != T[ti - 1]) {
                    ND[si][ti] = ND[si - 1][ti];
                } else {
                    ND[si][ti] = ND[si - 1][ti - 1] + ND[si - 1][ti];
                }
            }
        }

        // answer
        return ND[S.size()][T.size()];
    }
};

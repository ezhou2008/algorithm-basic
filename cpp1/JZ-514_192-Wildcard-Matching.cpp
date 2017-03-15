/*Wildcard Matching

Description
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/


class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     *
     * 基本原理：
     *      两个字符串逐字符进行比较，所有一样即为match(包括长度），在此基础上考虑 "?"和"*"
     * 要点：
     * 1. 对于一般字符，如果source[i] == pattern[j]，是否match就取决前面（i-1,j-1)是否match
     * 2. 对于?，和一般字符一样，只是可以匹配任何字符
     * 3. "*"有3种情况：
     *     3.1  匹配空：      a 和 a*       : 此时match(i,j) = match(i,j-1)
     *     3.2  匹配一个：    ab 和 a*      : 此时match(i,j) = match(i-1,j-1)
     *     3.3  匹配两个：   abc 和 a*     : 此时match(i,j) = match(i-1,j)
     *     3.4  匹配多个：   abcdef和a*  ：    和3.3一样：
     *          因为：f(abcdef,a*) = f(abcde,a*) = f(abcd,a*) = f(abc,a*)
     *
     *          如果写成另外的递推形式就比较复杂，比如：
     *          f(abcdef,a*) = f(abcde,a) or f(abcd,a) or f(abc,a) or f(ab,a) or f(a,a)
     *          这样的话，就多了一重循环，所以递归形式很重要。
     *
     * 4. 关于初始化：
     *      如果不人为增加在source和patten前增加空字符的话，初始化就会很复杂，几乎不可能做对（Soulution2)
     *      实际解题过程中，如果不增加初始化也好些，就不增加。实在觉得复杂，就增加虚拟行列
     *      九章的说法：如果不是和坐标相关的动态规划，一般需要增加0位置作为初始化
     *
     *
     */
    bool isMatch(const char *source, const char *patten) {

        int s_len = strlen(source);
        int p_len = strlen(patten);

        // state: M(s,p) = matched or not
        //          s= source index, p= pattern index
        vector <vector<bool>> matched(s_len + 1, vector<bool>(p_len + 1, false));

        //init，source and patten are empty
        // "a"和"a"比较的话，会缩小到empty和empty的比较，设置为true是合理的
        matched[0][0] = true;

        for (int p = 1; p <= p_len; p++) {
            if (patten[p - 1] == '*') {
                matched[0][p] = matched[0][p - 1];
            } // else == false as initialized（一般字符，＊）
        }

//        对于patten为空的情况，已初始化
//       for (int s = 1; s <= s_len; s++) {
//            matched[s][0] = false;
//        }


        for (int s = 1; s <= s_len; s++) {
            for (int p = 1; p <= p_len; p++) {
                if (source[s - 1] == patten[p - 1] || patten[p - 1] == '?') {
                    matched[s][p] = matched[s - 1][p - 1];
                } else if (patten[p - 1] == '*') {
                    matched[s][p] = matched[s][p - 1] | matched[s - 1][p - 1] | matched[s - 1][p];
                } else {
                    //skipped
                }
            }
        }

        //answer
        return matched[s_len][p_len];
    }
};

class Solution2 {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     *
     * 不增加空字符，初始化能复杂
     */
    bool isMatch(const char *source, const char *patten) {

        int s_len = strlen(source);
        int p_len = strlen(patten);

        if (s_len == 0 && p_len ==0) return true;

        if (s_len == 0) {
            if (strcmp(patten,"*") == 0) {
                return true;
            } else {
                return false;
            }
        }

        if (p_len == 0) return false;

        // state: M(s,p) = matched or not
        //          s= source index, p= pattern index
        vector<vector<bool>> matched(s_len, vector<bool>(p_len, false));

        //init
        if (source[0] == patten[0] | patten[0] == '?' || patten[0] == '*') {
            matched[0][0] = true;
        }

        for (int p = 1; p < p_len; p++) {
            if (patten[p] == '*'||(patten[p] == '?' && patten[p-1] == '*')) {
                matched[0][p] = matched[0][p-1];
            }
        }

        for (int s = 1; s < s_len; s++) {
            if ( patten[0] == '*' ) {
                matched[s][0] = matched[s-1][0];
            }
        }

        for (int s = 1; s < s_len; s++) {
            for (int p = 1; p < p_len; p++) {
                if (source[s] == patten[p] || patten[p] == '?') {
                    matched[s][p] = matched[s-1][p-1];
                } else if ( patten[p] == '*' ) {
                    matched[s][p] = matched[s][p-1] | matched[s-1][p-1] | matched[s-1][p];
                } else {
                    //skipped
                }
            }
        }

        //answer
        return matched[s_len-1][p_len-1];
    }
};
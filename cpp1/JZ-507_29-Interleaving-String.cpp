/*
Interleaving String

Description
Given three strings: s1, s2, s3, determine whether s3 is
formed by the interleaving of s1 and s2.

Example
For s1 = "aabcc", s2 = "dbbca"

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Challenge
O(n2) time or better
*/


class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     *
     * 递推关系
     * 1.  s1.size + s2.size == s3.size 否则肯定为false
     * 2.  IL(i,j) 只有当下面条件满足才为true，否则为false：
     *          a. (s3[i+j-1] == s1[i-1]) && IL[i-1][j]) 或者
     *          b. (s3[i+j-1] == s2[j-1]) && IL[i][j-1]
     *     也就是：检测s3最后一个char，看是否等于s1最后一个，是的话进一步判断，
     *     不是的话，再看是否等于s2最后一个。
     * 3. 注意：s1, s2,s3序号一致，和IL差1（IL添加虚拟行列）
     */
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> IL(s1.size()+1, vector<bool>(s2.size()+1, false));

        IL[0][0] = true;
        for (int j = 1; j <= s2.size(); j++) {
            IL[0][j] = (IL[0][j-1] && s2[j-1] == s3[j-1]);
            // 下面写法也是可以的，推荐上面的写法，和递推关系一致
            // IL[0][j] = (s2.substr(0,j) == s3.substr(0,j));

        }
        for (int i = 1; i <= s1.size(); i++) {
            IL[i][0] = (IL[i-1][0] && s1[i-1] == s3[i-1]);
        }

        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {

/*            递推关系*/
                 IL[i][j] = ((s3[i+j-1] == s1[i-1]) && IL[i-1][j]) ||
                     ((s3[i+j-1] == s2[j-1]) && IL[i][j-1]);

/*               下面这种写法是不对的，逻辑上和递推关系不一样
 *               if (s3[i+j-1] == s1[i-1]) {
                    IL[i][j] = IL[i-1][j];
                }
                else if (s3[i+j-1] == s2[j-1]) {
                    IL[i][j] = IL[i][j-1];
                }
*/
/*
 *              下面这种写法也是不对的，else if 改成 else就对了，因为是"或"的关系
 *              if (s3[i+j-1] == s1[i-1]) {
                    if  (IL[i-1][j]) {
                        IL[i][j] = true;
                    }
                } else if (s3[i+j-1] == s2[j-1]) {
                    if (IL[i][j-1]) {
                        IL[i][j] = true;
                    }
                }*/

            }
        }

        return IL[s1.size()][s2.size()];

    }
};
/*Word Break

Description

Given a string s and a dictionary of words dict,
determine if s can be break into a space-separated sequence
of one or more dictionary words.

Example
Given s = "lintcode", dict = ["lint", "code"].
Return true because "lintcode" can be break as "lint code".
*/


class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     *
     * 1. 递推关系的形成如下
     *  在source_str(0..i-1) 基础上增加source_str[i],
     *      其中［ab］需要判断是否一个word，ab，abc等表示已递推出来的结果
     *  a => a
     *  ab => +[ab], a+[b]
     *  abc => +[abc], a+[bc], ab+[c]
     *  abcd => +[abcd], a+[bcd], ab+[cd], abc+[d]
     *  可以看出：
     *      source（0..i)是否是breakable，取决于source[0,j-1]是否beakable和source[j-i]是否是word
     *      j=[0,i]
     *
     *  2. 优化
     *     由于word的长度有限，可以找出最大word长度，这样j可以不必从0开始
     *     0______j___max_word_len___i
     */
    bool wordBreak(string source_s, unordered_set<string> &dict) {
        // find out max len
        int max_w_len = 0;
        for (const auto &word : dict) {
            max_w_len = max((int)word.size(), max_w_len);
        }
        // state： 1. all init to false,  2. 虚拟第一个为empty string
        vector<int> breakable(source_s.size()+1, false);
        // source 为空，比如：ab，如果ab为dictionary word, 最后会递推到empty string
        // 显然，这种情况下，empty string定义为true是合理的
        breakable[0] = true;

        for (int i = 1; i <= source_s.size(); i++) {
//            注意：如果i比较小的话，j还是要从1开始的
            int j_left = (i>=max_w_len)?(i - max_w_len + 1):1;
            for ( int j = j_left; j <=i ; j++) {
                string word_right = source_s.substr(j-1,i-j+1);
                if (dict.find(word_right) != dict.end()) {
                    if (breakable[j-1]) {
                        breakable[i] = true;
                        break;
                    }
                }
            }
        }
        return breakable[source_s.size()];
    }
};
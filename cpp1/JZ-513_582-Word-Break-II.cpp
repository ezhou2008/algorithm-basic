/*Word Break II

Description
Given a string s and a dictionary of words dict,
add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Example
Gieve s = lintcode,
dict = ["de", "ding", "co", "code", "lint"].

A solution is ["lint code", "lint co de"].


 */

/*

             ________ |_| ________________________________
            |                           |        |       |
         ___a|bcd__________          ___ab|cd_   abc|d_   abcd|
         |        |        |         |        |        |
     ____b|cd_     bc|d     bcd|     c|d      cd|      d|
    |        |
    c|d      cd|
   |
   d|

 */


class Solution_dfs_divide&conquer {
public:
    /**
     * @param s a string
     * @param wordDict a set of words
     *
     * 1. 使用标准的dfs + divide&conquer，搜索tree如上图，
     * 总共2^n中可能性，对应搜索树从root 到leaf的2^3=8条路径
     * 2. 这种方法比dfs + backtracking要简洁，容易记住些（目前推荐采用这个方法）
     *
     */
    vector<string> wordBreak(string source_s, unordered_set<string> &dict) {
        //word string到 vector<string>的map，不然会超时
        unordered_map<string,vector<string>> wd_sen_map;
        return WB_helper(source_s, dict,wd_sen_map);
    }

    vector<string> WB_helper(string src,unordered_set<string> &dict,
                             unordered_map<string,vector<string>> &wd_sen_map) {

        vector<string> result;
        auto it = wd_sen_map.find(src);
        if (it !=wd_sen_map.end()) {
            return (*it).second;
        }

        for(int p_len = 1; p_len <= src.size(); p_len++) {
/*
            将string分成两部分，left部分判断是否in dictionary
            如果left in dict, 则right部分进一步递归迭代，否则忽略
*/
            string left = src.substr(0,p_len);
            string right = src.substr(p_len, src.size()-p_len);
            if (dict.find(left) != dict.end()) {
/*              1. 到叶子节点（不管哪个level都一样），不需要进一步divide
                2. 另外，也可以再进一步divide，这样的话，下一不src就为empty（同dfs＋backtracking）
                然后，再function 的最前面判断src是否是空，是空的话，就直接返回空
                这种办法有个问题，就是没法区分返回的空是在叶子节点下一步返回，还是非叶子节点返回，
                返回的时候就需要另外标志来区分，麻烦些
                为什么没法区分的原因是divide and conquer 是bottom up 中间节点和叶子节点的下一节点均返回空
                如果是dfs从上到下是可以的，因为从上到下，只有到叶子节点才处理（把路径加入到result）
                */
                if (p_len == src.size()) {
                    result.push_back(left);
                } else {
                    vector<string> result_r = WB_helper(right, dict,wd_sen_map);
/*                  将left 和 result_r返回组合后，
                    如left = "lint", result_r ={"co de", "code"}, result = {"ling co de", "lint code"}*/
                    // 如果result_r 为空，就不用加入（此时为非叶子节点，不breakable，中途返回的）
                    for (auto &item : result_r) {
                        item = left + " "+ item;
                        result.push_back(item);
                    }
                }
            }
        }
        wd_sen_map[src] = result;
        return result;
    }
};

class Solution_dfs_backtracking_dp {
public:
    /**
     * @param s a string
     * @param wordDict a set of words
     *
     * 使用标准的dfs + backtracking，搜索tree如上图，
     * 总共2^n中可能性，对应搜索树从root 到leaf的2^3=8条路径
     *
     */
    vector <string> wordBreak(string source_s, unordered_set <string> &dict) {
        int max_w_len = 0;
        for (const auto &word : dict) {
            max_w_len = max((int) word.size(), max_w_len);
        }
        vector <string> result;
        vector <string> prefix_l;
        WB_helper(source_s, dict, max_w_len, prefix_l, result);
        // wordBreakUtil(source_s, (int)source_s.size(), dict, cur_res,result);
        return result;

    }

    void WB_helper(string src, unordered_set <string> &dict, int max_l,
                   vector <string> &prefix_list, vector <string> &result) {
/*
        基本case，src为空，说明到叶子节点，此路径可用，将路径添加到结果
*/
        if (src.empty()) {
            string cur_res;
            for (const auto &p : prefix_list) {
                cur_res += p;
                cur_res += " ";
            }

            if (!cur_res.empty()) {
                cur_res.pop_back();
                result.push_back(cur_res);
                return;
            }
        }

/*       利用 wordbreak的结果判断word是否breakable，不然会超时
        这个放在basic case后面，是用wordbreak的结果里空字符串为true，会导致可用的路径不添加  */
        if (!wordBreakalbe(src, dict)) return;

        for (int p_len = 1; p_len <= src.size() && p_len <= max_l; p_len++) {
/*
            将string分成两部分，left部分判断是否in dictionary
            如果left in dict, 则right部分进一步递归迭代，否则忽略
*/
            string left = src.substr(0, p_len);
            string right = src.substr(p_len, src.size() - p_len);
            if (dict.find(left) != dict.end()) {
/*                将left加入prefix，
                如果没有搜索到叶子节点，说明这种break，不能make sentence，
                prefix 将会被discard，因为只有到叶子节点prefix才会加入到result 里
*/
                prefix_list.push_back(left);
                WB_helper(right, dict, max_l, prefix_list, result);
//                prefix回退
                prefix_list.pop_back();
            }
        }
    }

/*
    使用dp判断string是否breakable
*/
    bool wordBreakalbe(string source_s, unordered_set <string> &dict) {
        // find out max len
        int max_w_len = 0;
        for (const auto &word : dict) {
            max_w_len = max((int) word.size(), max_w_len);
        }
        // state： 1. all init to false,  2. 虚拟第一个为empty string
        vector<int> breakable(source_s.size() + 1, false);
        // source 为空，比如：ab，如果ab为dictionary word, 最后会递推到empty string
        // 显然，这种情况下，empty string定义为true是合理的
        breakable[0] = true;

        for (int i = 1; i <= source_s.size(); i++) {
//            注意：如果i比较小的话，j还是要从1开始的
            int j_left = (i >= max_w_len) ? (i - max_w_len + 1) : 1;
            for (int j = j_left; j <= i; j++) {
                string word_right = source_s.substr(j - 1, i - j + 1);
                if (dict.find(word_right) != dict.end()) {
                    if (breakable[j - 1]) {
                        breakable[i] = true;
                        break;
                    }
                }
            }
        }
        return breakable[source_s.size()];
    }
};

class Solution_dfs_noBacktracking {
public:
    // 1. prefix_list 传值
    void WB_helper(string src, unordered_set <string> &dict, int max_l,
                   vector <string> prefix_list, vector <string> &result) {

        if (src.empty()) {
            string cur_res;
            for (const auto &p : prefix_list) {
                cur_res += p;
                cur_res += " ";
            }
            if (!cur_res.empty()) {
                cur_res.pop_back();
                result.push_back(cur_res);
                return;
            }
        }

        for (int i = 0; i < src.size() && i < max_l; i++) {
            string left = src.substr(0, i + 1);
            string right = src.substr(i + 1, src.size() - 1 - i);
            if (dict.find(left) != dict.end()) {
                vector <string> prefix_l_bak = prefix_list;
                // 2. 递归的函数传入的是prfix的copy
                prefix_l_bak.push_back(left);
                WB_helper(right, dict, max_l, prefix_l_bak, result);
                // prefix_list.pop_back();
            }
        }
    }
};

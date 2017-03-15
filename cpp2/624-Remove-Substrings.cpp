/*Remove Substrings

Description
        Notes
Testcase
        Judge
Given a string s and a set of n substrings. You are supposed to remove
every instance of those n substrings from s so that s is of the minimum
length and output this minimum length.

Have you met this question in a real interview? Yes
        Example
Given s = ccdaabcdbb, substrs = ["ab", "cd"]
Return 2

Explanation:
        ccdaabcdbb -> ccdacdbb -> cabb -> cb (length = 2)

Tags
        String Amazon*/

class Solution {
public:
    /**
     * @param s a string
     * @param dict a set of n substrings
     * @return the minimum length
     */
    int minLength(string& s, set<string>& dict) {
        // Write your code here
        queue<string> s_q;
        unordered_set<string> s_set;

        int min_len = INT_MAX;
        s_q.push(s);
        s_set.insert(s);
        while (!s_q.empty()) {
            string cur_s = s_q.front();
            s_q.pop();
            min_len = min(min_len, (int)cur_s.size());

            for (auto dict_ele : dict) {
                // find out all occurance of dict_ele in cur_s,
                // remove to get new string, insert new_s to queue/hash if not duplicated
                int n_pos = cur_s.find(dict_ele);
                while (n_pos != string::npos) {
                    // one occurence found
                    string new_str = cur_s.substr(0,n_pos) +
                                     cur_s.substr(n_pos+dict_ele.size(), cur_s.size()-dict_ele.size()-n_pos);
                    if (s_set.find(new_str) == s_set.end()) {
                        s_q.push(new_str);
                        s_set.insert(new_str);
                    }
                    // continue to search
                    n_pos = cur_s.find(dict_ele, n_pos+1);
                }
            }
        }
        return min_len;
    }
};

class Solution_TLE {
public:
    /**
     * @param s a string
     * @param dict a set of n substrings
     * @return the minimum length
     */
    int minLength(string& s, set<string>& dict) {
        // write your code here
        int min_len = INT_MAX;
        unordered_set<string> s_set;
        s_set.insert(s);
        while (!s_set.empty()) {
            string cur_s = *s_set.begin();
            min_len = min(min_len,(int)cur_s.size());
            s_set.erase(s_set.begin());

            bool existed = false;
            for (auto ele_dict : dict) {
                if (s.find(ele_dict) != string::npos) {
                    existed = true;
                    break;
                }
            }
            if (!existed) {
                continue;
            }

            vector<string> prefix;
            vector<bool> flags;
            helper(cur_s, 0, prefix,flags, s_set,dict);
/*            for (auto ele_str : s_set) {
                cout << ele_str << endl;
            }*/
        }

        return min_len;
    }
    void helper(string s, int p_pos, vector<string>& prefix, vector<bool> flags, unordered_set<string>& result,set<string>& dict) {
        if (p_pos==s.size()) {
            string tmp;
            bool found = false;
            for (int i=0;i<prefix.size();i++) {
                if (flags[i]) {
                    found = true;
                    continue;
                } else {
                    tmp += prefix[i];
                }
            }
            if (found) {
                // cout << tmp << endl<<endl;
                result.insert(tmp);
            }
            return;
        }
        for(int i=p_pos; i<s.size(); i++) { //partition right after index i
            string sub = s.substr(p_pos, i-p_pos+1);
            if (dict.find(sub) != dict.end()) {
                flags.push_back(true);
            } else {
                flags.push_back(false);
            }
            prefix.push_back(sub);
            helper(s, i+1, prefix,flags, result,dict);
            prefix.pop_back();
            flags.pop_back();
        }
    }
};
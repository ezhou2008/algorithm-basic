/*
Palindrome Partitioning II

Description
Given a string s, cut s into some substrings such that every substring is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example
Given s = "aab",

Return 1 since the palindrome partitioning ["aa", "b"] could be produced using 1 cut.
*/



class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     *
     * 1. 此方案会time out
     *
     *  1. 递推关系的形成如下
     *  在source_str(0..i-1) 基础上增加source_str[i],
     *      其中［ab］需要判断是否是palindrome，ab，abc等表示已递推出来的结果
     *  a => a
     *  ab => +[ab], a+[b]
     *  abc => +[abc], a+[bc], ab+[c]
     *  abcd => +[abcd], a+[bcd], ab+[cd], abc+[d]
     *  可以看出：
     *      source（0..i)的min-cut，是source[0,j-1]中的最小＋1（前提是：source[j-i]是parlindrome）
     *      j=[0,i]
     *
     */
    int minCut(string src_str) {

        // state
        vector<int> MC(src_str.size()+1, INT_MAX);
        // init, "a"的cut ＝ 0， 递推关系是MC[j-1] + 1, 所有mc[0]设置为－1
        MC[0] = -1;

        for (int i = 1; i <=src_str.size(); i++) {
            for (int j=1; j<=i; j++) {
                // check if src_str[j..i]部分是否是palindrome
                if (is_palindrome(src_str.substr(j-1, i-j+1))) {
                    MC[i] = min(MC[i], MC[j-1]+1);
                }
            }
        }
        return MC[src_str.size()];
    }

    // bool is_palindrome(string s) { //这种判断方法需要改进
    //     string tmp_str(s.rbegin(), s.rend());
    //     if (tmp_str == s) return 1;
    //     else return 0;
    // }

    // decide if str is palindrome or not
    bool is_palindrome(const string& source_s)
    {
        if (source_s.size() <=1) return true;
        for ( int i = 0, j = source_s.size() -1; i<=j; i++, j--){
            if (source_s[i] != source_s[j]) return false;
        }
        return true;
    }

};

class Solution_time_optimized {
public:
    /**
     * @param s a string
     * @return an integer
     *
     *  此方案会不会time out
     *
     *  1. minCut递推关系的形成如下
     *  在source_str(0..i-1) 基础上增加source_str[i],
     *      其中［ab］需要判断是否是palindrome，ab，abc等表示已递推出来的结果
     *  a => a
     *  ab => +[ab], a+[b]
     *  abc => +[abc], a+[bc], ab+[c]
     *  abcd => +[abcd], a+[bcd], ab+[cd], abc+[d]
     *  可以看出：
     *      source（0..i)的min-cut，是source[0,j-1]中的最小＋1（前提是：source[j-i]是parlindrome）
     *      j=[0,i]
     *
     *  2. 判断一个str的所有组合是否是palindrome也可以用dp
     *     递推关系：str[i..j]是否是palindrome: p[i,j]=p[i+1,j-1] if str[i] == str[j]
     *     e.g:
     *          a   b   b   a
     *          0   1   2   3
     *          --------------
     *    a 0 | 1   0   0   1
     *    b 1 |     1   1   0
     *    b 2 |         1   0
     *    a 3 |             1
     *
     *    先init 斜线：(0,0),(1,1),(2,2),(3,3)  -> word len = 0
     *    再init 斜线：(0,1),(1,2),(2,3)    -> word len = 1
     *    再计算：斜线：(0,2),(1,3)    -> word len = 2
     *    再计算：斜线：(0,3)  -> word len = 3
     */
    int minCut(string src_str) {

/*
        这里也可以不提前给all_palindrome分配空间，赋值是和自动分配，但效率是否会比提前分配差？？
        answer：不会。会使用vector的move assignment操作直接把返回的vector的资源move到新的vector
        也就是copy指针，资源保留，不重新分配
        如果新的vector已经分配了空间的话，move assignment会先释放此空间，然后move老的对象资源到新对象，
        这样看的话，还是不提前分配资源为好。
*/
//      vector<vector<bool>> all_palindrome(src_str.size(),
//                                            vector<bool>(src_str.size(), false));
        vector<vector<bool>> all_palindrome;
        all_palindrome = get_palindrome(src_str);

        // init =1
        vector<int> MC(src_str.size()+1, INT_MAX);
        MC[0] = -1;

        for (int i = 1; i <=src_str.size(); i++) {
            for (int j=1; j<=i; j++) {
                // check if src_str[j..i]部分是否是palindrome
                if (all_palindrome[j-1][i-1]) {
                    MC[i] = min(MC[i], MC[j-1]+1);
                }
            }
        }
        return MC[src_str.size()];
    }

    vector<vector<bool>> get_palindrome(const string& src) {

        // all init to false
        vector<vector<bool>> all_palindrome(src.size(), vector<bool>(src.size(), false));

        //init: word length = 0
        for (int i = 0; i < src.size(); i++) {
            all_palindrome[i][i] = true;
        }

        //init: word length = 1;
        for (int i = 0; i < src.size()-1; i++) {
            all_palindrome[i][i+1] = (src[i]==src[i+1]);
        }

        // p(i,j) = p(i+1, j-1) if src(i) == s(j)
        for ( int len = 2; len < src.size() ; len++) {
            for (int i = 0; i < src.size()-len; i++) {
//                判断［i，i+len]部分是否是palindrome
                if (src[i] == src[i+len]) {
                    all_palindrome[i][i+len] = all_palindrome[i+1][i+len-1];
                }
            }
        }
        return all_palindrome;
    } // end of function

};


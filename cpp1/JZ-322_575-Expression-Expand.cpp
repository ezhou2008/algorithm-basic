/*Expression Expand

Description
Given an expression s includes numbers, letters and brackets.
Number represents the number of repetitions inside the brackets
(can be a string or another expression)．Please expand expression to be a string.

Example
s = abc3[a] return abcaaa
        s = 3[abc] return abcabcabc
        s = 4[ac]dy, return acacacacdy
        s = 3[2[ad]3[pf]]xyz, return adadpfpfpfadadpfpfpfadadpfpfpfxyz

Challenge
Can you do it without recursion?
*/


class Solution_recommend {
public:
    /**
     * @param s  an expression includes numbers, letters and brackets
     * @return a string
     */
    string expressionExpand(string& s) {
        string result;
        if (s.size() == 0) return result;

        stack<string> str_stack;

        int left = 0;
        string num_str;
        string letters;
        while( left < s.size()) {
            if ( isdigit(s[left]) ) {
                num_str.push_back(s[left]);
            } else if ( s[left] == '[' ) {
                // push letters before "[" into stack, 必须在push num前面
                if ( !letters.empty() ) {
                    str_stack.push( letters );
                    // 必须clear to empty
                    letters.clear();
                }
                // push numbers before "[" into stack
                // e.g. abc3[a], 先push "abc", 后push "3"
                if ( !num_str.empty() ) {
                    str_stack.push( num_str );
                    // 必须clear to empty
                    num_str.clear();
                }
                //push '[' into stack
                string tmp = s.substr(left, 1);
                str_stack.push(tmp);
            } else if ( isalpha(s[left]) ) {
                letters.push_back( s[left] );
            } else if ( s[left] == ']' ) {
                // push letters between "[" and "]" into stack
                // e.g abc3[a] 中间的"a"
                // 也有可能没有，比如3[2[ad]3[pf]]xyz，最外层的[]
                // 因为中间都是表达式，已经展开入栈了
                if ( !letters.empty() ) {
                    str_stack.push( letters );
                    letters.clear();
                }

/*
                将stack上"［］"直接的strings，出栈，合并，展开
*/
                // 出栈，合并
                string ss;
                stack<string> tmp_stack; // 目的将strings的顺序变为正常顺序
                while (!str_stack.empty() && str_stack.top() !="[") {
                    ss = str_stack.top();
                    tmp_stack.push( ss );
                    str_stack.pop();
                }
                ss.clear();
                while (!tmp_stack.empty()) {
                    ss += tmp_stack.top();
                    tmp_stack.pop();
                }

                // pop out "["
                str_stack.pop();

                // find out repeat number
                string num_ss;
                num_ss = str_stack.top();
                str_stack.pop(); //pop out repetition number
                int repeat_n = atoi(num_ss.c_str());

                // 展开
                string repeat_s;
                for(int i=0;i<repeat_n;i++) {
                    repeat_s += ss;
                }
                str_stack.push( repeat_s );
            }
            left++;
        }
        // 有些是以letters结尾
        if ( !letters.empty() ) {
            str_stack.push( letters );
            letters.clear();
        }

        // 两stack将letters 的顺序变为正常
        stack<string> tmp_stack;
        while ( !str_stack.empty()) {
            tmp_stack.push( str_stack.top() );
            str_stack.pop();
        }
        while ( !tmp_stack.empty() ){
            result += tmp_stack.top();
            tmp_stack.pop();
        }
        return result;
    }
};

class Solution_v1 {
public:
    /**
     * @param s  an expression includes numbers, letters and brackets
     * @return a string
     */
    string expressionExpand(string& s) {
        string result;
        if (s.size() == 0) return result;

        stack<string> str_stack;

        int left = 0;
        int right = 0;
        // string num_str;
        // string letters;
        while( right < s.size()) {
            if ( isdigit(s[left]) ) {
                string tmp;
                while( right<s.size() && isdigit(s[right]) )  {
                    right++;
                }
                //number不可能是最后一个，所以right 不会越界
                tmp = s.substr(left, right-left);
                str_stack.push( tmp );
                left = right;
                continue;
            }
            if ( s[left] == '[' ) {
                string tmp = s.substr(left, 1);
                str_stack.push(tmp);
                right++;
                left = right;
                continue;
            }
            if ( isalpha(s[left]) ) {
                string tmp;
                while( right<s.size() && isalpha(s[right]) )  {
                    right++;
                }
                if ( right >=s.size() ) {
                    tmp = s.substr(left, right-left+1);
                } else {
                    tmp = s.substr(left, right-left);
                }
                str_stack.push( tmp );
                left = right;
                continue;
            }
            if ( s[left] == ']' ) {
                //pop stack
                string ss;
                stack<string> tmp_stack;
                while (!str_stack.empty() && str_stack.top() !="[") {
                    ss = str_stack.top();
                    tmp_stack.push( ss );
                    str_stack.pop();
                }
                str_stack.pop(); // pop out "["
                ss = str_stack.top();

                str_stack.pop(); //pop out repetion number
                int repeat_n = atoi(ss.c_str());

                ss.clear();
                while (!tmp_stack.empty()) {
                    ss += tmp_stack.top();
                    tmp_stack.pop();
                }
                string repeat_s;
                for(int i=0;i<repeat_n;i++) {
                    repeat_s += ss;
                }
                str_stack.push( repeat_s );

                right++;
                left = right;
                continue;
            }
        }

        stack<string> tmp_stack;
        while ( !str_stack.empty()) {
            tmp_stack.push( str_stack.top() );
            str_stack.pop();
        }
        while ( !tmp_stack.empty() ){
            result += tmp_stack.top();
            tmp_stack.pop();
        }
        return result;
    }


};



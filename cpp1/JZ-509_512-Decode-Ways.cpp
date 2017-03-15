/*Decode Ways

Description
A message containing letters from A-Z is being encoded to numbers
using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits,
determine the total number of ways to decode it.

Example
Given encoded message 12, it could be decoded as AB (1 2) or L (12).
The number of ways decoding 12 is 2.
*/




class Solution_JZ {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     *
     * 基本方案：
     * e.g.
     *
     * 1. if s(i)可以单独decode,即s(i)!='0'
     *    ways(i) = ways(i-1)
     * 2. if s(i-1)和s(i)可以一起decode：
     *    ways(i) += ways(i-2)
     * e.g.:
     *
     *  a. ways("123") = ways("12"){"3"=C} + ways("1"){"23"＝W}，可以decode为一位数或者两位数
     *     也就是： ways(i) = ways(i-1) + ways(i-2) = 3
     *  b. ways("120") = ways("1"){"20" = U}  如果为0的话，只能decode为两位数
     *     也就是 ways(i) = ways(i-2)
     *  b. ways("189") = ways("18") = ways("1","8") + ways("18"='r") = 1+1 = 2
     *     也就是 ways(i) = ways(i-2)
     *  c. ways("100") =0 没法单独decode，也没法一起decdoe
     *
     * 参考九章方案，比较简洁，易懂
     */
    int numDecodings(string& s) {

        if (s.size() == 0) return 0;
        if (s[0] == '0') return 0;
        // state
        vector<int> ways(s.size(), 0);
        ways[0] = 1;
        // s[0]不可能为0，所以如果s[1]＝0的话，只可decode为两位数，否则都有可能
        ways[1] = (s[1] == '0')?1:2;
        for ( int i = 2; i < s.size(); i++) {
            if ( s[i] != '0') { // 如果==0的话，只可能是两位数了, skipped
                ways[i] = ways[i-1];
            }

            //两位数的case
            int two_digit = (s[i-1]-'0')*10 + s[i] -'0';
            if (two_digit <= 26 && two_digit >=10) {
                ways[i] += ways[i-2];
            }
        }
        return ways[s.size()-1];
    }
};

class Solution_my {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     *
     * 自己想出来的，比较复杂难懂
     */
    int numDecodings(string& s) {
        if (s.size()==0) return 0;
        if (s[0] == '0') return 0;
        // Write your code here
        // state
        vector<int> ways1(s.size(), 1);  //一位数case
        vector<int> ways2(s.size(), 0);  //两位数case


        for (int i=1; i<s.size(); i++) {
            if (s[i]!='0') {
                ways1[i] = ways1[i-1] + ways2[i-1];
            } else {
                ways1[i] = 0;
            }

            int i1_digit = s[i-1]-'1' + 1;
            int i_digit= s[i] -'1' +1;
            if (i1_digit*10+i_digit <=26) {
                ways2[i] = ways1[i-1];
            }
        }
        return ways1[s.size()-1] + ways2[s.size()-1];

    }
};
/*strStr II

Description
Implement strStr function in O(n + m) time.

strStr return the first index of the target string in a source string.
The length of the target string is m and the length of the source string is n.
If target does not exist in source, just return -1.

Have you met this question in a real interview? Yes
        Example
Given source = abcdef, target = bcd, return 1.

Tags
        Hash Table
        Related Problems
        Easy strStr*/

class Solution {
public:
    /**
     * @param source a source string
     * @param target a target string
     * @return an integer as index
     *
     * 计算字符串的hash，通过hash来查找
     *
     */
    int strStr2(const char* source, const char* target) {
        // Write your code here
        if (source == NULL || target == NULL)
            return -1;
        int m = strlen(target);
        int n = strlen(source);

        if (m == 0)
            return 0;

        int mod = rand() % 1000000 + 1000000;
        int hash_target = 0;
        int m26 = 1;

        for (int i = 0; i < m; ++i) {
            hash_target = (hash_target * 26 + target[i] - 'a') % mod;
            if (hash_target < 0)
                hash_target += mod;
        }

        for (int i = 0; i < m - 1; ++i)
            m26 = m26 * 26 % mod;

        int value = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= m)
                value = (value - m26 * (source[i - m] - 'a')) % mod;

            value = (value * 26 + source[i] - 'a') % mod;
            if (value < 0)
                value += mod;

            if (i >= m - 1 && value == hash_target) {
                // you have to double check by directly compare the string
                char sub[m];
                memcpy(sub, &source[i - m + 1], m);
                sub[m] = '\0';
                if (strcmp(target, sub) == 0) {
                    return i - m + 1;
                }
            }
        }
        return -1;
    }
};
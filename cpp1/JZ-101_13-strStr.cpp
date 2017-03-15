/*strStr

For a given source string and a target string, you should output
the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview,
the interviewer may just want to
test your basic implementation ability. But make sure your confirm
with the interviewer first.

Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)
*/


class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if(source == NULL || target == NULL) {
            return -1;
        }

        int s_len = strlen(source);
        int t_len = strlen(target);

        for (int i = 0; i < s_len - t_len + 1; i++) {
            int j= -1;
            for(j = 0; j < t_len; j++) {
                if (target[j] != source[i+j]) break;
            }

            if (j == t_len) {
                return i;
            }
        }
        return -1;
    }
};

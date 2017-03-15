/*
Valid Palindrome

Description
Given a string, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

Notice

        Have you consider that the string might be empty?
        This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

        Example
"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Challenge
O(n) time without extra memory.

Tags
        String Two Pointers Facebook Zenefits Uber
*/


class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {

        int left = 0;
        int right = s.size()-1;
        while (left < right) {
            // skip left side not-alpha-number
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            // skip right side not-alpha-number
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            // left and right are alpha-number, check if equal(ignoring case)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } else {
                left++; right--;
            }
        }
        return true;
    }
};
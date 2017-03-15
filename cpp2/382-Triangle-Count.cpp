/*Triangle Count

Description
Given an array of integers, how many three numbers can be found
in the array, so that we can build an triangle whose three edges
length is the three numbers that we find?

Have you met this question in a real interview? Yes
        Example
Given array S = [3,4,6,7], return 3. They are:

[3,4,6]
[3,6,7]
[4,6,7]
Given array S = [4,4,4,4], return 4. They are:

[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]
Tags
        Two Pointers LintCode Copyright
        Related Problems
        Medium 3Sum 20 %
Easy Two Sum*/

class Solution_my {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int N = S.size();
        if (N < 3)  {
            return 0;
        }
        sort(S.begin(), S.end());

        int t_count = 0;
        for (int i=0; i<=N-3; i++) {
            // find two sum > S[i]
            int target = S[i];
            int left = i+1;
            int right = N-1;
            while (left < right) {
                // printf("S[%d]=%d, S[%d]=%d\n", left, S[left], right, S[right]);
                if (S[left] + S[right] <= target) {
                    left++;
                } else {
                    int l1 = left;
                    while (S[i]+S[l1] <= S[right]) {
                        l1++;
                    }
                    t_count += (right-l1);
                    right--;
                }
                // cout << "c_t=" << t_count << endl;
            }
        }
        return t_count;
    }
};

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     *
     * 比较巧妙的技巧
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int N = S.size();
        if (N < 3)  {
            return 0;
        }
        sort(S.begin(), S.end());

        int t_count = 0;
        for (int i=0; i<=N-1; i++) {
            // find two sum > S[i]
            int target = S[i];
            int left = 0;
            int right = i-1;
            while (left < right) {
                // printf("S[%d]=%d, S[%d]=%d\n", left, S[left], right, S[right]);
                if (S[left] + S[right] <= target) {
                    left++;
                } else {
                    t_count += (right-left);
                    right--;
                }
                // cout << "c_t=" << t_count << endl;
            }
        }
        return t_count;
    }
};
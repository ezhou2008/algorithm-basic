/*Perfect Squares

Description
Given a positive integer n, find the least number of perfect
square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Have you met this question in a real interview? Yes
        Example
Given n = 12, return 3 because 12 = 4 + 4 + 4
Given n = 13, return 2 because 13 = 4 + 9

Tags
        Dynamic Programming Mathematics

Related Problems
Medium Ugly Number II*/

class Solution_timeout {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {

        vector<int> dp(n+1,INT_MAX);

        for (int j=1;j*j<=n;j++) {
            dp[j*j] = 1;
        }

        for (int i=2; i<=n;i++) {
            if (dp[i] == 1) {
                continue;
            }
            for (int j=1; j*j<=i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+dp[j*j]);
            }
        }
        return dp[n];
    }

/*    13 12 11 10 9 8 7 6 5 4 3 2 1
    1 2 3 4 5 6 7 8 9 10
    1 2 3 1 2 3 4 2
    */
};

class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {

        vector<int> dp(n+1,INT_MAX);

        for (int j=0;j*j<=n;j++) {
            dp[j*j] = 1;
        }

        for (int i=2; i<=n;i++) {
            for (int j=1; j*j<=i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+dp[j*j]);
            }
        }
        return dp[n];
    }
};


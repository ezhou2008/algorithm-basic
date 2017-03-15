/*
Copy Books

Description
Given n books and the ith book has A[i] pages.
You are given k people to copy the n books.

n books list in a row and each person can claim a continous range
of the n books. For example one copier can copy the books from ith
to jth continously, but he can not copy the 1st book, 2nd book and 4th
book (without 3rd book).

They start copying books at the same time and they all cost 1 minute
to copy 1 page of a book. What's the best strategy to assign books so
that the slowest copier can finish at earliest time?

Have you met this question in a real interview? Yes
Example
Given array A = [3,2,4], k = 2.

Return 5( First person spends 5 minutes to copy book 1 and book 2
and second person spends 4 minutes to copy book 3. )
*/


class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int n = pages.size();
        if (k>n) k = n;
        vector<int> sum(n);
        sum[0] = pages[0];
        for (int i=1; i<n; ++i) sum[i] = sum[i-1]+pages[i];
        vector<vector<int> > f(n, vector<int>(k));
        for (int i=0; i<n; ++i) f[i][0] = sum[i];
        for (int j=1; j<k; ++j) {
            int p = 0;
            f[0][j] = pages[0];
            for (int i=1; i<j; ++i) f[i][j] = max(f[i-1][j], pages[i]);
            for (int i=j; i<n; ++i) {
                while (p<i && f[p][j-1]<sum[i]-sum[p]) ++p;
                f[i][j] = max(f[p][j-1], sum[i]-sum[p]);
                if (p>0) --p;
                f[i][j] = min(f[i][j], max(f[p][j-1], sum[i]-sum[p]));
            }
        }
        return f[n-1][k-1];
    }
};
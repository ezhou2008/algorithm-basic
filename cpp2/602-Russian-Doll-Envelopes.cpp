/*Russian Doll Envelopes

        Description
You have a number of envelopes with widths and heights given as
a pair of integers (w, h). One envelope can fit into another
if and only if both the width and height of one envelope is
greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll?
(put one inside other)

Have you met this question in a real interview? Yes
        Example
Given envelopes = [[5,4],[6,4],[6,7],[2,3]],
the maximum number of envelopes you can Russian doll is
3 ([2,3] => [5,4] => [6,7]).

Tags
        Binary Search Dynamic Programming Facebook
Related Problems
Medium Longest Increasing Subsequence*/

class Solution_TLE {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // Write your code here
        auto cmp_pair = [](pair<int,int> p1, pair<int,int> p2) {
            return (p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second);
/*            if (p1.first < p2.first) {
                return true;
            } else if (p1.first == p2.first) {
                return p1.second < p2.second;
            } else {
                return false;
            }*/
        };

        sort(envelopes.begin(), envelopes.end(), cmp_pair);

        int N = envelopes.size();
        vector<int> local_dp(N,1);

        for (int i=1; i<N; i++) {
            for (int j=0; j<i; j++) {
                if (envelopes[i].first > envelopes[j].first &&
                    envelopes[i].second > envelopes[j].second) { //j can fit into i
                    local_dp[i] = max(local_dp[i], local_dp[j]+1);
                }
            }

        }
        return *max_element(local_dp.begin(), local_dp.end());

    }
};

class Solution_binary_search {
public:
    /**
     * @param envelopes a number of envelopes with widths and heights
     * @return the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // width升序，后heigh降序
        auto cmp_pair = [](pair<int,int> p1, pair<int,int> p2) {
            return (p1.first < p2.first) || (p1.first == p2.first && p1.second > p2.second);
        };

        sort(envelopes.begin(), envelopes.end(), cmp_pair);

        // Longest increasing sequence的binary search算法
        // 这里只找height的LIS
        int N = envelopes.size();
        vector<int> dp;
        dp.push_back(0);

        for (int i=1; i<N; i++) {
            int idx = binary_search(dp,envelopes[i], envelopes);
            if (idx == -1) {
                dp.push_back(i);
            } else {
                dp[idx] = i;
            }
        }
        return dp.size();
    }

    // find the first ele >= target, retur -1 if not found
    // 只比较second（即height）
    int binary_search(vector<int> dp, pair<int,int> target, vector<pair<int, int>>& envelopes) {
        int start = 0;
        int end = dp.size()-1;
        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            if (envelopes[dp[mid]].second >= target.second) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (envelopes[dp[start]].second >= target.second) {
            return start;
        } else if (envelopes[dp[end]].second >= target.second) {
            return end;
        } else {
            return -1;
        }
    }
};
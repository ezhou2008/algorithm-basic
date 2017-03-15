/*Zigzag Iterator II

        Description
Notes
        Testcase
Judge
Follow up Zigzag Iterator: What if you are given k 1d vectors?
How well can your code be extended to such cases?
The "Zigzag" order is not clearly defined and is ambiguous
for k > 2 cases. If "Zigzag" does not look right to you,
replace "Zigzag" with "Cyclic".

Have you met this question in a real interview? Yes
        Example
Given k = 3 1d vectors:

[1,2,3]
[4,5,6,7]
[8,9]
Return [1,4,8,2,5,9,3,6,7].

Tags
        Google
Related Problems*/

class ZigzagIterator2 {
public:
    /**
     * @param vecs a list of 1d vectors
     */
    int N = -1;
    vector<vector<int>::iterator> it;
    vector<vector<int>::iterator> end;
    int cur_p = 0;

    ZigzagIterator2(vector<vector<int>>& vecs) {
        // initialize your data structure here.
        N = vecs.size();
        for (int i=0; i<N;i++) {
            it.push_back(vecs[i].begin());
            end.push_back(vecs[i].end());
        }
    }

    int next() {
        // Write your code here
        int ret_val = INT_MIN;
        while (it[cur_p] == end[cur_p]) {
            cur_p = ++cur_p % N;
        }
        ret_val = *(it[cur_p]++);
        cur_p = ++cur_p % N;
        return ret_val;
    }

    bool hasNext() {
        // Write your code here
        for (int i=0; i<N; i++) {
            if (it[i] != end[i]) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
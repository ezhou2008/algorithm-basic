/*Zigzag Iterator

Description
Given two 1d vectors, implement an iterator to return their elements alternately.

Have you met this question in a real interview? Yes
        Example
Given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false,
the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Tags
        Google
Related Problems
Medium*/

class ZigzagIterator {
public:
    /**
     * @param v1 v2 two 1d vectors
     */

    vector<int>::iterator it[2];
    vector<int>::iterator it_end[2];
    int next_v = 0;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {

        it[0] = v1.begin();
        it[1] = v2.begin();
        it_end[0] = v1.end();
        it_end[1] = v2.end();
    }

    int next() {
        int ret_val = INT_MIN;
        if (it[next_v] != it_end[next_v]) {
            ret_val = *(it[next_v]++);
            next_v = !next_v;
        } else {
            next_v = !next_v;
            ret_val = *(it[next_v]++);
        }
        return ret_val;
    }

    bool hasNext() {
        return it[0]!=it_end[0] || it[1]!=it_end[1];
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
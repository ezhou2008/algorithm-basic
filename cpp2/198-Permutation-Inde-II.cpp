/*Permutation Index II

Description
Given a permutation which may contain repeated numbers,
find its index in all the permutations of these numbers,
which are ordered in lexicographical order. The index begins at 1.

Example
Given the permutation [1, 4, 2, 2], return 3.

Related Problems
Medium Next Permutation II*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     *
     * 本题是 Permutation Index 的扩展，这里需要考虑重复元素，有无重复元素最大的区别在于原来的1!, 2!, 3!...等需要除以重复元素个数的阶乘，颇有点高中排列组合题的味道。记录重复元素个数同样需要动态更新，引入哈希表这个万能的工具较为方便。
     */
    long long permutationIndexII(vector<int>& A) {
        if (A.empty()) return 0;

        long long index = 1;
        long long factor = 1;
        // 记录每个数出现的次数
        unordered_map<int, int> hash;
        for (int i = A.size() - 1; i >= 0; --i) {
            int rank = 0;
            hash[A[i]]++;
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) {
                    ++rank;
                }
            }

/*            printf("A[%d] = %d\n", i, A[i]);
            for (auto ele : hash) {
                printf("hash[%d] = %d, ", ele.first, ele.second);
            }
            cout << "dupPer = " << dupPerm(hash) << endl;
            cout << endl;*/

            index += rank * factor / dupPerm(hash);
            factor *= (A.size() - i);
        }

        return index;
    }
    long long dupPerm(unordered_map<int, int> hash) {
        if (hash.empty()) return 1;

        long long dup = 1;
        for (auto p : hash) {
            dup *= fact(p.second);
        }

        return dup;
    }

    long long fact(int num) {
        long long val = 1;
        for (int i = 1; i <= num; ++i) {
            val *= i;
        }

        return val;
    }
};
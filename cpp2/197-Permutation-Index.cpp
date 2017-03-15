/*Permutation Index

Description
Given a permutation which contains no repeated number,
find its index in all the permutations of these numbers,
which are ordered in lexicographical order. The index begins at 1.

Have you met this question in a real interview? Yes
Example
Given [1,2,4], return 1.

Related Problems
Medium Next Permutation II 33 %
Medium Previous Permutation*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     *
     * 题解

做过 next permutation 系列题的话自然能想到不断迭代直至最后一个，最后返回计数器的值即可。这种方法理论上自然是可行的，但是最坏情况下时间复杂度为
O
n
O(n!), 显然是不能接受的。由于这道题只是列出某给定 permutation 的相对顺序(index), 故我们可从 permutation 的特点出发进行分析。
以序列1, 2, 4为例，其不同的排列共有 3!=6 种，以排列[2, 4, 1]为例，若将1置于排列的第一位，后面的排列则有 2!=2 种。将2置于排列的第一位，由于[2, 4, 1]的第二位4在1, 2, 4中为第3大数，故第二位可置1或者2，那么相应的排列共有 2 * 1! = 2种，最后一位1为最小的数，故比其小的排列为0。综上，可参考我们常用的十进制和二进制的转换，对于[2, 4, 1], 可总结出其排列的index为2! * (2 - 1) + 1! * (3 - 1) + 0! * (1 - 1) + 1.+

以上分析看似正确无误，实则有个关键的漏洞，在排定第一个数2后，第二位数只可为1或者4，而无法为2, 故在计算最终的 index 时需要动态计算某个数的相对大小。按照从低位到高位进行计算，我们可通过两重循环得出到某个索引处值的相对大小。

     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        long long factor  = 1;
        long long idx = 1;

        for (int i=A.size()-1; i>=0; i--) {
            int pos = 0;  // 找出右边比A[i]小的数目
            for (int j=i;j<A.size();j++) {
                if (A[j] < A[i]) {
                    pos++;
                }
            }
            idx += pos*factor;
            // printf("i=%d, pos = %d, factor = %d, idx = %d\n", i, pos, factor,(int)idx);
            // 注意： factor 更新要放在idx更新后面，因为第一次要用初始化值
            factor *= (A.size()-i);
        }
        return idx;
    }
};
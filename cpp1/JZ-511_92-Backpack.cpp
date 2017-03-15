/*
Backpack

 Description
Given n items with size Ai, an integer m denotes the size of a backpack.
How full you can fill this backpack?

Notice

You can not divide any item into small pieces.

Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11,
we can select [2, 3, 5], so that the max size we can fill this backpack is 10.
If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.

Challenge
O(n x m) time and O(m) memory.

O(n x m) memory is also acceptable if you do not know how to optimize memory.


*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     *
     * 1. ith item要么选上，要么不选。选上需要满足一定的条件，否则不选。
     * 2. O(m) memory
     *    在O(n x m) memory方案上优化
     * 3. 其它见backpack II
     */
    int backPack(int m, vector<int> A) {
        // write your code here

        // state: MS(bp_size): max size at i-th item with backpack size = bp_size
        vector<int> MS(m+1, 0);
        // init
        for ( int bp_size=0; bp_size<=m; bp_size++) {
            if (A[0] <= bp_size) {
                MS[bp_size] = A[0];
            } // else =0 as initialized
        }

        for (int i=1; i<A.size(); i++) {
/*
            注意：ba_size倒序进行运算
*/
            for (int bp_size=m; bp_size>=0; bp_size--) {
                //selected
                if (A[i] <= bp_size) {
                    MS[bp_size] = max(MS[bp_size], MS[bp_size-A[i]]+A[i]);
                }
            }
        }
        return MS[m];

    }
};
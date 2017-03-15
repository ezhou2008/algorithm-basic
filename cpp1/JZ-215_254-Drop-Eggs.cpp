/*Drop Eggs

Description

There is a building of n floors. If an egg drops from the k th floor or above,
it will break. If it's dropped from any floor below, it will not break.

You're given two eggs, Find k while minimize the number of drops for the worst case.
Return the number of drops in the worst case.

Clarification
For n = 10, a naive way to find k is drop egg from 1st floor, 2nd floor ... kth floor.
But in this worst case (k = 10), you have to drop 10 times.

Notice that you have two eggs, so you can drop at 4th, 7th & 9th floor,
in the worst case (for example, k = 9) you have to drop 4 times.

Example
        Given n = 10, return 4.
Given n = 100, return 14.

Related Problems
Medium Drop Eggs II
*/


class Solution_memoryOut {
public:
    /**
     * @param n an integer
     * @return an integer
     */
    int dropEggs(int n) {
        // Write your code here
        vector<int> f(n+1,INT_MAX);

/*      state
        i: ith floor, i=[1,n]
        f(i)=min number of drops in worst case at ith floor
        f(i) = min{ 1+max{k-1,f(i-k)} } ,k=1,i
            either break{=k-1} or not break{=f(i-k)}

        另一种写法，也许更清晰些：
        drops_global(i) = min {drops_local(k)} i=1,n
            floors的数目是i，最小需要的drop数
        drops_local(k) = 1+max{k-1,drops_global(i-k)} k=1,i
            floors的数目是i，从k层开始试探，worst case需要的drop数目

        由于local还有依赖于前面的global，所以需要同时计算local和global
 */

        //initialization
        f[0] = 0;

        //function
        for( int i = 1; i <=n; i++)
        {
//            f[i] = INT_MAX;
            for( int k = 1; k <= i; k++){
                // max代表worst case，min代表minimize worst cases
                f[i] = min( f[i], 1+max( k-1, f[i-k]) );
            }
        }

        //answer
        return f[n];
    }
};


class Solution {
public:
    /**
     * @param n an integer
     * @return an integer
     *
     * 1. 如果只有一个eggs，只有一层一层的drop,没有别的办法
     * 2. 如果有很多eggs，可以使用二分法，最少需要log2(n)个eggs
     * 3. 如果只有两个eggs，最优的办法是在开始在x层drop，而且在x层egg break or not所需的drop次数是一样的。
     *    所以在x层所需的次数有x
     *          x层drop一次，
     *              如果break 的话，再需在下面x-1层一层层地是，需x-1次，共x-1+1(x层drop)= x次drop
     *              如果不break的话，要做到和break一样的次数的话，就需跳到x＋x-1层drop，所需为：
     *                  x-2(x+x-1层下面一层层地试探)+ 1(x+x-1层的drop)+1(x层drop)=x
     *          如此类推，
     *              第一次drop的位置在x,第二次 x + x-1, 第三次为 x + x-1 + x-2...,
     *              最后一次为 x + x-1 + x-2 + x-3 +....+3+2+1 = n
     *              x(x+1)/2 >=n
     *              e.g. n=10 x=4, n=100, x=14
     */
    int dropEggs(int n) {
        // Write your code here
/*
        x + x-1 + x-2 + x-3 +....+3+2+1 = n
*/
        long long ans = 0;
        int x = 0;
        while (ans < n) {
            x += 1;
            ans += x;
        }
        return x;
    }
};
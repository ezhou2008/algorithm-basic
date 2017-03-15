/*Drop Eggs II

Description

There is a building of n floors. If an egg drops from the k th floor or above,
it will break. If it's dropped from any floor below, it will not break.

You're given m eggs, Find k while minimize the number of drops for the worst case.
Return the number of drops in the worst case.

Example
Given m = 2, n = 100 return 14
Given m = 2, n = 36 return 8

Tags
        Dynamic Programming
        Related Problems
        Easy Drop Eggs
*/

class Solution {
public:
    /**
     * @param m the number of eggs
     * @param n the umber of floors
     * @return the number of drops in the worst case
     *
     */
    int dropEggs2(int m_eggs, int n_floors) {
        // Write your code here

        // state
        // 初始化为0比较自然，主要是针对0层的情况
        vector<vector<int>> drops(m_eggs+1, vector<int>(n_floors+1,0));

        // init，一个egg的case
        for (int n=1; n<=n_floors; n++) {
            drops[1][n] = n;
        }
        // init, 一层的case
        for (int m=1; m<=m_eggs; m++) {
            drops[m][1] = 1;
        }

        for (int m = 2; m <=m_eggs; m++) {
            for (int n = 2; n <= n_floors; n++) {
                drops[m][n] = INT_MAX;
                // 找出k层开始drop的话，所需的drops，
                // 找出其中的最小值
                for (int k =1; k<=n; k++) { //k-1, n-k都有可能为0，所以要初始化drops[m][0]
/*
                    注意：先max（找出两者中的worst case），后min找出从kth层开始的最小者
                    题目中的描述如下：
                    Find k while **minimize** the number of drops for the **worst case**.
*/
                    drops[m][n] = min( drops[m][n], 1+max(drops[m-1][k-1], drops[m][n-k]) );
                }
            }
        }
        return drops[m_eggs][n_floors];

    }
};
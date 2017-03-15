/*Edit Distance
Description

Given two words word1 and word2, find the minimum number of steps
required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

        Insert a character
        Delete a character
        Replace a character

Example
Given word1 = "mart" and word2 = "karma", return 3.
*/


class Solution {
public:
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     *
     *  需增加空子串
     */
    int minDistance(string source, string target) {

        // state dis(i,j): distance to change source(0..i) to target(0..j)
        // 初始化为0
        vector<vector<int>> dis(source.size()+1, vector<int>(target.size()+1,0));

        // init：source == empty, insert only 只需要一直增加
        for (int t = 1; t <= target.size(); t++) {
            dis[0][t] = dis[0][t-1] + 1;
        }
        // init： target == empty, delete only 只需要一直删除
        for (int s = 1; s <= source.size(); s++) {
            dis[s][0] = dis[s-1][0] + 1;
        }

/*        function
        1. source[i] == target[j]: 本次不需要操作
        2. source[i] != target[j]， 如: ab->cd
                2.1 replace:
                    就变成ad->cd, 退回到dis[i-1][j-1]
                2.1 Insert:
                    就变成abd->cd, 退回到dis[i][j-1]
                2.1 delete:
                    就变成a->cd, 退回到dis[i-1][j]
*/

        for (int s = 1; s <= source.size(); s++) {
            for (int t = 1; t <= target.size(); t++) {
                if (source[s-1] == target[t-1]) {
                    dis[s][t] = dis[s-1][t-1];
                } else {
                    dis[s][t] = min(dis[s-1][t-1], min(dis[s][t-1],dis[s-1][t])) + 1;
                }
            }
        }

        //answer
        return dis[source.size()][target.size()];

    }
};

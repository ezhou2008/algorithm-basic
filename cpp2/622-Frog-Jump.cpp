/*Frog Jump

Description

A frog is crossing a river. The river is divided into x units
and at each unit there may or may not exist a stone.
The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order,
determine if the frog is able to cross the river by landing on the last
stone. Initially, the frog is on the first stone and assume the first
jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either
k - 1, k, or k + 1 units. Note that the frog can only jump in the
forward direction.

Notice
The number of stones is ≥ 2 and is < 1100.

Each stone's position will be a non-negative integer < 2^31.

The first stone's position is always 0.

Example
Given stones = [0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping
1 unit to the 2nd stone, then 2 units to the 3rd stone, then
2 units to the 4th stone, then 3 units to the 6th stone,
4 units to the 7th stone, and 5 units to the 8th stone.

Given stones = `[0,1,2,3,4,8,9,11]`

Return false. There is no way to jump to the last stone as
        the gap between the 5th and 6th stone is too large.
Tags
        Dynamic Programming
        Related Problems*/


class Solution {
public:
    /**
     * @param stones a list of stones' positions in sorted ascending order
     * @return true if the frog is able to cross the river or false
     *
     * 要点：
     * 1. 不是dp
     * 2. 记录所有可能的到达的位置
     *
     */
    bool canCross(vector<int>& stones) {
/*        需用unordered_set,不能用vector，因为有重复，不然的话，会超时
*/
        // map<位置，此位置上的next jump>
        unordered_map<int,unordered_set<int>> dp;
        for (int i=0; i<stones.size();i++) {
            dp.insert(make_pair(stones[i],unordered_set<int>()));
        }
        // "the first jump must be 1 unit"
        dp[stones[0]].insert(1);

        // 计算i位置能到达的位置的可能的step(next jump)
        for (int i=0; i<stones.size();i++) {
            for (auto step : dp[stones[i]]) {
                int next_pos = stones[i]+step; // i可达的位置（stone)
                if (dp.find(next_pos) != dp.end()) { // 位置有效（存在stone）
                    if (step-1 > 0) { // 添加k-1
                        dp[next_pos].insert(step-1);
                    }
                    dp[next_pos].insert(step); // 添加k
                    dp[next_pos].insert(step+1); // 添加k+1
                }
            }
        }
        // 最后一个位置的next jump不为空
        return !(dp[stones.back()].empty());
    }
};
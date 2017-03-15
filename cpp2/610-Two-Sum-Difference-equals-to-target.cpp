/*
Two Sum - Difference equals to target

Description
Given an array of integers, find two numbers that their difference equals
to a target value.
where index1 must be less than index2. Please note that your returned
answers (both index1 and index2) are NOT zero-based.

Notice

        It's guaranteed there is only one available solution

Have you met this question in a real interview? Yes
        Example
Given nums = [2, 7, 15, 24], target = 5
return [1, 2] (7 - 2 = 5)

Tags
        Two Pointers Hash Table
*/


class Solution_Two_Pointers {
public:
    /*
     * @param nums an array of Integer
     * @param target an integer
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        vector<int> result(2,-1);
        int N = nums.size();

        auto cmp_pair = [](pair<int,int> p1, pair<int,int> p2) {
            return p1.first < p2.first;
        };
        // pair<value, index>
        vector<pair<int,int>> nums_p;
        for (int i=0; i<nums.size(); i++) {
            nums_p.push_back(make_pair(nums[i],i));
        }

        sort(nums_p.begin(), nums_p.end(), cmp_pair);

        for (int i=0; i<N-1; i++) {
            for (int j=i+1; j<N; j++) {
                if (nums_p[j].first-nums_p[i].first < abs(target)) {
                    continue;
                }
                if (nums_p[j].first-nums_p[i].first == abs(target)) {
                    result[0] = min(nums_p[i].second, nums_p[j].second)+1;
                    result[1] = max(nums_p[i].second, nums_p[j].second)+1;
                    return result;

                } else {
                    break;
                }
            }
        }
        return result;



    }
};


class Solution_hash1 {
public:
    /*
     * @param nums an array of Integer
     * @param target an integer
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     *
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        // write your code here
        vector<int> result(2,-1);
        unordered_map<int,int> n_map;
        for (int i=0; i<nums.size(); i++) {
            n_map[nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++) {
            if (n_map.find(nums[i]+target) != n_map.end()) {
                result[0] = min(i,n_map[nums[i]+target])+1;
                result[1] = max(i,n_map[nums[i]+target])+1;
                break;
            }
            if (n_map.find(nums[i]-target) != n_map.end()) {
                result[0] = min(i,n_map[nums[i]-target])+1;
                result[1] = max(i,n_map[nums[i]-target])+1;
                break;
            }
        }
        return result;
    }
};


class Solution_hash2 {
public:
    /*
     * @param nums an array of Integer
     * @param target an integer
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        // write your code here
        vector<int> result(2,-1);
        unordered_map<int,int> n_map;
        for (int i=0; i<nums.size(); i++) {
        }

        for (int i=0; i<nums.size(); i++) {
            if (n_map.find(nums[i]+target) != n_map.end()) {
                result[0] = min(i,n_map[nums[i]+target])+1;
                result[1] = max(i,n_map[nums[i]+target])+1;
                break;
            }
            if (n_map.find(nums[i]-target) != n_map.end()) {
                result[0] = min(i,n_map[nums[i]-target])+1;
                result[1] = max(i,n_map[nums[i]-target])+1;
                break;
            }
            // 下面statement不能放在if前面，否则如果target＝0的情况就pass不了
            n_map[nums[i]] = i;

        }
        return result;
    }
};


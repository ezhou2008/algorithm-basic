/*
Intersection of Two Arrays II

Description
Given two arrays, write a function to compute their intersection.

Notice

Each element in the result should appear as many times as
it shows in both arrays.
The result can be in any order.
Have you met this question in a real interview? Yes
Example
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Challenge
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that
you cannot load all elements into the memory at once?

Tags
Binary Search Two Pointers Sort Hash Table
*/



class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     *
     * 要点：
     *  使用hash map，需要记录重复次数
     *
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        vector<int> result;
        unordered_map<int,int> hash_1;
        for (auto ele_1 : nums1) {
            if (hash_1.find(ele_1) == hash_1.end()) {
                hash_1[ele_1] = 1;
            } else {
                hash_1[ele_1]++;
            }
        }
        for (auto ele_2 : nums2) {
            if (hash_1.find(ele_2) != hash_1.end()) {
                result.push_back(ele_2);
                hash_1[ele_2]--;
                if (hash_1[ele_2] == 0) {
                    hash_1.erase(ele_2);
                }
            }
        }
        return result;
    }
};
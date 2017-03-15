/*Remove Duplicate Numbers in Array

Description
Given an array of integers, remove the duplicate numbers in it.

You should:
1. Do it in place in the array.
2. Move the unique numbers to the front of the array.
3. Return the total number of the unique numbers.

Notice

You don't need to keep the original order of the integers.

Have you met this question in a real interview? Yes
        Example
Given nums = [1,3,1,4,4,2], you should:

Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
Return the number of unique integers in nums => 4.
Actually we don't care about what you place in ?,
we only care about the part which has no duplicate integers.

Challenge
        Do it in O(n) time complexity.
Do it in O(nlogn) time without extra space.
Tags
        Sort Hash Table
Related Problems*/

class Solution {
public:
    /**
     * @param nums an array of integers
     * @return the number of unique integers
     */
    int deduplication(vector<int>& nums) {
        if (nums.size()==0) {
            return 0;
        }

        unordered_set<int> n_hash;
/*        int idx_last_u = -1;
        for (int i=0; i<nums.size();i++) {
            if (n_hash.find(nums[i]) == n_hash.end()) {
                n_hash.insert(nums[i]);
                swap(nums[++idx_last_u], nums[i]);
            }
        }
        return idx_last_u+1;*/

        // 下面这么做也可以
        for (int i=0; i<nums.size();i++) {
                n_hash.insert(nums[i]);
        }
        int idx =0;
        for (auto ele : n_hash) {
            nums[idx++] = ele;
        }
        return n_hash.size();
    }
};

class Solution {
public:
    /**
     * @param nums an array of integers
     * @return the number of unique integers
     */
    int deduplication(vector<int>& nums) {
        if (nums.size() <=1) {
            return nums.size();
        }

        quick_sort(nums,0, nums.size()-1);
        // sort也可以
        // sort(nums.begin(),nums.end());

        int idx_last_u = 0; // 最后一个unique element的idx
        for (int i=0;i<nums.size();i++) {
            if (nums[idx_last_u] != nums[i]) {
                idx_last_u++;
                nums[idx_last_u] = nums[i];
                //swap 也可以，因为“we don't care about what you place in ?”
//                swap(nums[idx_last_u],nums[i]);
            }
        }
        return idx_last_u+1;
    }

    void quick_sort(vector<int>& nums, int start, int end) {
        if (nums.size() <=1 || start >=end) {
            return;
        }

        int mid = start+(end-start)/2;
        int pivot = nums[mid];

        int left = start;
        int right = end;
        while (left <= right) {
            while (left <= right && nums[left] < pivot) {
                left++;
            }
            while (left <= right && nums[right] > pivot) {
                right--;
            }
            if (left <=right) {
                swap(nums[left], nums[right]);
                left++;right--;
            }
        }
        quick_sort(nums,start,right);
        quick_sort(nums,left,end);
    }
};
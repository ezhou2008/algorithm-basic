/*
Kth Largest Element II

Description

Find K-th largest element in an array. and N is much larger than k.

Notice
You can swap elements in the array

Have you met this question in a real interview? Yes
        Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5,
2nd largest element is 4, 3rd largest element is 3 and etc.
*/

class Solution {
public:
    /**
     * @param nums an integer unsorted array
     * @param k an integer from 1 to n
     * @return the kth largest element
     */
    int kthLargestElement2(vector<int> nums, int k) {
        // Write your code here
        // min_q
        priority_queue<int, vector<int>, std::greater<int>> min_q;

        for (auto num : nums) {
            min_q.push(num);
            if (min_q.size() > k) {
                min_q.pop();
            }
        }

        return min_q.top();
    }
};
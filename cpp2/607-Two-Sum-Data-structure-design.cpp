/*
Two Sum - Data structure design

        Description
Notes
        Testcase
Judge
        Design and implement a TwoSum class. It should support
        the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to
the value.

Have you met this question in a real interview? Yes
        Example
add(1); add(3); add(5);
find(4) // return true
find(7) // return false
Tags
        LinkedIn Hash Table Data Structure Design
*/


class TwoSum {
public:
    unordered_map<int,int> nums;

    // Add the number to an internal data structure.
    void add(int number) {
        if (nums.find(number) == nums.end()) {
            nums[number] = 1;
        } else {
            nums[number]++;
        }
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        // Write your code here
        for (auto ele : nums) {
            int target = value - ele.first;
            if (nums.find(target) != nums.end()) {
                if (target != ele.first || (target == ele.first && nums[target] >= 2)) {
                    return true;
                }
            }
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);


class TwoSum {
public:
    unordered_multiset<int> nums;

    // Add the number to an internal data structure.
    void add(int number) {
        // Write your code here
        nums.insert(number);
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto ele : nums) {
            int target = value - ele;
            int count_req = (target==ele) ? 2:1;
            if (nums.count(target)>=count_req) {
                return true;
            }
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);


class TwoSum_Tl_exceed {
public:
    vector<int> nums;

    // Add the number to an internal data structure.
    void add(int number) {
        // Write your code here
        nums.push_back(number);
        for (int i=nums.size()-1; i>0; i--) {
            if (nums[i] < nums[i-1]) {
                swap(nums[i], nums[i-1]);
            }
        }
        // sort(nums.begin(), nums.end());

    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        // Write your code here
        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[left]+nums[right] == value) {
                return true;
            } else if (nums[left]+nums[right] > value) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
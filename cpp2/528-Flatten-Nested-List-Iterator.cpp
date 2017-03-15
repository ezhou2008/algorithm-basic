/*Flatten Nested List Iterator

Description
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also
be integers or other lists.

Notice
You don't need to implement the remove method.

Have you met this question in a real interview? Yes
        Example
Given the list [[1,1],2,[1,1]], By calling next repeatedly until hasNext
returns false, the order of elements returned by next should be:
[1,1,2,1,1].

Given the list [1,[4,[6]]], By calling next repeatedly until hasNext
returns false, the order of elements returned by next should be: [1,4,6].

Tags
Recursion Stack Data Structure Design Snapchat Google*/


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 *
 *     注意：
 *     不要用NestedInteger的指针，比如，"stack<NestedInteger＊> n_stack"，
 *     取NestedInteger的地址好像有问题，或者push NestedInteger的指针到stack有问题。
 *
 * };
 */
class NestedIterator {
public:
    stack<NestedInteger> n_stack;
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        for (int i=nestedList.size()-1; i>=0; i--) {
            n_stack.push(nestedList[i]);
        }
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int ret = n_stack.top().getInteger();
        n_stack.pop();
        return ret;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        cout << endl;
        while (!n_stack.empty()) {
            if (n_stack.top().isInteger()) {
                return true;
            }

            vector<NestedInteger> cur_arr=n_stack.top().getList();
            n_stack.pop();
            for (int i=cur_arr.size()-1; i>=0; i--) {
                n_stack.push(cur_arr[i]);
            }
        }
        return false;
    }
};


class NestedIterator {
public:
    vector<int> num_list;
    int next_idx = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        helper(nestedList);
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int answer = num_list[next_idx];
        next_idx++;
        return answer;
        // return num_list[next_idx++];
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        return next_idx < num_list.size();
    }

    void helper(const vector<NestedInteger> &nestedList) {
        for (auto ele : nestedList) {
            if (ele.isInteger()) {
                num_list.push_back(ele.getInteger());
            } else {
                helper(ele.getList());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
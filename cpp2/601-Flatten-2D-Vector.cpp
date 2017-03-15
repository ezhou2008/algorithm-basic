/*Flatten 2D Vector

Description
Implement an iterator to flatten a 2d vector.

Example
Given 2d vector =

[
[1,2],
[3],
[4,5,6]
]

By calling next repeatedly until hasNext returns false,
the order of elements returned by next should be: [1,2,3,4,5,6].

Tags
Airbnb Zenefits Google Twitter*/



class Vector2D {
public:
    vector<vector<int>> *arr2d;
    int next_row = 0;
    int next_col = 0;
    Vector2D(vector<vector<int>>& vec2d) {
        // Initialize your data structure here
        arr2d = &vec2d;
    }

    int next() {
        // Write your code here
        int ret = (*arr2d)[next_row][next_col];
        if (++next_col >= (*arr2d)[next_row].size()) {
            next_row++;
            next_col = 0;
        }
        return ret;
    }

    bool hasNext() {
        // Write your code here
        return (next_row < (*arr2d).size() && next_col < (*arr2d)[next_row].size());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
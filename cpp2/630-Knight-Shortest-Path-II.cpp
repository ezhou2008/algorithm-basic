/*Knight Shortest Path II

Description
Given a knight in a chessboard n * m (a binary matrix with 0 as empty
and 1 as barrier). the knight initialze position is (0, 0) and he wants
to reach position (n - 1, m - 1), Knight can only be from left to right.
Find the shortest path to the destination position, return the length of
the route. Return -1 if knight can not reached.

Have you met this question in a real interview? Yes
Clarification
If the knight is at (x, y), he can get to the following positions in one
step:

(x + 1, y + 2)
(x - 1, y + 2)
(x + 2, y + 1)
(x - 2, y + 1)
Example
[[0,0,0,0],
[0,0,0,0],
[0,0,0,0]]

Return 3

[[0,0,0,0],
[0,0,0,0],
[0,1,0,0]]

Return -1

Tags
        Dynamic Programming Amazon Breadth First Search
        Related Problems
        Medium Knight Shortest Path*/

class Solution_推荐 {
public:
    struct Point {
        int x, y;
        Point() : x(0), y(0) {}
        Point(int a, int b) : x(a), y(b) {}
    };
    /**
     * @param grid a chessboard included 0 and 1
     * @return the shortest path
     */
    int shortestPath2(vector<vector<bool>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        Point source(0,0);
        Point destination(n_row-1,n_col-1);
        return shortestPath(grid,source, destination);

    }

    int shortestPath(vector<vector<bool>>& grid, Point& source, Point& destination) {
        // 标准的bfs
        int n_row = grid.size();
        int n_col = grid[0].size();

        queue<Point> p_q;
        p_q.push(source);
        grid[source.x][source.y] = 1;  //mark as visited
        int r_len = -1;
        while(!p_q.empty()) {
            int q_size = p_q.size();
            r_len++;
            for (int i = 0; i<q_size; i++) {
                Point cur_p = p_q.front();
                p_q.pop();

                if (cur_p.x == destination.x && cur_p.y == destination.y) {
                    return r_len;
                }

                vector<Point>  neigbours = get_neigbours(cur_p, grid);
                for (auto adj : neigbours) {
                    if (grid[adj.x][adj.y] == 0) {
                        p_q.push(adj);
                        grid[adj.x][adj.y] = 1; // makred as visited
                    }
                }
            }
        }
        return -1;
    }

    vector<Point> get_neigbours(Point& source, vector<vector<bool>>& grid) {
        vector<Point> result;
        int n_row = grid.size();
        int n_col = grid[0].size();
        vector<int> delta_x {1, -1, 2, -2};
        vector<int> delta_y {2, 2, 1, 1};

        for (int i = 0; i<delta_x.size(); i++) {
            if ((source.x+delta_x[i] >=0 && source.x+delta_x[i] < n_row) &&
                (source.y+delta_y[i] >= 0 && source.y+delta_y[i] < n_col) ) {
                result.push_back(Point(source.x+delta_x[i], source.y+delta_y[i]));
            }
        }
        return result;
    }
};



class Solution {
public:
    struct Point {
        int x, y;
        Point() : x(0), y(0) {}
        Point(int a, int b) : x(a), y(b) {}
    };
    /**
     * @param grid a chessboard included 0 and 1
     * @return the shortest path
     *
     * dp搜索
     */
    int shortestPath2(vector<vector<bool>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        if (grid[0][0]==1 && grid[n_row-1][n_col-1]==1) {
            return -1;
        }

        vector<vector<int>> dp_len(n_row,vector<int>(n_col,INT_MAX));

        queue<Point> p_q;
        p_q.push(Point(0,0));
        dp_len[0][0] = 0;
        while(!p_q.empty()) {
            Point cur_p = p_q.front();
            p_q.pop();

            vector<Point>  neigbours = get_neigbours(cur_p, grid);
            for (auto adj : neigbours) {
                // len长的路径必须排除，否则加入queue处理会超时
                if (grid[adj.x][adj.y] == 0 &&
                    dp_len[cur_p.x][cur_p.y]+1 < dp_len[adj.x][adj.y]) {
                    p_q.push(adj);
                    dp_len[adj.x][adj.y] = dp_len[cur_p.x][cur_p.y]+1;
                }
            }
        }
        if (dp_len[n_row-1][n_col-1] == INT_MAX) {
            return -1;
        } else {
            return dp_len[n_row-1][n_col-1];
        }
    }

    vector<Point> get_neigbours(Point& source, vector<vector<bool>>& grid) {
        vector<Point> result;
        int n_row = grid.size();
        int n_col = grid[0].size();
        vector<int> delta_x {1, -1, 2, -2};
        vector<int> delta_y {2, 2, 1, 1};

        for (int i = 0; i<delta_x.size(); i++) {
            if ((source.x+delta_x[i] >=0 && source.x+delta_x[i] < n_row) &&
                (source.y+delta_y[i] >= 0 && source.y+delta_y[i] < n_col) ) {
                result.push_back(Point(source.x+delta_x[i], source.y+delta_y[i]));
            }
        }
        return result;
    }
};
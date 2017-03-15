/*Number of Islands II

Description
        Notes
Testcase
        Judge
Given a n,m which means the row and column of the 2D matrix and
an array of pair A( size k). Originally, the 2D matrix is all 0
which means there is only sea in the matrix. The list pair
has k operator and each operator has two integer A[i].x, A[i].y
means that you can change the grid matrix[A[i].x][A[i].y]
from sea to island. Return how many island are there in the matrix after each operator.

Notice

0 is represented as the sea, 1 is represented as the island.
If two 1 is adjacent, we consider them in the same island.
We only consider up/down/left/right adjacent.

Have you met this question in a real interview? Yes
Example
Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].

return [1,1,2,2].

Tags
Google Union Find
Related Problems
Medium Surrounded Regions 21 %
Easy Number of Islands*/

class Solution_union_find {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    // 找出 x所属的集合
    int find(int x) {
        if (f[x] == x)  // 集合根节点
            return x;
        return find(f[x]); //递归
    }

    // merge x to y and return status of merge operation
    //      if: x,y存在island，而且没有merge，return true
    //      else: return false
    bool merge(int x, int y) {
        if (f[x] == -1 || f[y] == -1)  // 不存在island
            return false;

        x = find(x);
        y = find(y);
        if (x != y) { // 没有merge（分属不同的set）
            f[x] = y;
            return true;
        } else  // 已经merged（在相同的set）
            return false;
    }

    bool inside(int x, int y, int n, int m) {
        return (x >= 0 && y >=0 && x < n && y < m);
    }

    vector<int> f;
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        const int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        int area = 0;

        vector<int> ret;
        f.resize(n*m);

        for (int i = 0; i < n * m; ++i) f[i] = -1;

        for (int i = 0; i <  operators.size(); i++) {
            int point = operators[i].x * m + operators[i].y;
            if (f[point] == -1) {
                area += 1;
                f[point] = point;  // mark为island
            }
            for (int k = 0; k < 4; ++k) {
                // 相邻位置，如果存在island的话，而且没有merge的话，就merge
                int x = operators[i].x + d[k][0];
                int y = operators[i].y + d[k][1];

                if (inside(x, y, n, m)) {
                    if (merge(x * m + y, point)) //merge会判断是否存在island
                        area -= 1; // 成功island数目－1
                }
            }
            ret.push_back(area);
        }
        return ret;
    }
};

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution_TLE {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    const int SEA = 0;
    const int ISLAND = 1;
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        vector<int> num_islands;

        vector<vector<int>> matrix(n, vector<int>(m,SEA));
        for (int i=0; i<operators.size(); i++) {
            matrix[operators[i].x][operators[i].y] = ISLAND;

            vector<vector<bool>> visited(n, vector<bool>(m,false));
            int count = 0;
            for (int j=0; j<=i; j++) {
                if (!visited[operators[j].x][operators[j].y]) {
                    bfs(operators[j].x,operators[j].y, matrix, visited);
                    count++;
                }
            }
            num_islands.push_back(count);
        }
        return num_islands;
    }

    void bfs(int start_x, int start_y, vector<vector<int>> &matrix,
             vector<vector<bool>> &visited) {

        int n_row = matrix.size();
        int n_col = matrix[0].size();
        vector<Point> delta { {-1,0},{1,0},{0,-1},{0,1}};

        queue<Point> p_q;
        p_q.push(Point(start_x, start_y));
        visited[start_x][start_y] = true;

        while(!p_q.empty()) {
            Point cur_p = p_q.front();
            p_q.pop();

            for (int i=0; i<delta.size();i++) {
                int next_x = cur_p.x + delta[i].x;
                int next_y = cur_p.y + delta[i].y;
                if (next_x>=0 && next_x<n_row && next_y>=0 && next_y<n_col) {
                    if (matrix[next_x][next_y] == ISLAND & !visited[next_x][next_y]) {
                        p_q.push(Point(next_x, next_y));
                        visited[next_x][next_y] = true;
                    }
                }
            }
        }
    }
};
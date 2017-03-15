/*Graph Valid Tree

Description
Given n nodes labeled from 0 to n - 1 and a list of undirected edges
(each edge is a pair of nodes), write a function to check whether these
edges make up a valid tree.

Notice
You can assume that no duplicate edges will appear in edges.
Since all edges are undirected, [0, 1] is the same as [1, 0]
and thus will not appear together in edges.

Example
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]],
return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]],
return false.

Tags
Depth First Search Facebook Zenefits Union Find Breadth First Search Google
Related Problems
Medium Connected Component in Undirected Graph*/

class Solution_1 {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // 创建邻接表（使用unordered_set方便删除）
        vector<unordered_set<int>> neigbours(n, unordered_set<int>());
        for (int i=0; i<edges.size(); i++) {
            neigbours[edges[i][0]].insert(edges[i][1]);
            neigbours[edges[i][1]].insert(edges[i][0]);
        }

        // 从任意一点开始都可以，因为tree要求图是联通的
        return bfs(0, n, neigbours);
    }

    // check if：
    //  1. there is loop by bfs
    //  2. 是否有不可达的点
    bool bfs(int start, int n, vector<unordered_set<int>> &neigbours) {

        unordered_set<int> visited;
        queue<int> node_q;
        node_q.push(start);
        visited.insert(start);
        while (!node_q.empty()) {
            int cur_node = node_q.front();
            node_q.pop();

            for (auto adj : neigbours[cur_node]) {
                if (visited.find(adj) != visited.end()) {
                    // loop found
                    return false;
                }
                node_q.push(adj);
                visited.insert(adj);
                // important:
                // 在adj的邻接表中删除cur_node,防止从adj再访问cur_node
                neigbours[adj].erase(cur_node);
            }
        }
        // 确保没有不可达的点，否则不是valid tree
        return visited.size() == n;
    }
};

class Solution_2 {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // 假如能组成一棵树，则这棵树的edge数目为n - 1
        // 有了这个bfs的话，下面bfs就不需要判断是否有环了
        if (edges.size() != n - 1) {
            return false;
        }
        // 创建邻接表（使用unordered_set方便删除）
        vector<unordered_set<int>> neigbours(n, unordered_set<int>());
        for (int i=0; i<edges.size(); i++) {
            neigbours[edges[i][0]].insert(edges[i][1]);
            neigbours[edges[i][1]].insert(edges[i][0]);
        }

        // 从任意一点开始都可以，因为tree要求图是联通的
        return bfs(0, n, neigbours);
    }

    // 基本的bfs，除了需要判断是否有不可达的点外
    bool bfs(int start, int n, vector<unordered_set<int>> &neigbours) {

        unordered_set<int> visited;
        queue<int> node_q;
        node_q.push(start);
        visited.insert(start);
        while (!node_q.empty()) {
            int cur_node = node_q.front();
            node_q.pop();

            for (auto adj : neigbours[cur_node]) {
                if (visited.find(adj) != visited.end()) {
                    continue;
                }
                node_q.push(adj);
                visited.insert(adj);
            }
        }
        // 确保没有不可达的点，否则不是valid tree
        return visited.size() == n;
    }
};
/*K Closest Points

Description
Given some points and a point origin in two dimensional space,
find k points out of the some points which are nearest to origin.
Return these points sorted by distance, if they are same with distance,
sorted by x-axis, otherwise sorted by y-axis.

Example
Given points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3
return [[1,1],[2,5],[4,4]]

Tags
        LinkedIn Heap Amazon
Related Problems
Medium K Closest Numbers In Sorted Array*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points a list of points
     * @param origin a point
     * @param k an integer
     * @return the k closest points
     */
    class Distance {
    public:
        Point p;
        double d;
        Distance(Point _p, double _d):p(_p),d(_d) {;}
    };
    vector<Point> kClosest(vector<Point>& points, Point& origin, int k) {
        // Write your code here
        auto dis_cmp = [](Distance d1, Distance d2) {
            if (d1.d < d2.d) {
                return true;
            } else if (d1.d > d2.d) {
                return false;
            } else {
                return (d1.p.x == d2.p.x)?(d1.p.y < d2.p.y):(d1.p.x < d2.p.x);
            }
        };

        priority_queue<Distance, vector<Distance>, decltype(dis_cmp)> max_q(dis_cmp);

        for (auto cur_p : points) {
            int delta_x = cur_p.x-origin.x;
            int delta_y = cur_p.y-origin.y;
            double cur_dis = sqrt(delta_x*delta_x+delta_y*delta_y);
            if (max_q.size() < k) {
                max_q.push(Distance(cur_p, cur_dis));
            } else if (max_q.size() == k) {
                Distance q_top = max_q.top();
                if (cur_dis < q_top.d) {
                    max_q.pop();
                    max_q.push(Distance(cur_p, cur_dis));
                }
            } else {
                // s.th wrong
            }
        }

        vector<Point> result;
        stack<Point> tmp_s;
        while (!max_q.empty()) {
            tmp_s.push((max_q.top()).p);
            max_q.pop();
        }
        while(!tmp_s.empty()) {
            result.push_back(tmp_s.top());
            tmp_s.pop();
        }
        return result;
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
class Solution {
public:
    /**
     * @param points a list of points
     * @param origin a point
     * @param k an integer
     * @return the k closest points
     *
     * 避免浮点允许
     */
    class Distance {
    public:
        Point p;
        int d;
        Distance(Point _p, int _d):p(_p),d(_d) {;}
    };
    vector<Point> kClosest(vector<Point>& points, Point& origin, int k) {
        auto dis_cmp = [](Distance d1, Distance d2) {
            if (d1.d == d2.d) {
                return (d1.p.x == d2.p.x)?(d1.p.y < d2.p.y):(d1.p.x < d2.p.x);
            } else {
                return d1.d < d2.d;
            }
        };

        priority_queue<Distance, vector<Distance>, decltype(dis_cmp)> max_q(dis_cmp);

        for (auto cur_p : points) {
            int delta_x = cur_p.x-origin.x;
            int delta_y = cur_p.y-origin.y;
            int cur_dis = delta_x*delta_x+delta_y*delta_y;
            if (max_q.size() < k) {
                max_q.push(Distance(cur_p, cur_dis));
            } else if (max_q.size() == k) {
                Distance q_top = max_q.top();
                if (cur_dis < q_top.d) {
                    max_q.pop();
                    max_q.push(Distance(cur_p, cur_dis));
                }
            } else {
                // s.th wrong
            }
        }

        vector<Point> result;
        stack<Point> tmp_s;  // for reverse vector
        while (!max_q.empty()) {
            tmp_s.push((max_q.top()).p);
            max_q.pop();
        }
        while(!tmp_s.empty()) {
            result.push_back(tmp_s.top());
            tmp_s.pop();
        }
        return result;
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
class Solution_final {
public:
    /**
     * @param points a list of points
     * @param origin a point
     * @param k an integer
     * @return the k closest points
     *
     * 改进比较部分
     * 使用reverse
     */
    class Distance {
    public:
        Point p;
        int d;
        Distance(Point _p, int _d):p(_p),d(_d) {;}
    };
    vector<Point> kClosest(vector<Point>& points, Point& origin, int k) {
        auto dis_cmp = [](Distance d1, Distance d2) {
            if (d1.d == d2.d) {
                return (d1.p.x == d2.p.x)?(d1.p.y < d2.p.y):(d1.p.x < d2.p.x);
            } else {
                return d1.d < d2.d;
            }
        };

        priority_queue<Distance, vector<Distance>, decltype(dis_cmp)> max_q(dis_cmp);

        for (auto cur_p : points) {
            int delta_x = cur_p.x-origin.x;
            int delta_y = cur_p.y-origin.y;
            int cur_dis = delta_x*delta_x+delta_y*delta_y;
/*
            下面这段：不错的技巧
*/
            max_q.push(Distance(cur_p, cur_dis));
            if (max_q.size() > k) {
                max_q.pop();
            }
        }

        vector<Point> result;
        while (!max_q.empty()) {
            result.push_back((max_q.top()).p);
            max_q.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};



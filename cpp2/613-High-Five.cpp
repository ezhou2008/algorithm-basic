/*High Five

Description
There are two properties in the node student id and scores,
to ensure that each student will have at least 5 points,
find the average of 5 highest scores for each person.

Example
Given results = [[1,91],[1,92],[2,93],[2,99],[2,98],[2,97],[1,60],
[1,58],[2,100],[1,61]]

Return
Tags
Heap Amazon
Related Problems
Medium Top k Largest Numbers*/


/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here

        auto recodrd_cmp = [](Record p1,Record p2) {
            return p1.score < p2.score;
        };
        priority_queue<Record,vector<Record>, decltype(recodrd_cmp)> max_h(recodrd_cmp);

        for (auto r : results) {
            max_h.push(r);
        }

        // map<int,int> (std id, number of highest scores)
        unordered_map<int,int> r_count;
        // map<int, double> (student_id, average_score)
        map<int,double> ret;
        while (!max_h.empty()) {
            Record cur_r = max_h.top();
            int cur_id = cur_r.id;
            double cur_score = cur_r.score;
            max_h.pop();

            if (r_count.find(cur_id) == r_count.end()) {
                r_count[cur_id] = 1;
                ret[cur_id] = cur_score;
            } else {
                if (r_count[cur_id] < 5) {
                    r_count[cur_id]++;
                    ret[cur_id] += cur_score;
                    if (r_count[cur_id] == 5) {
                        ret[cur_id] =  ret[cur_id]/5;
                    }
                }
            }
        } // end while
        return  ret;
    }
};


/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        unordered_map<int,vector<double>> id_scores;
        for (auto r : results) {
            if (id_scores.find(r.id) == id_scores.end() || id_scores[r.id].size()<5) {
                id_scores[r.id].push_back(r.score);
            } else {
/*
                此处必须要用"&", 否则不更新
                也可以直接使用"id_scores[r.id]"
*/
                vector<double> &cur_scores = id_scores[r.id];
                if (cur_scores.size() == 5) {
                    int cur_min = INT_MAX;
                    int cur_min_idx = -1;
                    for (int i=0; i < cur_scores.size(); i++) {
                        if (cur_scores[i] < cur_min) {
                            cur_min = cur_scores[i];
                            cur_min_idx = i;
                        }
                    }
                    if (r.score > cur_min) {
                        cur_scores[cur_min_idx] = r.score;
                    }
                }
            }
        } // end for

        map<int, double> answer;
        for (auto id_s : id_scores) {
            int cur_id = id_s.first;
            vector<double> cur_scores = id_s.second;
            answer[cur_id] = 0;
            for (auto s : cur_scores) {
                answer[cur_id] += s;
            }
            answer[cur_id] /= (cur_scores.size());
        }
        return answer;
    }
};


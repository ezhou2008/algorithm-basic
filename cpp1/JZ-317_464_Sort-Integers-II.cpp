/*Sort Integers II

Description

Given an integer array, sort it in ascending order.
Use quick sort, merge sort, heap sort or any O(nlogn) algorithm.

Example
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].

Tags
        Quick Sort Sort Merge Sort
Related Problems
Naive Sort Integers
*/
class Solution_merge {
public:
    /**
     * @param A an integer array
     * @return void
     */

    void sortIntegers2(vector<int>& A) {
        // Write your code here
        if (A.size() == 0) return;
        merge_sort(A, 0, A.size()-1);
    }

    void merge_sort(vector<int>& A, int start, int end) {
        if (start == end) return;

        int mid = start + (end-start)/2;
        //divide
        merge_sort(A, start, mid);
        merge_sort(A, mid+1, end);

        //conquer(merge)
        int p_l = start;
        int p_r = mid+1;
        vector<int> tmp_arr(end-start+1);
        int cur_idx = 0;

        while (p_l <= mid && p_r <= end) {
            if (A[p_l] < A[p_r]) {
                tmp_arr[cur_idx] = A[p_l];
                cur_idx++;
                p_l++;
            } else {
                tmp_arr[cur_idx] = A[p_r];
                cur_idx++;
                p_r++;
            }
        }

        while (p_l <= mid) {
            tmp_arr[cur_idx] = A[p_l];
            cur_idx++;
            p_l++;
        }

        while (p_r <= end) {
            tmp_arr[cur_idx] = A[p_r];
            cur_idx++;
            p_r++;
        }
        vector<int>::iterator it = A.begin();
        advance(it, start);
        copy(tmp_arr.begin(), tmp_arr.end(), it);
    }


};

class Solution_quick {
public:
    /**
     * @param A an integer array
     * @return void
     */

    void sortIntegers2(vector<int>& A) {
        // Write your code here
        quick_sort(A, 0, A.size()-1);
    }

    void quick_sort(vector<int>& A, int start, int end){
        // base cases
        if (A.size() <=1) return;
        if (start >= end) return;
// 1. partition
// 2. sort left and right

        // step 1: partition
        // 注意：pivot为值，非index
        int pivot = A[ start+(end-start)/2 ];
        // 两指针相向而行
        int left = start;
        int right = end;

/*        注意：下面partition方式对于＝＝pivot的值实际上是不做处理的，
        比如，下面是一个实际partition的例子，可以看出第一次partition时，
        对于2，并没有把所有2都放到中间（理想情况是放在中间），不过对于排序而言，
        这样没问题，还是能得到正确的排序结果。
        [2, 3, 2, 1, 2] -> [2, 1], 2, [3, 2] ->
        1, 2, 2, [3, 2] -> 1,2,2,2,3
*/


        // 注意为<=, 非<, 原因见后面注释
        while (left <= right) {
            // 左边找不属于左边的数
            // 注意：A[left]<pivot，A[right] > pivot, 非<=,>=,
            //      对于＝＝的情况，两边都是不属于，会被交换
            // 总结: index比较使用"<=", 值比较使用 "<"
            while (left <= right && A[left] < pivot) {
                left++;
            }
            // 右边找不属于右边的数
            while (left <= right && A[right] > pivot) {
                right--;
            }
            // 交换
            if (left <= right) {
                swap(A[left], A[right]);
                left++; right--;
            }
        }
        // step 2: sort left and right
            // 注意范围：［start,right], [left,end], 一般情况下＝pivot数被排除掉(也有没排除的情况）
        quick_sort(A, start, right);
        quick_sort(A, left, end);
/*        注意范围：这里就可以看出为什么while要用left <= right，
        如果left < right，意味最后left＝right，那么［start,right], [left,end]就会有重叠，
        从而导致死循环
*/

    }
};


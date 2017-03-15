/*Implement double sqrt(double x) and x >= 0.

Compute and return the square root of x.

Notice
You do not care about the accuracy of the result,
we will help you to output results.

Example
Given n = 2 return 1.41421356*/

class Solution {
public:
    /**
     * @param x a double
     * @return the square root of x
     */
    double sqrt(double x) {
        double start = 0.0;
        // end 直接设置成x就可以了，没必要找更精确的下限，因为二分法收敛得很快
        double end = x;
        double eps = 1e-12;

        // x<1.0的数sqrt比需要大（但<1.0)，所以需要人为把end设置成1.0
        if(end < 1.0) {
            end = 1.0;
        }
        while(end - start > eps) {
            // 二分浮点数 和二分整数不同
            // 一般都有一个精度的要求 譬如这题就是要求小数点后八位
            // 也就是只要我们二分的结果达到了这个精度的要求就可以
            // 所以 需要让 end 和 start 小于一个我们事先设定好的精度值 eps
            // 一般eps的设定1e-8,因为这题的要求是到1e-8,所以我把精度调到了1e-12
            // 最后 选择 start 或 end 作为一个结果即可 
            double mid = (end + start) / 2;
            if(mid * mid < x) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        return start;
    }
};

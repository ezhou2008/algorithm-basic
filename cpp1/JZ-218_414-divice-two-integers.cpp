/*Divide Two Integers

Description

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return 2147483647

Example
Given dividend = 100 and divisor = 9, return 11.
*/



class Solution {
public:
    /**
     * @param n an integer
     * @return an integer
     *
1. 典型的二分法(*2步进）。
以87除4举例，
(4 * 2 = 8)  <= 87
(4 * 4 = 16) <= 87
(4*8 = 32 )  <= 87
(4*16 = 64 ) <= 87
(4*32 = 128 ) > 87
现在我们可以确定4 * 16 = 64小于87，那么再处理87 - 64 = 23
4*4 <=23, 再处理 23-4*4 = 7
4*1 <= 7, 再处理7-4*1 ＝ 3， 此时3 < 4，结束
结果为：16+ 4+1=21

2. corner case，非常重要：

(1) x, y可能会是负数
(2) x可能为0时，返回INT_MAX或INT_MIN
(3) INT_MIN / -1 > INT_MAX，overflow
 4. 计算是需要转换成long

     *
     */
    int divide(int dividend, int divisor) {
        if (divisor == 0) return dividend >= 0 ? INT_MAX : INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; //overflow problem

        long  _dividend = abs((long)dividend);
        long _divisor = abs((long)divisor);

        int result = 0;

        while (_dividend >= _divisor ) {
            int i = 0;
            while ((_divisor << (i + 1)) <= _dividend) {
                i++;
            }
            _dividend = _dividend - (_divisor << i);
            result += 1 << i;
            // printf("divident = %d, i = %d, result = %d\n",
            //       (int)_dividend, (int)(i), (int)result);

        }

        bool positive = ((dividend >= 0) && (divisor > 0)) || ((dividend <= 0) && (divisor < 0));

        return positive ? result : -result;
    }
};
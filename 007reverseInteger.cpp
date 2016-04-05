//
// Created by Pasco on 16/4/6.
//

#include "catch.hpp"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        /*
         * 需要定义为long long
         * 否则有可能翻转后会溢出
         * */
        long long res=0;
        int n=0;
        while (x) {
            res = res*10 + x%10;
            x = x/10;
        }
        /*
         * 如果翻转后大于最大的int
         * 或小于最小的int
         * 返回0
         * */
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};

TEST_CASE("case 1 for reverse integer") {
    Solution solution;
    int foo = 1534236469;

    int expectedOutput = 0;
    int actualOutput = solution.reverse(foo);

    REQUIRE(expectedOutput == actualOutput);
}
//
// Created by Pasco on 16/4/8.
//

#include "catch.hpp"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};

TEST_CASE("CASE 1 for palindrom number") {
    Solution solution;
    int x = 10;

    bool expectedOutput = false;
    bool actualOutput = solution.isPalindrome(x);

    REQUIRE(expectedOutput == actualOutput);
}
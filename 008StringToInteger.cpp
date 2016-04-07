//
// Created by Pasco on 16/4/7.
//

#include "catch.hpp"

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int indicator = 1;
        for(int i = 0; i<str.size();)
        {
            i = str.find_first_not_of(' ');
            if(str[i] == '-' || str[i] == '+')
                indicator = (str[i++] == '-')? -1 : 1;
            while('0'<= str[i] && str[i] <= '9')
            {
                result = result*10 + (str[i++]-'0');
                if(result*indicator >= INT_MAX) return INT_MAX;
                if(result*indicator <= INT_MIN) return INT_MIN;
            }
            return result*indicator;
        }
    }
};

TEST_CASE("CASE 1 for string to integer") {
    Solution solution;
    string foo = "-2147483648";

    int expectOutput = -2147483648;
    int actualOutput = solution.myAtoi(foo);

    REQUIRE(expectOutput == actualOutput);
}
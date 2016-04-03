//
// Created by Pasco on 16/4/1.
//
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        map<int,int> mp;
        int find;

        for (int i = 0; i < numbers.size() ; ++i) {
            find = mp[target-numbers[i]];
            if(find){
                res.push_back(find);
                res.push_back(i);
                break;
            }
            mp[numbers[i]] = i;
        }
        return res;
    }
};

TEST_CASE("two sum case 1") {
    /*
     * case 1
     * */
    Solution solution;
    vector<int> fooArray = {0, 1, 2, 3, 4, 5, 6, 7};
    int target = 13;
    /*
     * expected output and actual output
     * */
    vector<int> expectedOutput = {6,7};
    vector<int> actualOutput = solution.twoSum(fooArray,target);

    /*
     * assert
     * */
    REQUIRE(expectedOutput == actualOutput);

}


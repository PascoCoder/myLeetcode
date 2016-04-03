//
// Created by Pasco on 16/4/2.
//

#include "catch.hpp"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
         *  为什么初始值设为-1?
         *  记录beginIndex的时候
         *  如果遇到重复的,那么需要将beginIndex挪动到重复位置的下一位
         *  比如:abcdebc
         *  一开始beginIndex = 0
         *  遍历到第二个b的时候,beginIndex应该挪到第一个b位置的后面
         *  即 beginIndex = 第一个b的位置 + 1
         *  既然这样的话,如果初始值设置为0
         *  那么 begin = 第一个某个字母的位置 + 1
         *  那么begin的位置总是从1开始的,所以不对
         * */
        vector<int> charVec(256, -1);
        /*
         * charVec 用来记录某个字母最后一次出现所在的位置
         * 如果重复出现,就将beginIndex挪动到 = 上次一出现的位置+1
         * */
        int longest = 0;
        int beginIndex = 0;

        for (int i = 0; i < s.length(); ++i) {
            beginIndex = max(charVec[s[i]] + 1, beginIndex);
            longest = max(longest, i - beginIndex + 1);
            charVec[s[i]] = i;          //record the char position
        }
        return longest;
    }
};


TEST_CASE("length Of Longest Substring case 1") {
    Solution solution;
    string s = "abcdefgeabc";

    int expectedOutput = 7;
    int actualOutput = solution.lengthOfLongestSubstring(s);

    REQUIRE(expectedOutput == actualOutput);

}
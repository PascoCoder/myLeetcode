//
// Created by Pasco on 16/4/4.
//

#include "catch.hpp"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*
         * 字符串长度为0和1的两种特殊情况*/
        if (s.length() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return s;
        }
        string res;
        int j = 0;
        int k = 0;
        int startPosition = 0;

        int maxLength = 0;
        for (int i = 0; i < s.length();) {
            /*
             * 如果剩余的字符串长度还没有已知最大长度回文字符长度的一半长
             * 那么就没必要往下找了,已知的那个就是最长了
             * */
            if(s.length()-i < maxLength/2){
                break;
            }
            k = i;
            j = i;
            /*
             * 如果有连续重复出现的字符
             * 那么k直接跳到重复字符结束的位置
             * 因为连续重复的字符肯定是回文
             * 所以我们要看看重复字符的两侧位置
             * sample: abccccccccbe
             * 我们要从第一个c的前面和最后一个c后面开始对比
             * j的位置是第一个c的位置
             * 所以我们要把k挪到最后一个c的位置
             * 然后对比s[k++] == s[j--]是否成立
             * 直到找到不成立的地方
             * j就是初始位置,k就是回文结束位置
             * 长度即为 k-j+1
             * */
            while (k<s.length()-1 && s[k]==s[k+1]){
                k++;
            }
            i = k+1;
            while (k<s.length()-1 && j>0 && s[j-1]==s[k+1]) {
                k++;
                j--;
            }
            int newStringLength = k-j+1;
            if(newStringLength > maxLength) {
                startPosition = j;
                maxLength = newStringLength;
            }
        }
        res = s.substr(startPosition,maxLength);
        return res;
    }
};


TEST_CASE("case 1 for longestPalindrome") {
    Solution solution;
    string fooString = "ajdfabbcbbashfja";

    string expectedOutput = "abbcbba";
    string actualOutput = solution.longestPalindrome(fooString);

    REQUIRE(expectedOutput == actualOutput);
}
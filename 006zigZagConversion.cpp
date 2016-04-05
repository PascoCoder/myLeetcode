//
// Created by Pasco on 16/4/5.
//

#include "catch.hpp"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        /*
         * 如果就一行或者总字符数还没有行数多,那么直接返回原字符串
         * */
        if(numRows<2 || s.size()<=numRows) {
            return s;
        }
        //定义一个全为0的字符串,长度和原字符串相等
        string res(s.size(),0);
        //设置一个指针指向字符串,方便后续操作
        char *p=&res[0];
        //按行遍历字符串
        for(int i=0, j,k, step=(numRows-1)*2;i<numRows;++i) {
            /*
             * 第一行和最后一行的间隔为(2n-2)
             * */
            if(i==0 || i==numRows-1)
                for(j=i;j<s.size();j+=step) {
                    *p++=s[j];
                }
                /*
                 * 第i行的间隔为(2n-2)-2i
                 * */
            else
                for(j=i, k=i*2;j<s.size();k=step-k,j+=k) {
                    *p++=s[j];
                }
        }
        return res;
    }
};

TEST_CASE("case 1 for zig zag conversion") {
    Solution solution;
    string fooString = "PAYPALISHIRING";
    int numRows = 3;

    string expectedOutput = "PAHNAPLSIIGYIR";
    string actualOutput = solution.convert(fooString, numRows);

    REQUIRE(expectedOutput == actualOutput);
}
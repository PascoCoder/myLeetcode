//
// Created by Pasco on 16/4/2.
//

#include "catch.hpp"

using namespace std;

class Solution {
private:
    /*
     * 寻找第K个数
     * */
    int findkth(int* num1, int n1, int* num2, int n2, int k)
    {
        if(n1>n2)
            return findkth(num2, n2, num1, n1, k); // ensure the first array is shorter than the second one
        if(n1==0)
            return num2[k-1];
        if(k==1)
            return min(num1[0], num2[0]);

        /*
         * 每次比较两个数组的第k/2位
         * 这样的话每次可以淘汰k/2个数
         *
         * 如果较短的数组没有k/2那么长
         * 那就比较较短数组的最后一位 和 较长数组的k-n1位
         * 这样每次可以淘汰n1个数 或者 k-n1个数
         *
         * 被淘汰的数全是小于中位数的
         * 座椅下一步开始寻找第(k-被淘汰的数量)个数
         * */
        int k1 = min(k/2, n1);
        int k2 = k - k1;
        if(num1[k1-1]==num2[k2-1])
            return num1[k1-1];
        else if(num1[k1-1]<num2[k2-1])
            return findkth(num1+k1, n1-k1, num2, n2, k-k1);
        else
            return findkth(num1, n1, num2+k2, n2-k2, k-k2);
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        /*
         * 分别放进整型数组,方便后续操作
         * */
        int n1 = nums1.size();
        int* num1=NULL;
        if(n1>0)
            num1 = (int*) malloc(n1*sizeof(int));
        for(int i=0; i<n1; i++)
            num1[i] = nums1[i];

        int n2 = nums2.size();
        int* num2=NULL;
        if(n2>0)
            num2 = (int*) malloc(n2*sizeof(int));
        for(int j=0; j<n2; j++)
            num2[j] = nums2[j];


        double result;
        int n = n1+n2;

        /*
         * 如果总数是奇数,
         * */
        if(n%2==1)
            result = 1.0*findkth(num1, n1, num2, n2, (n+1)/2);
        else
        {
            result = 0.5*findkth(num1, n1, num2, n2, n/2);
            result += 0.5*findkth(num1, n1, num2, n2, n/2+1);
        }

        if(n1>0)
            free(num1);
        if(n2>0)
            free(num2);

        return result;
    }
};


TEST_CASE("case 1 for find median sorted arrays") {
    Solution solution;

    vector<int> num1 = {};
    vector<int> num2 = {2,3};

    double expectedOutput = 2.5;
    double actualOutput = solution.findMedianSortedArrays(num1, num2);

    REQUIRE(expectedOutput == actualOutput);
}
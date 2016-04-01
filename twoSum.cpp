//
// Created by Pasco on 16/4/1.
//
#include "catch.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {

        }
    }
};

TEST_CASE("two sum case", "two sum") {
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

    REQUIRE(expectedOutput == actualOutput);




}

//#include <vector>
//#include <iostream>
//using namespace std;
//
//class Solution {
//public:
//    bool Find(vector<vector<int> > array,int target) {
//        int rowCount = array.size();
//        int colCount = array[0].size();
//        for (int i = rowCount-1,j = 0; i>=0 && j<=colCount;) {
//            if (array[i][j] == target) {
//                return true;
//            }
//            if (array[i][j] > target) {
//                i--;
//                continue;
//            }
//            if (array[i][j] < target) {
//                j++;
//                continue;
//            }
//        }
//        return false;
//    }
//};
//int main() {
//    Solution solution;
//    vector<vector<int> > a = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9}};
//    bool flag = solution.Find(a,10);
//    cout<<flag<<endl;
//    return 0;
//}

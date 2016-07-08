//
// Created by Pasco on 16/4/19.
//
//
#include "catch.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

    void quickSort(vector<int>& arr, int left, int right)
    {
        if (left >= right)
        {
            return;
        }

        int base = left;
        int i = left;
        int j = right;

        while (i != j)
        {
            while (arr[j] < arr[base] && i < j)
            {
                j--;
            }

            while (arr[i] > arr[base] && i < j)
            {
                i++;
            }
            if (i != j)
            {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[base],arr[i]);
        quickSort(arr, left, i);
        quickSort(arr, i+1,right);
    }

};

TEST_CASE("000quickSort") {
    Solution solution;
    vector<int > fooArray = {5, 2, 6, 3, 8};
    vector<int > expectOutput = {8, 6, 5, 3, 2};
    solution.quickSort(fooArray, 0, fooArray.size()-1);
    REQUIRE(expectOutput == fooArray);

}
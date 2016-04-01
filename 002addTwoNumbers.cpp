//
// Created by Pasco on 16/4/2.
//

#include "catch.hpp"
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *lastNode = NULL;
        int carry = 0;
        while(l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            ListNode *newNode = new ListNode((val1 + val2 + carry) % 10);
            carry = (val1 + val2 + carry) / 10;
            if (!res) {
                res = newNode;
                lastNode = res;
            }
            lastNode->next = newNode;
            lastNode = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (carry) {
            ListNode *carryNode = new ListNode(carry);
            lastNode->next = carryNode;
        }
        return res;
    }
};

TEST_CASE("add two numbers case","add two numbers") {
    /*
     * case 1
     * */
    Solution solution;

    //2 -> 3 -> 5
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;

    // 1 -> 4 -> 6
    ListNode *l4 = new ListNode(1);
    ListNode *l5 = new ListNode(4);
    ListNode *l6 = new ListNode(6);
    l4->next = l5;
    l5->next = l6;

    /*
     * expected output and actual output
     * */
    vector<int> expectedOutput = {3, 7, 1, 1};
    vector<int> actualOutput;
    ListNode *res = solution.addTwoNumbers(l1, l4);
    while (res) {
        actualOutput.push_back(res->val);
        res = res->next;
    }

    /*
     * assert
     * */
    REQUIRE(actualOutput == expectedOutput);


}

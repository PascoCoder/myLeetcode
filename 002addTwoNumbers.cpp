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
            }
            if (lastNode) {
             lastNode->next = newNode;
            }
            lastNode = newNode;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
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
     * case1 expected output and actual output
     * */
    vector<int> case1ExpectedOutput = {3, 7, 1, 1};
    vector<int> case1ActualOutput;
    ListNode *res = solution.addTwoNumbers(l1, l4);
    while (res) {
        case1ActualOutput.push_back(res->val);
        res = res->next;
    }

    /*
     * case1 assert
     * */
    REQUIRE(case1ActualOutput == case1ExpectedOutput);

    /*
     * case2
     * */
    ListNode *foo = new ListNode(0);
    ListNode *bar = new ListNode(0);

    /*
     * case2 expected output and actual output
     * */
    vector<int> case2ExpectedOutput = {0};
    vector<int> case2ActualOutput;
    ListNode *case2res = solution.addTwoNumbers(foo, bar);
    while (case2res) {
        case2ActualOutput.push_back(case2res->val);
        case2res = case2res->next;
    }

    /*
     * case2 assert
     * */
    REQUIRE(case2ExpectedOutput == case2ActualOutput);
}

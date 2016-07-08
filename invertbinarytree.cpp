//
// Created by Pasco on 16/4/6.
//

#include "catch.hpp"

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        TreeNode *tempTreeNode;
        tempTreeNode = root->left;
        root->left = root->right;
        root->right = tempTreeNode;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};


TEST_CASE("case 1 for invert binary tree") {
    Solution solution;

    TreeNode *node1 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(3);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(9);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;

    TreeNode *result = solution.invertTree(node1);


    vector<int> expectOutput;







}
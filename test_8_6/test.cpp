#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include<queue>

  //Definition for a binary tree node.
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
 

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int level = 0;
        while (!qu.empty()) {
            int size = qu.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < size; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                int value = node->val;
                if (level % 2 == value % 2) {
                    return false;
                }
                if ((level % 2 == 0 && value <= prev) || (level % 2 == 1 && value >= prev)) {
                    return false;
                }
                prev = value;
                if (node->left != nullptr) {
                    qu.push(node->left);
                }
                if (node->right != nullptr) {
                    qu.push(node->right);
                }
            }
            level++;
        }
        return true;
    }
};

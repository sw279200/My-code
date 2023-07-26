#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    //从根到叶的二进制之和
    int dfs(TreeNode* root, int val) {
        if (root == nullptr) {
            return 0;
        }
        val = (val << 1) | root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return val;
        }
        return dfs(root->left, val) + dfs(root->right, val);
    }


    //二叉树的坡度
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

   
        int ans = 0;

        int findTilt(TreeNode* root) {
            dfs(root);
            return ans;
        }

        int dfs(TreeNode* node) {
            if (node == nullptr) {
                return 0;
            }
            int sumLeft = dfs(node->left);
            int sumRight = dfs(node->right);
            ans += abs(sumLeft - sumRight);
            return sumLeft + sumRight + node->val;
        }

};



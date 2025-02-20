#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


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
    //汉诺塔问题
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);
    }

    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C)
    {
        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        move(n - 1, A, C, B);    // 将A上面n-1个通过C移到B
        C.push_back(A.back());  // 将A最后一个移到C
        A.pop_back();          // 这时，A空了
        move(n - 1, B, A, C);     // 将B上面n-1个通过空的A移到C

    }

    //合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* head = nullptr;
        if (list1->val < list2->val)
        {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);

        }
        else
        {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
        }

        return head;
    }

    //反转链表
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr||head->next == nullptr) return head;
        ListNode* newhead = reverseList(head->next);
        head = head->next->next;
        head->next = nullptr;
        return newhead;
    }

    // 两两交换链表中的节点
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* tmp = swapPairs(head->next->next);
        ListNode* newhead = head->next;
        newhead->next = head;
        head->next = tmp;
        return newhead;
    }

    //快速幂
    double myPow(double x, int n) {
        return n < 0 ? 1.00 / Pow(x, -(long long)n) : Pow(x, n);
    }
    double Pow(double x, int n)
    {
        if (n == 0) return 1.0;
        double tmp = Pow(x, n / 2);
        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
    }

    //计算布尔二叉树的值
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right) return root->val == 1;
        return root->val == 2 ? evaluateTree(root->left) || evaluateTree(root->right) 
            : evaluateTree(root->left) && evaluateTree(root->right);
    }

    //求根节点到叶子节点数字之和
    int _sumNumbers(TreeNode* root, int sum) {
        int presum = sum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) return presum;
        if (!root->left) return _sumNumbers(root->right, presum);

        if (!root->right) return _sumNumbers(root->left, presum);

        return _sumNumbers(root->left, presum) + _sumNumbers(root->right, presum);
    }
    int sumNumbers(TreeNode* root) {

        return _sumNumbers(root, 0);
    }

    //二叉树剪枝
    TreeNode* pruneTree(TreeNode* root) {
        if (!root->left && !root->right && root->val == 0)
        {
            delete root;
            root = nullptr;
            return nullptr;
        }

        if (!root->right) pruneTree(root->left);
        if (!root->left) pruneTree(root->right);
    }
    long prev = LONG_MIN;

    //验证二叉搜索树
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        bool left = isValidBST(root->left);
        if (left == false) return false;
        bool cur = false;
        if (root->val > prev)
        {
            prev = root->val;
            cur = true;
        }
        if (cur == false) return false;
        bool right = isValidBST(root->right);
        return left && cur && right;
    }

    //二叉搜索树中第k小的元素
    int smallk = -1;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return smallk;
    }

    void dfs(TreeNode* root, int& k)
    {
        if (!root || k == 0) return;
        dfs(root->left, k);
        k--;
        if (k == 0) smallk = root->val;
        dfs(root->right, k);
    }

    vector<string> ret;

    // 257. 二叉树的所有路径
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        if (root == nullptr) return ret;
        dfs(root, path);
        return ret;
    }

    void dfs(TreeNode* root, string path)
    {
        path += to_string(root->val);
        if (!root->left && !root->right)
        {
            ret.push_back(path);
            return;
        }
        path += "->";
        if (root->left)dfs(root->left, path);
        if (root->right)dfs(root->right, path);
    }

};

int main()
{

    return 0;
}
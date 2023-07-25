#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
public:
    //整理字符串
    string makeGood(string s) {
        string ret;
        for (char ch : s) {
            if (!ret.empty() && tolower(ret.back()) == tolower(ch) && ret.back() != ch) {
                ret.pop_back();
            }
            else {
                ret.push_back(ch);
            }
        }
        return ret;
    }


    //开幕式焰火
    int k = 0;//k来记录sum个数
    int* sum = new int[1000];//最坏所有节点颜色都不同
    int numColor(TreeNode* root) {
        if (root != NULL)
        {
            numColor(root->left);//利用递归遍历二叉树，到底部
            numColor(root->right);//到底部后开始对每个结点进行比较
            if (k == 0)//k=0，sum为空，不存在重复，第一个节点直接进入
            {
                sum[0] = root->val;
                k++;
            }
            else//此后每个节点与sum里每个节点进行比较
            {
                int i;
                for (i = 0; i < k; i++)
                {
                    if (sum[i] == root->val)
                    {
                        break;
                    }
                }
                if (i == k)//与sum所有元素都不相同，进入sum
                {
                    sum[k] = root->val;
                    k++;
                }
            }
        }
        return k;//最终遍历完所有节点，统计出“烟花”不同颜色的个数
    }
};



int main()
{
    string s = "leEeetcode";
    Solution sol;
    cout << sol.makeGood(s) << endl;    
    return 0;
}
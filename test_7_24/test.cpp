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
    //�����ַ���
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


    //��Ļʽ���
    int k = 0;//k����¼sum����
    int* sum = new int[1000];//����нڵ���ɫ����ͬ
    int numColor(TreeNode* root) {
        if (root != NULL)
        {
            numColor(root->left);//���õݹ���������������ײ�
            numColor(root->right);//���ײ���ʼ��ÿ�������бȽ�
            if (k == 0)//k=0��sumΪ�գ��������ظ�����һ���ڵ�ֱ�ӽ���
            {
                sum[0] = root->val;
                k++;
            }
            else//�˺�ÿ���ڵ���sum��ÿ���ڵ���бȽ�
            {
                int i;
                for (i = 0; i < k; i++)
                {
                    if (sum[i] == root->val)
                    {
                        break;
                    }
                }
                if (i == k)//��sum����Ԫ�ض�����ͬ������sum
                {
                    sum[k] = root->val;
                    k++;
                }
            }
        }
        return k;//���ձ��������нڵ㣬ͳ�Ƴ����̻�����ͬ��ɫ�ĸ���
    }
};



int main()
{
    string s = "leEeetcode";
    Solution sol;
    cout << sol.makeGood(s) << endl;    
    return 0;
}
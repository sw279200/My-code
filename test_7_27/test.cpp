#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
using namespace std;

struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */
    int sumOfLeftLeaves(TreeNode* root) {
        // write code here

        if (root == nullptr)
            return 0;


        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            return root->left->val;
        }
            

       return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

void test()
{
    int n, m;
    cin >> n >> m;
    list<int> mylist;
    list<int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        mylist.push_back(i);
    }
    int num = 1;
    while (mylist.size() > 1)
    {
        
        
        for (it = mylist.begin(); it != mylist.end(); )
        {
            if (num++%m==0)
            {
                it = mylist.erase(it);                
            }
            else
            {
                it++;
            }
        }
    }
    cout << *mylist.begin() << endl;
}

int main()
{
    test();
	return 0;
}
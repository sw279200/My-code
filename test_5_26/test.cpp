#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <vector>
#if 0
void solution()
{
	int n;
	cin >> n;
	int x = 0;
	int y = 0;
	cout << n * 2 << " " << n * 3 << endl;
}

int main()
{
	/*int n;
	cin >> n;
	while (n % 3 != 0)
		n++;
	cout << n;*/

	int T = 0;
	cin >> T;
	while (T--)
	{
		solution();
	}

}
#endif



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};


//二叉树前序遍历
class Solution1 {
public:

	void _preorderTraversal(TreeNode* root, vector<int>& arr)
	{
		if (root == nullptr)
			return;

		arr.push_back(root->val);
		_preorderTraversal(root->left, arr);
		_preorderTraversal(root->right, arr);

	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> array;
		_preorderTraversal(root, array);
		return array;
	}
};

//二叉树中序遍历
class Solution2 {
public:

	void _inorderTraversal(TreeNode* root, vector<int>& arr)
	{
		if (root == nullptr)
			return;


		_inorderTraversal(root->left, arr);
		arr.push_back(root->val);
		_inorderTraversal(root->right, arr);

	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> array;
		_inorderTraversal(root, array);
		return array;
	}
};


//二叉树后序遍历


class Solution3 {
public:

	void _postorderTraversal(TreeNode* root, vector<int>& arr)
	{
		if (root == nullptr)
			return;


		_postorderTraversal(root->left, arr);
		_postorderTraversal(root->right, arr);
		arr.push_back(root->val);

	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> array;
		_postorderTraversal(root, array);
		return array;
	}
};



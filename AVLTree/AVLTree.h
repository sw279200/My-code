#pragma once
#include<assert.h>
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;//balance factor

	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{ }
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			Node* cur = new Node(kv);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent ->_parent = parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				if (  parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if ( parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == 2&& cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else if(parent->_bf == -2&& cur->_bf == 1)
				{
					RotateLR(parent);
				}

				//1.旋转让这颗子树平衡了
				//2.旋转降低了这颗子树的高度，恢复到跟插入之前一样的高度，所以对上一层没有影响，不用继续更新了
				break;
				
			}
			else
			{
				assert(false);
			}

		}

		return true;
	}


	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;

		Node* parentParent = parent->_parent;
		parent->_parent = subR;
		if (subRL)
			subRL->_parent = parent;
		
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == parentParent->_left)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}

		subR->_bf = parent->_bf = 0;
	}

	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;

		Node* parentParent = parent->_parent;
		parent->_parent = subL;
		if(subLR)
			subLR->_parent = parent;
		
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent->_parent == parentParent->_left)
			{
				parentParent->_left = subL;			
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent ;
		}
		subL->_bf = parent->_bf = 0;
	}

	//双旋：先右单旋再左单旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;
		RotateL(subR);
		RotateR(parent);

		//subRL自己就是新增
		if (bf == 0)
		{
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			//subRL的左子树新增
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			//subRL的右子树新增
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}


	//双旋：先左单旋再右单旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);

		if (bf == 0)
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else if(bf==-1)
		{ 
			//subRL的左子树新增
			parent->_bf = 1;
			subL->_bf = subLR->_bf = 0;
		}
		else if (bf == 1)
		{
			//subRL的右子树新增
			subL->_bf = -1;
			parent->_bf = subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}

	}

	void InOrder(Node* root)
	{
		_InOrder(root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr) return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	int _Height(Node* root)
	{
		if (root == nullptr) return 0;

		int leftHight = _Height(root->_left);
		int rightHight = _Height(root->_right);

		return rightHight > leftHight ? rightHight + 1 : leftHight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr) return true;

		int leftHight = _Height(root->_left);
		int rightHight = _Height(root->_right);

		if (rightHight - leftHight != root->_bf)
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}

		return abs(rightHight - leftHight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}



private:
	Node* _root = nullptr;
};


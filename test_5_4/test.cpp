#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//138. 复制带随机指针的链表
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL) {
		return NULL;
	}
	for (struct Node* node = head; node != NULL; node = node->next->next) {
		struct Node* nodeNew = malloc(sizeof(struct Node));
		nodeNew->val = node->val;
		nodeNew->next = node->next;
		node->next = nodeNew;
	}
	for (struct Node* node = head; node != NULL; node = node->next->next) {
		struct Node* nodeNew = node->next;
		nodeNew->random = (node->random != NULL) ? node->random->next : NULL;
	}
	struct Node* headNew = head->next;
	for (struct Node* node = head; node != NULL; node = node->next) {
		struct Node* nodeNew = node->next;
		node->next = node->next->next;
		nodeNew->next = (nodeNew->next != NULL) ? nodeNew->next->next : NULL;
	}
	return headNew;
}

#endif
#if 1
#include <iostream>
using namespace std;

//封装案例————立方体

class Cube
{

public:
	//获取长
	int get_len()
	{
		return len;
	}
	//设置长
	void set_len(int size)
	{
		len = size;
	}
	//获取宽
	int get_width()
	{
		return width;
	}
	//设置宽
	void set_width(int w)
	{
		width = w;
	}

	//获取高
	int get_high()
	{
		return high;
	}
	//设置高
	void set_high(int h)
	{
		high = h;
	}
	//获取表面积
	int get_S()
	{
		return 2 * len * width + 2 * len * high + 2 * width * high;
	}
	//获取体积
	int get_V()
	{
		return len * width * high;
	}
	//判断两个立方体是否相等
	bool IsSame(Cube &c)
	{
		if (len == c.get_len() && width == c.get_width() && high == c.get_high())
		{
			return true;
		}

		return false;
	}

private:
	int len;//长
	int width;//宽
	int high;//高
};

bool Is_Same(Cube& c1, Cube& c2)
{
	if (c1.get_high() == c2.get_high() && c1.get_len() == c2.get_len() && c1.get_width() == c2.get_width())
		return true;

	return false;
}


int main()
{
	Cube c;
	c.set_high(10);
	c.set_len(10);
	c.set_width(10);
	cout << "该立方体的表面积为：" << c.get_S() << endl;
	cout << "该立方体的体积为：" << c.get_V() << endl;

	Cube c1;
	c1.set_high(10);
	c1.set_len(10);
	c1.set_width(10);

	cout << "全局函数判断这两个立方体是否相等：" << endl;

	if (Is_Same(c, c1))
	{
		cout << "这两个立方体相等" << endl;
	}
	else
	{
		cout << "这两个立方体不相等" << endl;
	}
	cout << "成员函数判断这两个立方体是否相等：" << endl;

	if (c.IsSame(c1))
	{
		cout << "这两个立方体相等" << endl;
	}
	else
	{
		cout << "这两个立方体不相等" << endl;
	}
	return 0;
}

#endif

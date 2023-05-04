#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//138. ���ƴ����ָ�������
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

//��װ������������������

class Cube
{

public:
	//��ȡ��
	int get_len()
	{
		return len;
	}
	//���ó�
	void set_len(int size)
	{
		len = size;
	}
	//��ȡ��
	int get_width()
	{
		return width;
	}
	//���ÿ�
	void set_width(int w)
	{
		width = w;
	}

	//��ȡ��
	int get_high()
	{
		return high;
	}
	//���ø�
	void set_high(int h)
	{
		high = h;
	}
	//��ȡ�����
	int get_S()
	{
		return 2 * len * width + 2 * len * high + 2 * width * high;
	}
	//��ȡ���
	int get_V()
	{
		return len * width * high;
	}
	//�ж������������Ƿ����
	bool IsSame(Cube &c)
	{
		if (len == c.get_len() && width == c.get_width() && high == c.get_high())
		{
			return true;
		}

		return false;
	}

private:
	int len;//��
	int width;//��
	int high;//��
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
	cout << "��������ı����Ϊ��" << c.get_S() << endl;
	cout << "������������Ϊ��" << c.get_V() << endl;

	Cube c1;
	c1.set_high(10);
	c1.set_len(10);
	c1.set_width(10);

	cout << "ȫ�ֺ����ж��������������Ƿ���ȣ�" << endl;

	if (Is_Same(c, c1))
	{
		cout << "���������������" << endl;
	}
	else
	{
		cout << "�����������岻���" << endl;
	}
	cout << "��Ա�����ж��������������Ƿ���ȣ�" << endl;

	if (c.IsSame(c1))
	{
		cout << "���������������" << endl;
	}
	else
	{
		cout << "�����������岻���" << endl;
	}
	return 0;
}

#endif

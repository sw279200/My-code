#pragma once

#include <iostream>
using namespace std;

#include <vector>
// priority_queue--->��
namespace bite
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};

	template<class T, class Container = std::vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		// ����յ����ȼ�����
		priority_queue() : c() {}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
			: c(first, last)
		{
			// ��c�е�Ԫ�ص����ɶѵĽṹ
			int count = c.size();
			int root = ((count - 2) >> 1);
			for (; root >= 0; root--)
				AdjustDown(root);
		}

		void push(const T& data)
		{
			c.push_back(data);
			AdjustUP(c.size() - 1);
		}

		void pop()
		{
			if (empty())
				return;

			swap(c.front(), c.back());
			c.pop_back();
			AdjustDown(0);
		}

		size_t size()const
		{
			return c.size();
		}

		bool empty()const
		{
			return c.empty();
		}

		// �Ѷ�Ԫ�ز������޸ģ���Ϊ���Ѷ�Ԫ���޸Ŀ��Ի��ƻ��ѵ�����
		const T& top()const
		{
			return c.front();
		}
	private:
		// ���ϵ���
		void AdjustUP(int child)
		{
			int parent = ((child - 1) >> 1);
			while (child)
			{
				if (Compare()(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
					child = parent;
					parent = ((child - 1) >> 1);
				}
				else
				{
					return;
				}
			}
		}

		// ���µ���
		void AdjustDown(int parent)
		{
			size_t child = parent * 2 + 1;
			while (child < c.size())
			{
				// ����parentΪ���Ľϴ�ĺ���
				if (child + 1 < c.size() && Compare()(c[child], c[child + 1]))
					child += 1;

				// ���˫���Ƿ��������
				if (Compare()(c[parent], c[child]))
				{
					swap(c[child], c[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					return;
			}
		}
	private:
		Container c;
	};
}

void TestQueuePriority()
{
	bite::priority_queue<int> q1;
	q1.push(5);
	q1.push(1);
	q1.push(4);
	q1.push(2);
	q1.push(3);
	q1.push(6);
	cout << q1.top() << endl;

	q1.pop();
	q1.pop();
	cout << q1.top() << endl;

	vector<int> v{ 5, 1, 4, 2, 3, 6 };
	bite::priority_queue<int, vector<int>, bite::greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;

	q2.pop();
	q2.pop();
	cout << q2.top() << endl;
}
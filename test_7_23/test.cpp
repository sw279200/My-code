#define _CRT_SECURE_NO_WARNINGS 1
 //C++����c���ԣ��ṹ�÷����Լ���ʹ��
 //ͬʱstructҲ����������
struct Stack
{
	// ��Ա����
	void Init()
	{
		a = nullptr;
		top = capacity = 0;
	}

	void Push(int x)
	{
		// ...
	}

	// ��Ա����
	int* a;
	int top;
	int capacity;
};

void StackInit(struct Stack* ps)
{
	// ...
}

void StackPush(struct Stack* ps, int x)
{

}

int main()
{
	struct Stack st1;
	StackInit(&st1);
	StackPush(&st1, 1);
	StackPush(&st1, 2);


	Stack st2;
	st2.Init();
	st2.Push(1);
	st2.Push(2);
	st2.Push(3);

	return 0;
}


//class Stack
//{
//public:
//	// ��Ա����
//	void Init()
//	{
//		a = nullptr;
//		top = capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		if (top == capacity)
//		{
//			size_t newcapacity = capacity == 0 ? 4 : capacity * 2;
//			a = (int*)realloc(a, sizeof(int) * newcapacity);
//			capacity = newcapacity;
//		}
//
//		a[top++] = x;
//	}
//
//	int Top()
//	{
//		return a[top - 1];
//	}
//
//private:
//	// ��Ա����
//	int* a;
//	int top;
//	int capacity;
//};
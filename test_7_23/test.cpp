#define _CRT_SECURE_NO_WARNINGS 1
 //C++兼容c语言，结构用法可以继续使用
 //同时struct也升级成了类
struct Stack
{
	// 成员函数
	void Init()
	{
		a = nullptr;
		top = capacity = 0;
	}

	void Push(int x)
	{
		// ...
	}

	// 成员变量
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
//	// 成员函数
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
//	// 成员变量
//	int* a;
//	int top;
//	int capacity;
//};
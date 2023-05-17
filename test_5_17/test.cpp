#define _CRT_SECURE_NO_WARNINGS 1


//#include <iostream>
//using namespace std;
//#include<vector>
//class Time
//{
//public:
//
//	void Date(vector<int>&v )
//	{
//
//	}
//
//	Time(long long year, long long month, long long day, long long hour, long long minuter, long long second)
//	{
//		this->m_year = year;
//		this->m_month = month;
//		this->m_day = day;
//		this->m_hour = hour;
//		this->m_minuter = minuter;
//		this->m_second = second;
//	}
//public:
//	long long m_year;
//	long long m_month;
//	long long m_day;
//	long long m_hour;
//	long long m_minuter;
//	long long m_second;
//};
//
//int main()
//{
//	long long year, long long month, long long day, long long hour, long long minuter, long long second;
//
//	string Second;
//	cin >> year >> month >> day >> hour >> minuter >> second >> Second;
//	Time time(year,month,day,hour,minuter,second);
//
//
//	vector<int>v;
//	for (int i = Second.empty() - 1; i >= 0; i--)
//	{
//		v.push_back(Second[i] - '0');
//	}
//	time.Date(v);
//	return 0;
//}

#if 0
//用数组实现循环队列

typedef struct {
    int* a;
    int front;
    int tail;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->tail = 0;
    obj->k = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj->tail + 1) % (obj->k + 1)) == obj->front;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }

    obj->a[obj->tail++] = value;
    obj->tail %= (obj->k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }

    obj->front++;
    obj->front %= (obj->k + 1);
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[(obj->tail + obj->k) % (obj->k + 1)];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
#endif


#if 0
//用栈实现队列
typedef struct {
    int* stk;
    int stkSize;
    int stkCapacity;
} Stack;

Stack* stackCreate(int cpacity) {
    Stack* ret = malloc(sizeof(Stack));
    ret->stk = malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}

void stackPush(Stack* obj, int x) {
    obj->stk[obj->stkSize++] = x;
}

void stackPop(Stack* obj) {
    obj->stkSize--;
}

int stackTop(Stack* obj) {
    return obj->stk[obj->stkSize - 1];
}

bool stackEmpty(Stack* obj) {
    return obj->stkSize == 0;
}

void stackFree(Stack* obj) {
    free(obj->stk);
}

typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret->inStack = stackCreate(100);
    ret->outStack = stackCreate(100);
    return ret;
}

void in2out(MyQueue* obj) {
    while (!stackEmpty(obj->inStack)) {
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);
    }
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->inStack, x);
}

int myQueuePop(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return x;
}

int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    return stackTop(obj->outStack);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj->inStack) && stackEmpty(obj->outStack);
}

void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}
#endif


#if 0
#include<cstdlib>
// 使用两个队列实现栈
// 使用两个数组（队列）和四个指针定义栈，指针分别指向对应的队首和队尾
typedef struct {
    int queue1[100], queue2[100];
    int front1, front2;
    int rear1, rear2;
} MyStack;

// 开辟一个栈
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->front1 = 0, stack->front2 = 0;
    stack->rear1 = 0, stack->rear2 = 0;
    return stack;
}

// 将元素存入队列中，存入后队尾指针 +1
void myStackPush(MyStack* obj, int x) {
    obj->queue1[(obj->rear1)++] = x;
}

int myStackPop(MyStack* obj) {
    // 优化：复制指针，减少对内存的访问次数
    int front1 = obj->front1, front2 = obj->front2;
    int rear1 = obj->rear1, rear2 = obj->rear2;

    // 将 queue1 除最后面的元素以外的所有元素都备份到 queue2
    while (rear1 - front1 > 1) {
        obj->queue2[rear2++] = obj->queue1[front1++];
    }
    // 弹出 queue1 的最后一个元素并保存
    int top = obj->queue1[front1++];
    // 将其他元素从 queue2 导回 queue1
    while (front2 != rear2) {
        obj->queue1[rear1++] = obj->queue2[front2++];
    }

    // 更新队首队尾指针
    obj->front1 = front1, obj->front2 = front2;
    obj->rear1 = rear1, obj->rear2 = rear2;

    // 返回栈顶指针
    return top;
}

// 直接返回队尾元素
int myStackTop(MyStack* obj) {
    // 注意队列的队尾是 rear-1 而不是 rear
    return obj->queue1[(obj->rear1) - 1];
}

// 若队首队尾指针相等，则队列为空，即栈为空
bool myStackEmpty(MyStack* obj) {
    return obj->rear1 == obj->front1;
}

// 将队首队尾指针都归 0
void myStackFree(MyStack* obj) {
    obj->front1 = 0, obj->front2 = 0;
    obj->rear1 = 0, obj->rear2 = 0;
}

int main()
{

    return 0;
}
#endif

#include<cstdio>

int main()
{
    int a = -3;
    int b = 2;
    b = a ^ 0xFF;
    printf("%d", 0xff);
    return 0;
}
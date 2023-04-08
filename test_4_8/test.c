#define _CRT_SECURE_NO_WARNINGS 1


//链表OJ接口题
//反转一个单链表
//struct ListNode* reverseList(struct ListNode* head) {
//
//    //方法二
//    struct ListNode* cur = head;
//    struct ListNode* newhead = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        //头插
//        cur->next = newhead;
//        newhead = cur;
//        cur = next;
//    }
//    return newhead;
//
//}


//将两个有序链表合并为一个新的有序链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//
//    if (list1 == NULL)
//    {
//        return list2;
//    }
//    if (list2 == NULL)
//    {
//        return list1;
//    }
//    struct ListNode* tail = NULL;
//    struct ListNode* head = NULL;
//    if (list1->val < list2->val)
//    {
//        head = tail = list1;
//        list1 = list1->next;
//    }
//    else
//    {
//        head = tail = list2;
//        list2 = list2->next;
//
//    }
//    while (list1 != NULL && list2 != NULL)
//    {
//        if (list1->val < list2->val)
//        {
//            tail->next = list1;
//            list1 = list1->next;
//
//        }
//        else
//        {
//            tail->next = list2;
//            list2 = list2->next;
//        }
//
//        tail = tail->next;
//    }
//    if (list1)
//    {
//        tail->next = list1;
//    }
//    if (list2)
//    {
//        tail->next = list2;
//    }
//    return head;
//}


//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点

//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//
//}

//给定一个链表，判断链表中是否有环
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            return true;
//        }
//    }
//    return false;
//}

////括号匹配问题
////栈的实现
//
//typedef char STDataType;
//
//typedef struct Stack
//{
//    STDataType* arr;
//    int top;
//    int capacity;
//}stack;
//
////初始化
//void StackInit(stack* ps)
//{
//    assert(ps);
//    ps->arr = (STDataType*)malloc(4 * sizeof(STDataType));
//    if (ps->arr == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//    ps->capacity = 4;
//    ps->top = 0;
//
//}
//
////销毁
//void StackDestroy(stack* ps)
//{
//    assert(ps);
//    free(ps->arr);
//    ps->arr = NULL;
//    ps->capacity = 0;
//    ps->top = 0;
//}
//
////压栈
//void StackPush(stack* ps, STDataType x)
//{
//    assert(ps);
//    if (ps->top == ps->capacity)
//    {
//        STDataType* temp = (STDataType*)realloc(ps->arr, ps->capacity * 2 * sizeof(STDataType));
//        if (temp == NULL)
//        {
//            printf("realloc fail\n");
//            exit(-1);
//        }
//        else
//        {
//            ps->arr = temp;
//            ps->capacity *= 2;
//        }
//    }
//    ps->arr[ps->top] = x;
//    ps->top++;
//}
//
////出栈
//void StackPop(stack* ps)
//{
//    assert(ps);
//    assert(ps->top > 0);
//    ps->top--;
//
//}
//
////返回栈顶元素
//STDataType StackTop(stack* ps)
//{
//    assert(ps);
//    assert(ps->top > 0);
//    return (ps->arr[ps->top - 1]);
//}
//
////判空
//bool StackEmpty(stack* ps)
//{
//    assert(ps);
//    return ps->top == 0;
//}
//
////栈长
//int StackSize(stack* ps)
//{
//    assert(ps);
//
//    return ps->top;
//}
//bool isValid(char* s) {
//    stack st;
//    StackInit(&st);
//    while (*s != '\0')
//    {
//        switch (*s)
//        {
//        case '(':
//        case '[':
//        case '{':
//        {
//            StackPush(&st, *s);
//            s++;
//            break;
//        }
//        case ')':
//        case ']':
//        case '}':
//        {
//            if (StackEmpty(&st))
//            {
//                StackDestroy(&st);
//                return false;
//            }
//
//            char top = StackTop(&st);
//            StackPop(&st);
//            //不匹配
//            if ((*s == ')' && top != '(')
//                || (*s == ']' && top != '[')
//                || (*s == '}' && top != '{'))
//            {
//                StackDestroy(&st);
//                return false;
//            }
//            else
//            {
//                s++;
//
//            }
//            break;
//        }
//        default:
//            break;
//
//
//        }
//    }
//    bool ret = StackEmpty(&st);
//    StackDestroy(&st);
//    return ret;
//}


//
/*
解题思路：
此题可以用两个队列去实现一个栈，每次始终保持一个队列为空，
入栈操作相当于给非空队列进行入队操作
出栈操作相当于非空队列的队尾元素出队，此时需要把非空队列除最后一个元素之外的其余元素入队到空队列，然后出队最后一个队尾元素

*/
//typedef struct {
//    Queue q1;
//    Queue q2;
//
//} MyStack;
//
///** Initialize your data structure here. */
//MyStack* myStackCreate(int maxSize) {
//    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&pst->q1);
//    QueueInit(&pst->q2);
//
//    return pst;
//}
//
///** Push element x onto stack. */
//void myStackPush(MyStack* obj, int x) {
//    //给非空队列进行入队操作
//    if (QueueEmpty(&obj->q1) != 0)
//    {
//        QueuePush(&obj->q1, x);
//    }
//    else
//    {
//        QueuePush(&obj->q2, x);
//    }
//}
//
///** Removes the element on top of the stack and returns that element. */
//int myStackPop(MyStack* obj) {
//    //把非空队列的除最后一个元素之外的剩余元素全部入队空队列
//    Queue* pEmpty = &obj->q1, * pNonEmpty = &obj->q2;
//    if (QueueEmpty(&obj->q1) != 0)
//    {
//        pEmpty = &obj->q2;
//        pNonEmpty = &obj->q1;
//    }
//
//    while (QueueSize(pNonEmpty) > 1)
//    {
//        QueuePush(pEmpty, QueueFront(pNonEmpty));
//        QueuePop(pNonEmpty);
//    }
//
//    int top = QueueFront(pNonEmpty);
//    //队尾元素出队
//    QueuePop(pNonEmpty);
//
//    return top;
//}
//
///** Get the top element. */
//int myStackTop(MyStack* obj) {
//    //获取非空队列的队尾元素
//    Queue* pEmpty = &obj->q1, * pNonEmpty = &obj->q2;
//    if (QueueEmpty(&obj->q1) != 0)
//    {
//        pEmpty = &obj->q2;
//        pNonEmpty = &obj->q1;
//    }
//
//    return QueueBack(pNonEmpty);
//}
//
///** Returns whether the stack is empty. */
//bool myStackEmpty(MyStack* obj) {
//    return !(QueueEmpty(&obj->q1) | QueueEmpty(&obj->q2));
//}
//
//void myStackFree(MyStack* obj) {
//    QueueDestory(&obj->q1);
//    QueueDestory(&obj->q2);
//    free(obj);
//}


#include<stdbool.h>
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
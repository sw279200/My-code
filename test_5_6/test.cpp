#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//链表分割
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}; 
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        auto* Big = (ListNode*)malloc(sizeof(ListNode));
        auto* Small = (ListNode*)malloc(sizeof(ListNode));
        Big->next = Small->next = nullptr;
        ListNode* cur = pHead;
        ListNode* curS = Small;
        ListNode* curB = Big;
        while (cur)
        {
            if (cur->val >= x)
            {
                curB->next = cur;
                cur = cur->next;
                curB = curB->next;
                curB->next = nullptr;
            }
            else
            {
                curS->next = cur;
                cur = cur->next;
                curS = curS->next;
                curS->next = nullptr;
            }

        }

        curS->next = Big->next;
        return Small->next;
    }
};
#endif


#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//剑指 Offer II 026. 重排链表
#include <iostream>
using namespace std;
 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:

    //反转链表
    struct ListNode* reverseList(struct ListNode* head) {

        struct ListNode* cur = head;
        struct ListNode* newhead = NULL;
        while (cur)
        {
            struct ListNode* next = cur->next;
            //头插
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;

    }
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode* fast = head;
        ListNode* low = head;
        ListNode* prev = low;
        while (fast && fast->next)
        {
            prev = low;
            low = low->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* phead = reverseList(low);
        ListNode* cur = phead;
        fast = head;
        ListNode* next = fast->next;
        while (fast->next && cur)
        {
            fast->next = cur;
            phead = phead->next;
            cur->next = fast = next;
            if (next)
                next = next->next;
            cur = phead;
        }
        if (cur)
        {
            fast->next = cur;
        }

        return;
    }
};

#endif


#if 0
#include <iostream>

using namespace std;

class Animal
{

public:
    //speak函数就是虚函数
    virtual void speak()
    {
        cout << "动物在说话 " << endl;
    }
};


class Cat : public Animal
{

public:
    //子类重写父类虚函数
    void speak()
    {
        cout << "我们一起学猫叫：一起喵喵喵" << endl;
    }
};


class Dog : public Animal
{
    
public:
    void speak()
    {
        cout << "汪汪汪" << endl;
    }
};


void LearnSpeak(Animal &animal)
{
    animal.speak();
}

void Test()
{
    Cat cat;
    LearnSpeak(cat);

    Dog dog;
    LearnSpeak(dog);
}
int main()
{
    Test();
    return 0;
}

#endif


#if 0

#include <iostream>
using namespace std;

//计算器
class AbstractCalculator
{

public:
    virtual int get_Num()
    {
        return 0;
    }

public:
    int m_Num1;
    int m_Num2;
};

//加法计算器
class AddCalculator : public AbstractCalculator
{

public:
    int get_Num()
    {
        return m_Num1 + m_Num2;
    }
};

//减法计算器
class SubCalculator :public AbstractCalculator
{

public:
    int get_Num()
    {
        return m_Num1 - m_Num2;
    }
};

//乘法计算器
class MulCalculator :public AbstractCalculator
{

public:
    int get_Num()
    {
        return m_Num1 * m_Num2;
    }
};

//除法计算器
class DivCalculator :public AbstractCalculator
{

public:
    int get_Num()
    {
        return m_Num1 / m_Num2;
    }
};

void Test()
{
    AbstractCalculator* ac = new AddCalculator;
    ac->m_Num1 = 100;
    ac->m_Num2 = 100;

    cout << ac->m_Num1 << " + " << ac->m_Num2 << " = " << ac->get_Num() << endl;
    delete ac;

    ac = new SubCalculator;
    ac->m_Num1 = 100;
    ac->m_Num2 = 100;

    cout << ac->m_Num1 << " - " << ac->m_Num2 << " = " << ac->get_Num() << endl;
    delete ac;

    ac = new MulCalculator;
    ac->m_Num1 = 100;
    ac->m_Num2 = 100;

    cout << ac->m_Num1 << " * " << ac->m_Num2 << " = " << ac->get_Num() << endl;
    delete ac;

    ac = new DivCalculator;
    ac->m_Num1 = 100;
    ac->m_Num2 = 100;

    cout << ac->m_Num1 << " / " << ac->m_Num2 << " = " << ac->get_Num() << endl;
    delete ac;
}

int main()
{
    Test();
    return 0;
}
#endif


#if 0

//多态案例二 制作饮品
#include <iostream>
using namespace std;

class AbstractDrink
{
public:
    //加入水
    virtual void addWater() = 0;

    //添加配料
    virtual void addMater() = 0;

    //倒入杯中
    virtual void putCup() = 0;

    //搅拌
    virtual void Mix() = 0;

    //实现步骤
    virtual void DoWork()
    {
        addWater();
        addMater();
        putCup();
        Mix();
    }
};

class Coffee :public AbstractDrink
{
public:
    //加入水
    virtual void addWater()
    {
        cout << "加水" << endl;
    }

    //倒入咖啡粉
    virtual void addMater()
    {
        cout << "倒入咖啡粉" << endl;
    }

    //倒入杯中
    virtual void putCup()
    {
        cout << "倒入杯中" << endl;
    }

    //搅拌
    virtual void Mix()
    {
        cout << "搅拌" << endl;
    }
};


class Tea :public AbstractDrink
{
public:
    //加入水
    virtual void addWater()
    {
        cout << "加水" << endl;
    }

    //加茶叶
    virtual void addMater()
    {
        cout << "添加茶叶 " << endl;
    }

    //倒入杯中
    virtual void putCup()
    {
        cout << "倒入杯中" << endl;
    }

    //搅拌
    virtual void Mix()
    {
        cout << "搅拌" << endl;
    }
};


void Test()
{
    Coffee cf;
    cf.DoWork();

    cout << "-----------------------" << endl;

    Tea tea;
    tea.DoWork();

}

int main()
{
    Test();
    return 0;
}
#endif


#if 0

#include <iostream>

using namespace std;

class Animal
{
public:

    Animal()
    {
        cout << "Animal的构造函数调用" << endl;
    }

    ////利用虚析构可以解决 父类指针释放子类对象时不干净的问题
    //virtual ~Animal()
    //{
    //    cout << "Animal的虚析构函数调用" << endl;
    //}
    
    
    //纯虚析构，需要声明也需要实现
    virtual ~Animal() = 0;

    //纯虚函数
    virtual void speak() = 0;

};

Animal:: ~Animal()
{
    cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat : public Animal
{
public:

    Cat(string name)
    {
        m_Name = new string(name);
        cout << "Cat的构造函数调用" << endl;
    }
    virtual void speak()
    {
        cout << * m_Name << "喵喵喵" << endl;
    }

    ~Cat()
    {
        
        if (m_Name != NULL)
        {
            cout << "Cat的析构函数调用" << endl;
            //父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄露
            delete m_Name;
        }
    }
    string* m_Name;
};

void Test()
{
    Animal* animal = new Cat("Tom在：");
    animal->speak();
    delete animal;
}


int main()
{
    Test();
    return 0;
}
#endif


//多态案例三 —— 电脑组装
#if 1
#include <iostream>
using namespace std;
//计算机组成

//CPU
class CPU
{
public:
    virtual void Running() = 0;

};

//显卡
class VedioCard
{
public:
    virtual void Display() = 0;

};

//内存条
class Memory
{
public:
    virtual void Storage() = 0;
};


class Computer
{
public:

    Computer(CPU* cpu,Memory* mem,VedioCard* vc)
    {
        m_cpu = cpu;
        m_mem = mem;
        m_vc = vc;
    }

    void Work()
    {
        m_cpu->Running();
        m_mem->Storage();
        m_vc->Display();
    }

    //提供一个析构函数，释放三个零件
    ~Computer()
    {
        //释放CPU零件
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }

        //释放内存条零件
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }

        //释放显卡零件
        if (m_vc != NULL)
        {
            delete m_vc;
            m_mem = NULL;
        }
    }

private:
    CPU* m_cpu; //CPU的零件指针
    Memory* m_mem;//内存条的零件指针
    VedioCard* m_vc;//显卡的零件指针
};

//具体产商
//Intel产商
class IntelCPU : public CPU
{
public:
    virtual void Running()
    {
        cout << "Intel 的CUP开始工作了" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void Storage()
    {
        cout << "Intel 的内存条开始存储了" << endl;
    }
};

class IntelVedioCard : public VedioCard
{
public:
    virtual void Display()
    {
        cout << "Intel 的显卡开始显示了" << endl;
    }
};

//具体产商
//Lenovo产商
class LenovoCPU : public CPU
{
public:
    virtual void Running()
    {
        cout << "Lenovo 的CUP开始工作了" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void Storage()
    {
        cout << "Lenovo 的内存条开始存储了" << endl;
    }
};

class LenovoVedioCard : public VedioCard
{
public:
    virtual void Display()
    {
        cout << "Lenovo 的显卡开始显示了" << endl;
    }
};

void Test()
{
    //生产三个零件
    CPU* intelcpu = new IntelCPU;
    Memory* intelmem = new IntelMemory;
    VedioCard* intelvc = new IntelVedioCard;

    //组装第一台电脑
    Computer * computer1 = new Computer(intelcpu, intelmem, intelvc);
    cout << "第一台电脑开始工作了" << endl;
    computer1->Work();
    delete computer1;
    
    cout << "--------------" << endl;

    //组装第二台电脑
    Computer* computer2 = new Computer(new LenovoCPU,new LenovoMemory,new LenovoVedioCard);
    cout << "第二台电脑开始工作了" << endl;
    computer2->Work();
    delete computer2;
    
    cout << "--------------" << endl;
    //组装第三台电脑
    Computer* computer3 = new Computer(new LenovoCPU, new IntelMemory, new LenovoVedioCard);
    cout << "第三台电脑开始工作了" << endl;
    computer3->Work();
    delete computer3;

}

int main()
{
    Test();
    return 0;
}


#endif

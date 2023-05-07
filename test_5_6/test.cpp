#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//����ָ�
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

//��ָ Offer II 026. ��������
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

    //��ת����
    struct ListNode* reverseList(struct ListNode* head) {

        struct ListNode* cur = head;
        struct ListNode* newhead = NULL;
        while (cur)
        {
            struct ListNode* next = cur->next;
            //ͷ��
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
    //speak���������麯��
    virtual void speak()
    {
        cout << "������˵�� " << endl;
    }
};


class Cat : public Animal
{

public:
    //������д�����麯��
    void speak()
    {
        cout << "����һ��ѧè�У�һ��������" << endl;
    }
};


class Dog : public Animal
{
    
public:
    void speak()
    {
        cout << "������" << endl;
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

//������
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

//�ӷ�������
class AddCalculator : public AbstractCalculator
{

public:
    int get_Num()
    {
        return m_Num1 + m_Num2;
    }
};

//����������
class SubCalculator :public AbstractCalculator
{

public:
    int get_Num()
    {
        return m_Num1 - m_Num2;
    }
};

//�˷�������
class MulCalculator :public AbstractCalculator
{

public:
    int get_Num()
    {
        return m_Num1 * m_Num2;
    }
};

//����������
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

//��̬������ ������Ʒ
#include <iostream>
using namespace std;

class AbstractDrink
{
public:
    //����ˮ
    virtual void addWater() = 0;

    //�������
    virtual void addMater() = 0;

    //���뱭��
    virtual void putCup() = 0;

    //����
    virtual void Mix() = 0;

    //ʵ�ֲ���
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
    //����ˮ
    virtual void addWater()
    {
        cout << "��ˮ" << endl;
    }

    //���뿧�ȷ�
    virtual void addMater()
    {
        cout << "���뿧�ȷ�" << endl;
    }

    //���뱭��
    virtual void putCup()
    {
        cout << "���뱭��" << endl;
    }

    //����
    virtual void Mix()
    {
        cout << "����" << endl;
    }
};


class Tea :public AbstractDrink
{
public:
    //����ˮ
    virtual void addWater()
    {
        cout << "��ˮ" << endl;
    }

    //�Ӳ�Ҷ
    virtual void addMater()
    {
        cout << "��Ӳ�Ҷ " << endl;
    }

    //���뱭��
    virtual void putCup()
    {
        cout << "���뱭��" << endl;
    }

    //����
    virtual void Mix()
    {
        cout << "����" << endl;
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
        cout << "Animal�Ĺ��캯������" << endl;
    }

    ////�������������Խ�� ����ָ���ͷ��������ʱ���ɾ�������
    //virtual ~Animal()
    //{
    //    cout << "Animal����������������" << endl;
    //}
    
    
    //������������Ҫ����Ҳ��Ҫʵ��
    virtual ~Animal() = 0;

    //���麯��
    virtual void speak() = 0;

};

Animal:: ~Animal()
{
    cout << "Animal�Ĵ���������������" << endl;
}

class Cat : public Animal
{
public:

    Cat(string name)
    {
        m_Name = new string(name);
        cout << "Cat�Ĺ��캯������" << endl;
    }
    virtual void speak()
    {
        cout << * m_Name << "������" << endl;
    }

    ~Cat()
    {
        
        if (m_Name != NULL)
        {
            cout << "Cat��������������" << endl;
            //����ָ��������ʱ�򣬲����������������������������������ж������ԣ������ڴ�й¶
            delete m_Name;
        }
    }
    string* m_Name;
};

void Test()
{
    Animal* animal = new Cat("Tom�ڣ�");
    animal->speak();
    delete animal;
}


int main()
{
    Test();
    return 0;
}
#endif


//��̬������ ���� ������װ
#if 1
#include <iostream>
using namespace std;
//��������

//CPU
class CPU
{
public:
    virtual void Running() = 0;

};

//�Կ�
class VedioCard
{
public:
    virtual void Display() = 0;

};

//�ڴ���
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

    //�ṩһ�������������ͷ��������
    ~Computer()
    {
        //�ͷ�CPU���
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }

        //�ͷ��ڴ������
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }

        //�ͷ��Կ����
        if (m_vc != NULL)
        {
            delete m_vc;
            m_mem = NULL;
        }
    }

private:
    CPU* m_cpu; //CPU�����ָ��
    Memory* m_mem;//�ڴ��������ָ��
    VedioCard* m_vc;//�Կ������ָ��
};

//�������
//Intel����
class IntelCPU : public CPU
{
public:
    virtual void Running()
    {
        cout << "Intel ��CUP��ʼ������" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    virtual void Storage()
    {
        cout << "Intel ���ڴ�����ʼ�洢��" << endl;
    }
};

class IntelVedioCard : public VedioCard
{
public:
    virtual void Display()
    {
        cout << "Intel ���Կ���ʼ��ʾ��" << endl;
    }
};

//�������
//Lenovo����
class LenovoCPU : public CPU
{
public:
    virtual void Running()
    {
        cout << "Lenovo ��CUP��ʼ������" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    virtual void Storage()
    {
        cout << "Lenovo ���ڴ�����ʼ�洢��" << endl;
    }
};

class LenovoVedioCard : public VedioCard
{
public:
    virtual void Display()
    {
        cout << "Lenovo ���Կ���ʼ��ʾ��" << endl;
    }
};

void Test()
{
    //�����������
    CPU* intelcpu = new IntelCPU;
    Memory* intelmem = new IntelMemory;
    VedioCard* intelvc = new IntelVedioCard;

    //��װ��һ̨����
    Computer * computer1 = new Computer(intelcpu, intelmem, intelvc);
    cout << "��һ̨���Կ�ʼ������" << endl;
    computer1->Work();
    delete computer1;
    
    cout << "--------------" << endl;

    //��װ�ڶ�̨����
    Computer* computer2 = new Computer(new LenovoCPU,new LenovoMemory,new LenovoVedioCard);
    cout << "�ڶ�̨���Կ�ʼ������" << endl;
    computer2->Work();
    delete computer2;
    
    cout << "--------------" << endl;
    //��װ����̨����
    Computer* computer3 = new Computer(new LenovoCPU, new IntelMemory, new LenovoVedioCard);
    cout << "����̨���Կ�ʼ������" << endl;
    computer3->Work();
    delete computer3;

}

int main()
{
    Test();
    return 0;
}


#endif

#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
using namespace std;

//�ݹ�˷��� дһ���ݹ麯������ʹ�� * ������� ʵ����������������ˡ�
//����ʹ�üӺš����š�λ�ƣ���Ҫ����һЩ��
class Solution {
public:
    int multiply(int A, int B) {
        if (A != 0 && B != 0)
            return A > B ? A + multiply(A, B - 1) : B + multiply(A - 1, B);
        else
            return 0;
    }
};

int main()
{
    Solution sol;
    cout << sol.multiply(918795921, 1) << endl;
	return 0;
}

#endif;

#include <iostream>
using namespace std;

//��� 1��n֮�� ���� 7 �й����ֵĸ�����
//һ������7�й���ָ������� 7 �ı�����
//�����ǰ��� 7 �����֣��� 17 ��27 ��37 ... 70 ��71 ��72 ��73...��

bool isInclude7(int n)
{
    
    while (n > 0)
    {
        if (n % 10 == 7)
            return true;
        n /= 10;
    }
    return false;
}
int main()
{
    int n = 0;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 7 == 0 || isInclude7(i))
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <iostream>

using namespace std;
////1���ַ���ѹ���������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ�����ܡ�
//���磬�ַ��� aabcccccaaa ���Ϊ a2b1c5a3 ������ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ���������Լ�����
//������ֻ������СдӢ����ĸ��a��z��
class Solution {
public:
    string compressString(string S) {
        string str = "";
        for (int i = 0; i < S.length(); i++)
        {
            str += S[i];
            int count = 1;
            for (int j = i; j < S.length(); j++)
            {
                if (j + 1 < S.length() && S[j] == S[j + 1]) {
                    count++;
                }
                else
                {
                    char arr[6];
                    str += _itoa(count, arr, 10);
                    i += count - 1;
                    break;
                }
            }

        }

        return str.length() < S.length() ? str : S;
    }
};
int main()
{
    Solution sol;
    string s = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";
    cout << sol.compressString(s) << endl;
    return 0;
}
#endif


#include <iostream>
using namespace std;
//��Խ�������д���򣬽���ĳ������������λ��ż��λ������ʹ�ý��ٵ�ָ�Ҳ����˵��λ0��λ1������λ
//2��λ3�������Դ����ƣ���
class Solution {
public:
    int exchangeBits(int num) {
        int arr[32];
        for (int i = 0; i < 32; i++)
        {
            arr[i] = num >> i & 1;
        }
        for (int i = 0; i < 32; i += 2)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        int sum = 0;
        for (int i = 0; i < 32; i++)
        {
            sum += arr[i] * pow(2, i);
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    cout << sol.exchangeBits(100) << endl;
    return 0;
}
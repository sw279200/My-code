#if 1
#include <iostream>
using namespace std;

//��һ��ֻ����һ�ε��ַ�
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param str string�ַ���
     * @return int����
     */
    int FirstNotRepeatingChar(string str) {
        // write code here
        int len = str.size();
        for (int i = 0; i < len; i++) {
            if (str.find_first_of(str[i]) == str.find_last_of(str[i])) {
                return i;
            }
        }
        return -1;
    }
};
#endif


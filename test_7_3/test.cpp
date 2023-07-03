#if 1
#include <iostream>
using namespace std;

//第一次只出现一次的字符
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return int整型
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


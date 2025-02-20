#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*首先，这个题不考虑字母*/
/*那就简单多了，只考虑数字，遇到其他情况直接返回-1就行了*/
class Solution {
public:
    int StrToInt(string str) {
        int ans = 0; int isplus = 1;
        for (char ch : str) {
            if (isalpha(ch)) {
                return 0;
            }if (ch == '+' || ch == '-') {
                isplus = (ch == '+') ? 1 : -1;
            }if (isdigit(ch)) {
                ans = ans * 10 + ch - '0';
            }
        }return isplus * ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.StrToInt("+12345678910") << endl;
	return 0;
}
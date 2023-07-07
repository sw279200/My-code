#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str.length() >= 10) {
			cout << str[0] << str.length()-2 << str[str.length() - 1] << endl;
		}
		else
		{
			cout << str << endl;
		}
	}
	return 0;
}

#endif


#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	string replaceSpaces(string S, int length) {
		string str = "";
		for (int i = 0; i < length; i++) {
			if (S[i] != ' ') {
				str += S[i];
			}
			else
			{
				str += "%20";
			}
		}
		return str;
	}
};

int main()
{
	Solution sol;
	cout << sol.replaceSpaces("Mr John Smith    ", 13) << endl;
	return 0;
}
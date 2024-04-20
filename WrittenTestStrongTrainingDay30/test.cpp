#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include <cmath>  
#include <unordered_set>  
using namespace std;

//最难的问题
string getplaintext(const string& ciphertext)
{
	string plaintext;
	for (auto& ch : ciphertext)
	{
		if (ch == ' ')plaintext += ' ';
		else if (ch - 5 >= 'A') plaintext += ch - 5;
		else plaintext += (ch + 21);
	}

	return plaintext;
}

//因子个数

int countDistinctPrimeFactors(int n) {
	//std::unordered_set<int> primeFactors;
	//int divisor = 2;
	//while (n > 1) {
	//	while (n % divisor == 0) {
	//		primeFactors.insert(divisor); // 将质因子插入集合中  
	//		n /= divisor; // 去除当前质因子的所有幂次  
	//	}
	//	// 尝试下一个可能的质数作为除数  
	//	divisor = (divisor == 2) ? 3 : divisor + 2;
	//	// 跳过偶数，因为我们已经用2试过了  
	//}
	//// 返回不同质因子的个数  
	//return primeFactors.size();

	std::unordered_set<int> primeFactors;
	// 只需要检查到sqrt(n)  
	for (int i = 2; i * i <= n; ++i) {
		// 当i是n的因子时  
		while (n % i == 0) {
			primeFactors.insert(i); // 插入质因子  
			n /= i; // 去除这个质因子的所有幂次  
		}
	}
	// 如果n是一个大于1的质数，则它自身也是一个质因子  
	if (n > 1) {
		primeFactors.insert(n);
	}
	// 返回不同质因子的个数  
	return primeFactors.size();
}

int main()
{
	/*string ciphertext;
	while (getline(cin, ciphertext))
	{
		cout << getplaintext(ciphertext) << endl;
	}*/

	int n = 0;
	while (cin >> n)
	{
		cout << countDistinctPrimeFactors(n) << endl;;
	}
	

	return 0;
}
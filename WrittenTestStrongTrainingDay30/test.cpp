#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include <cmath>  
#include <unordered_set>  
using namespace std;

//���ѵ�����
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

//���Ӹ���

int countDistinctPrimeFactors(int n) {
	//std::unordered_set<int> primeFactors;
	//int divisor = 2;
	//while (n > 1) {
	//	while (n % divisor == 0) {
	//		primeFactors.insert(divisor); // �������Ӳ��뼯����  
	//		n /= divisor; // ȥ����ǰ�����ӵ������ݴ�  
	//	}
	//	// ������һ�����ܵ�������Ϊ����  
	//	divisor = (divisor == 2) ? 3 : divisor + 2;
	//	// ����ż������Ϊ�����Ѿ���2�Թ���  
	//}
	//// ���ز�ͬ�����ӵĸ���  
	//return primeFactors.size();

	std::unordered_set<int> primeFactors;
	// ֻ��Ҫ��鵽sqrt(n)  
	for (int i = 2; i * i <= n; ++i) {
		// ��i��n������ʱ  
		while (n % i == 0) {
			primeFactors.insert(i); // ����������  
			n /= i; // ȥ����������ӵ������ݴ�  
		}
	}
	// ���n��һ������1����������������Ҳ��һ��������  
	if (n > 1) {
		primeFactors.insert(n);
	}
	// ���ز�ͬ�����ӵĸ���  
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
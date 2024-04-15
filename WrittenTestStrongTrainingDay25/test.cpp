#define _CRT_SECURE_NO_WARNINGS 1

//Êý¸ù
//#include<iostream>
//#include<string>
//using namespace std;
//
//int get(int n)
//{
//	return (n - 1) % 9 + 1;
//}
//
//
//int main()
//{
//	size_t n = 0;
//	while (cin >> n)
//	{
//		cout << get(n) << endl;
//	}
//	return 0;
//}

//ÐÇ¼ÊÃÜÂë
#include<cstdio>
#include<iostream>
using namespace std;

const int SIZE = 10010;
int f[SIZE] = { 1, 1, 2 };


int main() {
    for (int i = 3; i < SIZE; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % 10000;
    }

    int n = 0;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int x = 0;
            cin >> x;
            printf("%04d", f[x]);
        }
        cout << endl;
    }
    return 0;
}


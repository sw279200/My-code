#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>
char* reversed(char* str) {
	static char s[100];
	char* p;
	int i, count = 0;
	p = str;
	/**********Program**********/
	while (p[count])count++;
	for (i = 0; i < count; i++) s[i] = p[count-i-1];
	/**********  End  **********/
	return s;
}
int main() {
	char str[20];
	char* res;
	printf("������һ���ַ�����");
	gets(str);
	res = reversed(str);
	printf("����ת��%s\n", res);
	system("pause");
	return 0;
}
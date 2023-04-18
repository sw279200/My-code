#define _CRT_SECURE_NO_WARNINGS 1

#if 1

//FJµÄ×Ö·û´®
#include <stdio.h>
#include <string.h>
void func(int x)
{
	if (x == 1)
	{
		printf("%c", 'A');
	}
	else
	{
		func(x - 1);
		printf("%c", 'A' + x - 1);
		func(x - 1);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	func(n);
	printf("\n");
	return 0;
}
#endif






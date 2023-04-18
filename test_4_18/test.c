#define _CRT_SECURE_NO_WARNINGS 1

#if 1

//FJµÄ×Ö·û´®
#include <stdio.h>
#include <string.h>
#define N 64000000

void solve()
{
	int n = 0;
	scanf("%d", &n);
	char* pa = func(n);
	printf("%s\n", pa);
}

int main()
{
	solve();
	return 0;
}
#endif



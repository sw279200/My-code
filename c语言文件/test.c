#include<stdio.h>
int main()
{
	char ch;
	while (scanf("%c\n", &ch)!=EOF)
	{
		if (ch >= 'a' && ch <= 'z' || ch >= 'a' && ch <= 'z')
		{
			printf("%c is an alphabet.\n", ch);

		}
		else
		{
			printf("%c is not an alphabet.\n", ch);
		}
	}
	return 0;
}

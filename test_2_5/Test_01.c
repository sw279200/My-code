<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main() {
//
//	printf("The size of short is %d bytes.\n", sizeof(short));
//	printf("The size of int is %d bytes.\n", sizeof(int));
//	printf("The size of long is %d bytes.\n", sizeof(long));
//	printf("The size of long long is %d bytes.\n", sizeof(long long));
//
//	return 0;
//
//}

//int main() {
//
//	int count = 1234;          
//	printf("%#o %#X", count,count);    
//	return 0;
//}
/*printf可以使用使用格式控制串“ % o”、“ % X”
分别输出八进制整数和十六进制整数，并使用修饰符“#”控制前导显示*/

int main() {

	int n;   //输入一个四位数，反向输出该四位数
	scanf("%d", &n);
		int a = n % 10;
		int b = (n / 10)%10;
		int c = (n / 100) % 10;
		int d = n / 1000;
		printf("%d%d%d%d", a, b, c, d);
	
	return 0;
}
//int main() {
//
//	char character;
//	while (scanf("%c", &character)!=EOF) {
//		getchar();
//		printf("%c\n", (character + 32));
//	}
//	return 0;
//}
//int main() {
//
//	int m = printf("Hello world!");
//	printf("\n");
//	printf("%d", m);
//	return 0;
//}
//int main() {
//	long int id;
//	float score1, score2, score3;
//	scanf("%ld;%f,%f,%f", &id, &score1, &score2, &score3);
//	printf("The each subject score of No. %ld is %.2f, %.2f, %.2f.", id, score1, score2, score3);
//
//		return 0;
//	}
//int main() {
//
//	int year;
//	int month;
//	int date;
//	scanf("%4d%2d%2d", &year, &month, &date);
//	printf("year=%d\nmonth=%02d\ndate=%02d\n", year, month, date);
//	return 0;
//}
//
//int main() {
//
//	char a,b;
//	long int m,n;
//	scanf("%c=%ld,%c=%ld", &a, &n, &b, &m);
//	printf("%c=%ld,%c=%ld", a, m, b, n);
//	return 0;
//}
//int main() {
//	
//int m = 0xABCDEF;
//	printf("%15d", m);
//	return 0;
//}


	
=======
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main() {
//
//	printf("The size of short is %d bytes.\n", sizeof(short));
//	printf("The size of int is %d bytes.\n", sizeof(int));
//	printf("The size of long is %d bytes.\n", sizeof(long));
//	printf("The size of long long is %d bytes.\n", sizeof(long long));
//
//	return 0;
//
//}

//int main() {
//
//	int count = 1234;          
//	printf("%#o %#X", count,count);    
//	return 0;
//}
/*printf可以使用使用格式控制串“ % o”、“ % X”
分别输出八进制整数和十六进制整数，并使用修饰符“#”控制前导显示*/

int main() {

	int n;   //输入一个四位数，反向输出该四位数
	scanf("%d", &n);
		int a = n % 10;
		int b = (n / 10)%10;
		int c = (n / 100) % 10;
		int d = n / 1000;
		printf("%d%d%d%d", a, b, c, d);
	
	return 0;
}
//int main() {
//
//	char character;
//	while (scanf("%c", &character)!=EOF) {
//		getchar();
//		printf("%c\n", (character + 32));
//	}
//	return 0;
//}
//int main() {
//
//	int m = printf("Hello world!");
//	printf("\n");
//	printf("%d", m);
//	return 0;
//}
//int main() {
//	long int id;
//	float score1, score2, score3;
//	scanf("%ld;%f,%f,%f", &id, &score1, &score2, &score3);
//	printf("The each subject score of No. %ld is %.2f, %.2f, %.2f.", id, score1, score2, score3);
//
//		return 0;
//	}
//int main() {
//
//	int year;
//	int month;
//	int date;
//	scanf("%4d%2d%2d", &year, &month, &date);
//	printf("year=%d\nmonth=%02d\ndate=%02d\n", year, month, date);
//	return 0;
//}
//
//int main() {
//
//	char a,b;
//	long int m,n;
//	scanf("%c=%ld,%c=%ld", &a, &n, &b, &m);
//	printf("%c=%ld,%c=%ld", a, m, b, n);
//	return 0;
//}
//int main() {
//	
//int m = 0xABCDEF;
//	printf("%15d", m);
//	return 0;
//}


	
>>>>>>> 6468e2cf8e09c6a3001d43ca944523668294f635

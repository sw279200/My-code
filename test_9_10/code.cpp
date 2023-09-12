#define _CRT_SECURE_NO_WARNINGS 1
#include"code.h"

 #define SIZE 101
 #define MAXSIZE 100
 #define STYLE '#'
 #define CTIME 100
 const char* str = "|/-\\";



 void process()
 {
	     //version 1
		     int rate = 0;
	     char c_str[SIZE] = { 0 };
	     int len = strlen(str);
	     while (rate <= MAXSIZE)
		     {
		         printf("[%-100s][%-3d%%][%c] loading....\r", c_str, rate, str[rate % len]);				 
		         Sleep(CTIME);
		         c_str[rate++] = STYLE;
		     }
		 cout << endl;
		 cout << "加载资源成功！" << endl;

			 
 }

 int main()
 {
	 process();
	 return 0;
 }

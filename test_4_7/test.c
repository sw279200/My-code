#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#define N 1000000
//��n��Χ��һȦ��˳���źš��ӵ�1���˿�ʼ��������1��3��������
 //������3�����˳�Ȧ�ӣ���������µ���ԭ���ĵڼ��ŵ���λ
 
void main()
{
	int group[N];
	int totalNum = 0, restNum = 0, count = 0, roundcount = 0;

	scanf("%d", &totalNum);

	//�źŲ���
	for (int i = 0; i < totalNum; i++)
	{
		group[i] = i + 1;
	}

	restNum = totalNum;

	//ֻҪ��ֻʣ��һ����,��ô���ظ�����
	while (restNum > 1)
	{
		roundcount = 0;
		//������������,�ظ�����,ֱ��һ�ֽ���
		while (roundcount < totalNum)
		{
			if (group[roundcount] != 0)
			{
				count++;
				//����3��ͷ����
				if (count == 3)
				{
					group[roundcount] = 0;//�˳�������0Ϊ��ʶ
					restNum--;
					count = 0;
				}
			}
			roundcount++;
		}
	}

	for (int i = 0; i < totalNum; i++)
	{
		if (group[i] != 0)
		{
			printf("%d", group[i]);
			break;
		}
	}
}

//#include<stdio.h>
////����ת��
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[20] = { 0 };
//	int i = 0;
//	while (n)
//	{
//		arr[i++] = n % 8;
//		n /= 8;
//		
//	}
//	while (i--)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[18]={0};
//	int i = 0;
//	for (i = 0; i < 18; i++)
//	{
//		if (i <= n - 1)
//		{
//			arr[i] = 1;
//		}
//		
//		if ((i+1)%6==0)
//			printf("%d\n", arr[i]);
//		else
//		printf("%d", arr[i]);
//		
//	}
//	return 0;
//}

#include<stdio.h>
#include<string.h>
int a[10000000];//�жϰ�ȫ���Ƿ�ʹ�ù�

int safe[3];//�ݴ氲ȫ��
int main() {
    memset(a, 0, sizeof(a));//���а�ȫ����ֵ��0
    int m, q;
    int cnt = 0;//�ж��м��Ű�ȫ��
    scanf("%d%d", &m, &q);
    for (int i = 1; i <= q; i++) {
        int op;// 1�Է����� 2�Է�����
        int sum;//�Է��õ�����
        scanf("%d%d", &op, &sum);
        int l = (sum - 3);//�Է��õ����� ���Ӧ�İ�ȫ��(x-3)
        int r = (sum + 3);//�Է��õ����� ���Ӧ�İ�ȫ��(x+3)
        safe[1] = l;
        safe[2] = r;
        for (int j = 1; j <= 2; j++) {
            if (safe[j]<1 || safe[j]>m)continue;//Խ���׳�
            //�Է�����
            if (op == 1) {
                if (a[safe[j]] == 0) {//��ʾ�����ȫ��ûʹ��
                    cnt++;//��ȫ����������
                }
                //��Ӧ��ȫ����������
                a[safe[j]]++;
            }
            //�Է�����
            else {
                if (a[safe[j]] == 1) {
                    //���Է�����ֻ��һ�Ų���Ҫ��
                    // �����Ӧ�İ�ȫ��Ҳ��������
                    cnt--;//��ȫ����������
                }
                //��Ӧ��ȫ����������
                a[safe[j]]--;
            }
        }
        printf("%d\n", cnt);
    }

}



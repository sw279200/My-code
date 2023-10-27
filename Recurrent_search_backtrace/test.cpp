#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
public:
    //��ŵ������
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) { 
        int n = A.size();
        move(n, A, B, C);
    } 

    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C)
    {
        if (n == 1) {
            C.push_back(A.back());
            A.pop_back();
            return;
        }

        move(n - 1, A, C, B);    // ��A����n-1��ͨ��C�Ƶ�B
        C.push_back(A.back());  // ��A���һ���Ƶ�C
        A.pop_back();          // ��ʱ��A����
        move(n - 1, B, A, C);     // ��B����n-1��ͨ���յ�A�Ƶ�C

    }
};

int main()
{

    return 0;
}
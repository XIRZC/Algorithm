//���������������-��̬�滮�㷨
#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=10005;  //���е������
int mat[N];  //Դ��������
int dp[N];   //��̬�滮��ֵ���飬��������ת��Ϊ��ǰi��Ԫ���еĵ�����������������������i��Ԫ��

int main(void)
{
    int n;  //���ݸ���
    cin >>n;
    for(int i=1;i<=n;i++)
        cin >>mat[i];
    for(int i=1;i<=n;i++)
        cout <<dp[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            if(mat[j]<mat[i])
                dp[i]=max(dp[j]+1,dp[i]);
        }
    }
    int m=dp[1];
    for(int i=2;i<=n;i++)
    {
        if(m<dp[i])
            m=dp[i];
    }
    cout <<m;
    return 0;
}


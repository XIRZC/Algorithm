// ����ȡ����Ϸ-��һ����������Ͻ�ֻ�������߻������ߣ�ʹ�������ӻ��ֺ����
//��̬�滮�㷨
#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=510;
int a[N][N];  //���ԭ���ݾ���
int dp[N][N];  //��̬�滮����ֵ��������ת��Ϊ�����Ͻ��ߵ���Ϊi��Ϊj�ĸ��ӵ������ֺ�
int main(void)
{
    int n;
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >>a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1&&j==1)
                dp[i][j]=a[i][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    /*
    cout <<"-----------------------" <<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout <<dp[i][j] <<" ";
        cout <<endl;
    }*/
    cout <<dp[n][n];
    return 0;
}


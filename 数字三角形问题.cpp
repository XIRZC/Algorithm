//�������������⣬��̬�滮���
#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=105; //�������
int mat[N][N],dp[N][N];  //ԭ���ݾ���Ͷ�̬�滮���󣬱�ʾ�Ե�i�е�j�е�Ԫ��Ϊ���������ε����б���
int main(void)
{
    int n;
    cin >>n;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin >>mat[i][j];
    for(int i=n;i>=1;i--)
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(mat[i][j]+dp[i+1][j],mat[i][j]+dp[i+1][j+1]);
        }
    cout <<dp[1][1];
    return 0;
}


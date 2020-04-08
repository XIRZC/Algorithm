//���������������-��̬�滮���
#include<iostream>
#include<cstring>

using namespace std;

const int N=1005;  //���ַ����������
char s1[N],s2[N];  //��Դ�ַ�������
int dp[N][N];  //��̬�滮����ֵ����
int dps[N][N];  //���ŽⱣ����Ϣ����

int LCSLength(char s1[],char s2[],int n,int m,int dp[][N],int dps[][N]);  //��������ֵ���������Ž���Ϣ
void LCS(int n,int m,char s1[],int dps[][N]);  //������ŽⲢ���
int main(void)
{
    int n,m;
    cin >>s1 >>s2;  //ע�������ȡ�Ǵ�0��ʼ���ģ���������±����0��ʼ����
    n=strlen(s1);
    m=strlen(s2);
    memset(dps,0,sizeof(dp));
    cout <<LCSLength(s1,s2,n,m,dp,dps) <<endl;
    LCS(n-1,m-1,s1,dps);
    return 0;
}
int LCSLength(char s1[],char s2[],int n,int m,int dp[][N],int dps[][N])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                dps[i][j]=1;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                dps[i][j]=2;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
                dps[i][j]=3;
            }
        }
    }
    return dp[n-1][m-1];
}
void LCS(int n,int m,char s1[],int dps[][N])
{
    if(n==-1||m==-1)  return;  //�±��0��ʼ��Ҳ�ʹ�-1�ݹ����
    if(dps[n][m]==1)
    {
        LCS(n-1,m-1,s1,dps);  //ע�������ȵݹ�������������Ϊ�����Զ�����
        cout <<s1[n];
    }
    else if(dps[n][m]==2)
        LCS(n-1,m,s1,dps);
    else
        LCS(n,m-1,s1,dps);
}


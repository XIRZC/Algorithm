//最长公共子序列问题-动态规划解决
#include<iostream>
#include<cstring>

using namespace std;

const int N=1005;  //两字符串的最长长度
char s1[N],s2[N];  //两源字符串数组
int dp[N][N];  //动态规划最优值数组
int dps[N][N];  //最优解保存信息数组

int LCSLength(char s1[],char s2[],int n,int m,int dp[][N],int dps[][N]);  //计算最优值并保存最优解信息
void LCS(int n,int m,char s1[],int dps[][N]);  //求得最优解并输出
int main(void)
{
    int n,m;
    cin >>s1 >>s2;  //注意这里读取是从0开始读的，因此以下下标均从0开始计数
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
    if(n==-1||m==-1)  return;  //下标从0开始，也就从-1递归结束
    if(dps[n][m]==1)
    {
        LCS(n-1,m-1,s1,dps);  //注意这里先递归调用在输出，因为这是自顶向下
        cout <<s1[n];
    }
    else if(dps[n][m]==2)
        LCS(n-1,m,s1,dps);
    else
        LCS(n,m-1,s1,dps);
}


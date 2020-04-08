//单调递增最长子序列-动态规划算法
#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=10005;  //序列的最长长度
int mat[N];  //源数据数组
int dp[N];   //动态规划存值数组，将该问题转换为了前i个元素中的单调递增最长子序列且需包含第i个元素

int main(void)
{
    int n;  //数据个数
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


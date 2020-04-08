// 矩阵取数游戏-从一个矩阵的左上角只能往下走或往右走，使经过格子积分和最大
//动态规划算法
#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=510;
int a[N][N];  //存放原数据矩阵
int dp[N][N];  //动态规划最优值矩阵，问题转换为从左上角走到行为i列为j的格子的最大积分和
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


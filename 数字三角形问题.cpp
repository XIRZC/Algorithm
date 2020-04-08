//数字三角形问题，动态规划解决
#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=105; //最大行数
int mat[N][N],dp[N][N];  //原数据矩阵和动态规划矩阵，表示以第i行第j列的元素为顶的三角形的最大斜向和
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


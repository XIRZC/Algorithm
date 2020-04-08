//最大子矩阵和问题，求出最优解及其对应结果
#include<iostream>
#include<climits>
#include<cstring>
#define N 105   //矩阵得最大行数和列数s

using namespace std;

int R1,R2,C1,C2,CT1,CT2;  //分给为起始行，终止行，起始列，终止列，起始列和终止列的temp
int mat[N][N],dp[N];  //mat为计算矩阵,dp为多行压缩矩阵为一维向量用来进行最大子段和求解
int max_sum(int a[],int n);
int main(void)
{
    int row,col,max=INT_MIN,sum;  //row,col分别为矩阵行数和列数,max为结果
    cin >>row >>col;
    for(int i=1;i<=row;i++)  //读取矩阵
    {
        for(int j=1;j<=col;j++)
            cin >>mat[i][j];
    }
    //最大子矩阵和动态规划求解开始
    for(int i1=1;i1<=row;i1++)  //起始行下标
    {
        memset(dp,0,sizeof(dp));  //压缩矩阵赋初值
        for(int i2=i1;i2<=row;i2++)  //终止行下标
        {
            for(int j=1;j<=col;j++)
            {
                dp[j]+=mat[i2][j];
            }
            sum=max_sum(dp,col);
            if(sum>max)
            {
                max=sum;
                R1=i1;
                R2=i2;
                C1=CT1;
                C2=CT2;
            }
        }
    }
    max=max>0?max:0;
    cout <<max <<endl;
    cout <<R1 <<" " <<R2 <<" " <<C1 <<" " <<C2;
    return 0;
}
int max_sum(int a[],int n)
{
    int b[n+1],max;
    int c1=1,c2=1;
    memset(b,0,sizeof(b));
    max=b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(b[i-1]>0)
        {
            b[i]=b[i-1]+a[i];
            c2=i;
        }
        else
        {
            b[i]=a[i];
            c1=c2=i;
        }
        if(max<b[i])
        {
            max=b[i];
            CT1=c1;
            CT2=c2;
        }
    }
    return max>0?max:0;
}


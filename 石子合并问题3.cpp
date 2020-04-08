// 石子合并问题-环形相邻合并-动态规划算法
// 使用两个原数组连接起来的方式来模拟环形，注意转换为了长度为l而不是区间i到j 
#include<iostream>
#include<cstring>
#include<climits>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

using namespace std;

const int N=1010;  //石子的最多堆数
int a[N];   //存石子堆数据的源数组
int dpmax[2*N][N];   //动态规划最优值数组-问题转换为从第i堆开始顺时针合并长度为j的最多积分
int dpmin[2*N][N];  //动态规划最优值数组-问题转换为从第i堆开始顺时针合并长度为j的最少积分
int merge[2*N][2*N];   //用于两合并堆之间的合并，即为两堆的总石子数
//即为从第i堆到第j堆之间石子数总和
int main(void)
{
    int n;
    cin >>n;
    for(int i=1;i<=2*n;i++)
    {
        if(i<=n)
            cin >>a[i];
        else
            a[i]=a[i-n];
    }
    memset(dpmax,0,sizeof(dpmax));
    memset(dpmin,0,sizeof(dpmin));
    memset(merge,0,sizeof(merge));
    for(int i=1;i<=2*n;i++)
    {
        for(int j=i;j<=2*n;j++)
        {
            if(i==j)
                merge[i][j]=a[i];
            else if(i>n)
                merge[i][j]=merge[i][j-1]+a[j];
            else
                merge[i][j]=merge[i][j-1]+a[j];
        }
    }
    for(int l=2;l<=n;l++)  //长度
    {
        for(int i=1;i<=2*n-l+1;i++)  //起点
        {
            dpmax[i][l]=INT_MIN;
            dpmin[i][l]=INT_MAX;
            for(int k=1;k<l;k++)  //长度分割位置，子问题分解
            {
                dpmin[i][l]=min(dpmin[i][l],dpmin[i][k]+dpmin[i+k][l-k]+merge[i][i+l-1]);
                dpmax[i][l]=max(dpmax[i][l],dpmax[i][k]+dpmax[i+k][l-k]+merge[i][i+l-1]);
            }
        }
    }
      //merge数组输出
    for(int i=1;i<=2*n;i++)
    {
        for(int j=1;j<=2*n;j++)
            cout <<merge[i][j] <<" ";
        cout <<endl;
    }
    cout <<"-------------------" <<endl;
    //  dpmin数组输出   注意长度为l的也就是列为l的元素只有前2*n-l+1行有值，因为i为起点后还有长度l
    for(int i=1;i<=2*n;i++)
    {
        for(int j=1;j<=n;j++)
            cout <<dpmin[i][j] <<" ";
        cout <<endl;
    }
    cout <<"---------------" <<endl;
    //  dpmax数组输出
    for(int i=1;i<=2*n;i++)
    {
        for(int j=1;j<=n;j++)
            cout <<dpmax[i][j] <<" ";
        cout <<endl;
    }
    cout <<"----------------------" <<endl;

    int minv=INT_MAX,maxv=INT_MIN;
    for(int i=1;i<=n+1;i++)  //n+1即为第n列只有前2*n-n+1有值，其他行均为0，影响比较，所以要从n+1开始
    {
        minv=min(minv,dpmin[i][n]);
        maxv=max(maxv,dpmax[i][n]);
    }
    cout <<minv <<endl <<maxv;
    return 0;
}


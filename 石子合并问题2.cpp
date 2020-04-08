//石子合并问题-直线相邻合并-动态规划 

#include<iostream>
#include<cstring>
#include<climits>
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=110;
int a[N];
int dpmin[N][N];  //动态规划存值数组，定义为第i堆第j堆的最小合并得分
int dpmax[N][N];   //定义为第i堆第j堆的最大合并得分
int merge[N][N];  //用来合并两个子问题间的即两个合并堆之间的合并数组
//数值为从第i堆到第j堆的石子数和
int main(void)
{
    int n;
    cin >>n;
    for(int i=1;i<=n;i++)
        cin >>a[i];
    memset(dpmin,0,sizeof(dpmin));
    memset(dpmax,0,sizeof(dpmax));
    memset(merge,0,sizeof(merge));
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            dpmin[i][j]=INT_MAX;
            dpmax[i][j]=INT_MIN;
            for(int k=i;k<=j;k++)
                merge[i][j]+=a[k];
            for(int k=i;k<=j-1;k++)
            {
                dpmin[i][j]=min(dpmin[i][j],dpmin[i][k]+dpmin[k+1][j]+merge[i][j]);
                dpmax[i][j]=max(dpmax[i][j],dpmax[i][k]+dpmax[k+1][j]+merge[i][j]);
            }
        }
    }
    cout <<dpmin[1][n] <<endl <<dpmax[1][n];
    return 0;
}


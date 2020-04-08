//  01背包问题
//关键在于问题转换，将问题转换为容量为j的背包装前i件物品的最大价值
//转换为这个问题之后，即可使其具备最有子结构和重复子问题的性质
//从而使用动态规划算法去解决
#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=1000;  //背包容量的最大值

int w[N+1]={0,15,10,12,8},v[N+1]={0,12,8,9,5};  //各物品的重量和价值数组
int m[N+1][N+1];  //转换问题之后结果存储数组
int item[N+1];  //选择的物品
void traceback(int n,int c);   //从m[n][c]不断回溯找到选择的物品
int main(void)
{
    int n=4,c=30;  //物品个数和背包容量
    memset(m,0,sizeof(m));
    cin >> n >> c;
    //依次输入各个物品的重量和价值信息
    for(int i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(w[i]<=j)
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
            else
                m[i][j]=m[i-1][j];
        }
    }
    traceback(n,c);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
            cout << m[i][j] <<" ";
        cout << endl;
    }
    for(int i=1;i<=n;i++)
        if(item[i]==1)
            cout << i << " ";
    return 0;
}
void traceback(int n,int c)
{
    memset(item,0,sizeof(item));
    for(int i=n;i>1;i--)
    {
        if(m[i][c]==m[i-1][c])
            item[i]=0;
        else
        {
            item[i]=1;
            c-=w[i];
        }
    }
    item[1]=m[1][c]>0?1:0;
}



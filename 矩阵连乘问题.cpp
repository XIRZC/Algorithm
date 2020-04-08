// 矩阵连乘问题-矩阵的相乘次序使得乘次数最少
#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

const int N=10;  //矩阵的最大个数
int p[N+1];   //从0开始到n 代表每个矩阵的行数和列数，共有n+1个
int m[N][N];   //问题转换为次序从i到j的矩阵的连乘最小次数
int s[N][N];   //存储每次划分的位置
int n;  //矩阵个数

void matrix_chain(void);
void trace_back(int i,int j);
int main(void)
{
    cin >> n;
    for(int i=0;i<=n;i++)
    {
        cin >> p[i];
    }
    matrix_chain();
    trace_back(1,n);
    return 0;
}
void matrix_chain(void)
{
    memset(m,0,sizeof(m));
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;   //将其设置为最大值，以便后续不断比较得最小值
            for(int k=i;k<j;k++)
            {
                int temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(m[i][j]>temp)
                {
                    m[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }
    cout << m[1][n];
}
void trace_back(int i,int j)
{
    if(i==j)
    {
        cout << "M" << i;
        return;
    }
    cout << "(";
    trace_back(i,s[i][j]);
    cout << ",";
    trace_back(s[i][j]+1,j);
    cout << ")";
}


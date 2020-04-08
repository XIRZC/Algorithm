// ������������-�������˴���ʹ�ó˴�������
#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

const int N=10;  //�����������
int p[N+1];   //��0��ʼ��n ����ÿ�����������������������n+1��
int m[N][N];   //����ת��Ϊ�����i��j�ľ����������С����
int s[N][N];   //�洢ÿ�λ��ֵ�λ��
int n;  //�������

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
            m[i][j]=INT_MAX;   //��������Ϊ���ֵ���Ա�������ϱȽϵ���Сֵ
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


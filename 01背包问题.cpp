//  01��������
//�ؼ���������ת����������ת��Ϊ����Ϊj�ı���װǰi����Ʒ������ֵ
//ת��Ϊ�������֮�󣬼���ʹ��߱������ӽṹ���ظ������������
//�Ӷ�ʹ�ö�̬�滮�㷨ȥ���
#include<iostream>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

const int N=1000;  //�������������ֵ

int w[N+1]={0,15,10,12,8},v[N+1]={0,12,8,9,5};  //����Ʒ�������ͼ�ֵ����
int m[N+1][N+1];  //ת������֮�����洢����
int item[N+1];  //ѡ�����Ʒ
void traceback(int n,int c);   //��m[n][c]���ϻ����ҵ�ѡ�����Ʒ
int main(void)
{
    int n=4,c=30;  //��Ʒ�����ͱ�������
    memset(m,0,sizeof(m));
    cin >> n >> c;
    //�������������Ʒ�������ͼ�ֵ��Ϣ
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


